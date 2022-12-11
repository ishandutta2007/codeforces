#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <cctype>
#include <unordered_map>
#define INF 1000000000

using namespace std;
typedef long long ll;

string toLower(string s) {
	for (int i = 0; i < s.size(); ++i) {
		s[i] = tolower(s[i]);
	}
	return s;
}

int rCount(string s) {
	int ans = 0;
	for (char c : s) {
		ans += (c == 'r');
	}
	return ans;
}

vector<vector<int>> graph;
vector<int> sccID;
vector<int> low;
vector<int> disc;
vector<bool> inSCCStack;
int csccID = 0;
vector<int> sccToposort;
vector<vector<int>> sccDAG;
int t = 0;
stack<int> sccStack;

void takeSCC(int h) {
	while (sccStack.top() != h) {
		int toAdd = sccStack.top(); sccStack.pop();
		inSCCStack[toAdd] = false;
		sccID[toAdd] = csccID;
	}
	inSCCStack[h] = false;
	sccID[h] = csccID++;
	sccStack.pop();
}

void getSCCs(int i, int p) {
	low[i] = disc[i] = t++;
	sccStack.push(i);
	inSCCStack[i] = true;
	for (int next : graph[i]) {
		if (disc[next] == -1) {
			getSCCs(next, i);
			low[i] = min(low[i], low[next]);
		} else if (inSCCStack[next]) {
			low[i] = min(low[i], disc[next]);
		}
	}
	if (low[i] == disc[i]) {
		sccToposort.push_back(csccID);
		takeSCC(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m; cin >> m;
	vector<string> essay(m, "");
	for (int i = 0; i < m; ++i) {
		cin >> essay[i];
		essay[i] = toLower(essay[i]);
	}
	int n; cin >> n;
	vector<pair<string, string>> pairs(n, make_pair("", ""));
	for (int i = 0; i < n; ++i) {
		cin >> pairs[i].first >> pairs[i].second;
		pairs[i].first = toLower(pairs[i].first);
		pairs[i].second = toLower(pairs[i].second);
	}
	unordered_map<string, int> stringcomp;
	vector<string> compToStr;
	for (int i = 0; i < m; ++i) {
		if (stringcomp.count(essay[i]) == 0) {
			stringcomp[essay[i]] = compToStr.size();
			compToStr.push_back(essay[i]);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (stringcomp.count(pairs[i].first) == 0) {
			stringcomp[pairs[i].first] = compToStr.size();
			compToStr.push_back(pairs[i].first);
		}
		if (stringcomp.count(pairs[i].second) == 0) {
			stringcomp[pairs[i].second] = compToStr.size();
			compToStr.push_back(pairs[i].second);
		}
	}
	int gn = compToStr.size();
	graph = vector<vector<int>>(gn, vector<int>());
	for (auto st1_st2 : pairs) {
		graph[stringcomp[st1_st2.first]].push_back(stringcomp[st1_st2.second]);
	}
	sccID = low = disc = vector<int>(gn, -1);
	inSCCStack = vector<bool>(gn, false);
	for (int i = 0; i < gn; ++i) {
		if (disc[i] == -1) {
			getSCCs(i, -1);
		}
	}
	int sccn = csccID;
	sccDAG = vector<vector<int>>(sccn, vector<int>());
	//cout << "finished computing SCCs" << endl;
	for (auto st1_st2 : pairs) {
		//cout << "placing " << st1_st2.first << " " << st1_st2.second << endl;
		//cout << "compressing to " << stringcomp[st1_st2.first] << " " << stringcomp[st1_st2.second] << endl;
		//cout << "in SCCs " << endl;
		sccDAG[sccID[stringcomp[st1_st2.first]]].push_back(sccID[stringcomp[st1_st2.second]]);
	}
	//cout << "done with dag of SCCs" << endl;
	vector<pair<int, int>> bestPick(sccn, {INF, INF});
	for (int i = 0; i < gn; ++i) {
		bestPick[sccID[i]] = min(bestPick[sccID[i]], {rCount(compToStr[i]), compToStr[i].size()});
		//cout << "string " << compToStr[i] << " in scc " << sccID[i] << endl;
		//cout << "cur bp of that is " << bestPick[sccID[i]].first << " " << bestPick[sccID[i]].second << endl;
	}
	vector<pair<int, int>> bestReachable(bestPick);
	for (int i : sccToposort) {
		for (int next : sccDAG[i]) {
			bestReachable[i] = min(bestReachable[i], bestReachable[next]);
		}
	}
	ll theActualRCount = 0;
	ll theActualLen = 0;
	for (string word : essay) {
		theActualRCount += bestReachable[sccID[stringcomp[word]]].first;
		theActualLen += bestReachable[sccID[stringcomp[word]]].second;
	}
	cout << theActualRCount << " " << theActualLen << endl;
	return 0;
}