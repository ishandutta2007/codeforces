#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <unordered_map>
#include <cstring>

using namespace std;

struct MaxFlow {
	vector<vector<pair<int, int>>> adjl;
	vector<bool> isOpen;
	vector<int> par, pathEdge;
	int n, s, t;
	void addEdge(int u, int v) {
		// printf("ADDE %d %d\n", u, v);
		adjl[u].emplace_back(v, isOpen.size());
		isOpen.push_back(true);
		adjl[v].emplace_back(u, isOpen.size());
		isOpen.push_back(false);
	}
	bool updateDistInfo() {
		fill(par.begin(), par.end(), -1);
		par[s] = -2;
		queue<int> q; q.push(s);
		while (not q.empty()) {
			int c = q.front(); q.pop();
			for (auto x_id : adjl[c]) {
				if (isOpen[x_id.second] and par[x_id.first] == -1) {
					par[x_id.first] = c;
					pathEdge[x_id.first] = x_id.second;
					q.push(x_id.first);
				}
			}
		}
		return (par[t] != -1);
	}
	int getMaxFlow() {
		int ans = 0;
		while (updateDistInfo()) {
			for (int v = t; par[v] != -2; v = par[v]) isOpen[pathEdge[v]] = false, isOpen[pathEdge[v]^1] = true;
			++ans;
		}
		return ans;
	}
	void getFlowEdges(vector<pair<int, int>> &ans) {
		for (int i = 0; i < n; ++i) {
			for (auto j_id : adjl[i]) {
				if (i < j_id.first and !isOpen[j_id.second]) ans.emplace_back(i, j_id.first);
			}
		}
	}
	MaxFlow(int n, int s, int t) : n(n), s(s), t(t) {
		adjl = vector<vector<pair<int, int>>>(n);
		pathEdge = par = vector<int>(n);
	}
};

char word[20];

char toForm[5] = "````";

int compWord(char *tf) {
	if (*tf) {
		return (*tf - '`') + 27 * compWord(tf + 1);
	} else return 0;
}

void decompWord(int comp, char *toAns) {
	if (comp > 0) {
		*toAns = (comp % 27) + '`';
		decompWord(comp/27, toAns + 1);
	}
}

void findSubseqs(char* str, int maxLen, vector<int> &ans) {
	if ((!(*str) or maxLen == 0)) {
		if (compWord(toForm) > 0) ans.push_back(compWord(toForm));
	} else {
		findSubseqs(str + 1, maxLen, ans);
		toForm[4-maxLen] = *str;
		findSubseqs(str + 1, maxLen - 1, ans);
		toForm[4-maxLen] = '`';
	}
}

int main() {
	FILE* pin = fopen("input.txt", "r");
	FILE* pout = fopen("output.txt", "w");
	// printf("%p %p\n", (void*)pin, (void*)pout);

	// if the thing shows 
	int n; fscanf(pin, "%d", &n); 

	vector<vector<int>> possibleSV(n);
	unordered_map<int, int> varCompID;
	vector<int> compVars;
	int curVCID = 0;
	for (int i = 0; i < n; ++i) {
		fscanf(pin, "%s", word);
		findSubseqs(word, 4, possibleSV[i]);
		for (int cs : possibleSV[i]) {
			// printf("WORD COMP %d\n", cs);
			if (varCompID.count(cs) == 0) {varCompID[cs] = compVars.size(); compVars.push_back(cs);}
		}
	}
	curVCID = compVars.size();
	// printf("HERE\n");
	int SOURCE = 0, SINK = n + curVCID + 1;
	// printf("SOURCE = %d SINK = %d\n", SOURCE, SINK);
	MaxFlow hopk(SINK + 1, SOURCE, SINK);
	for (int i = 0; i < n; ++i) {
		hopk.addEdge(SOURCE, i + 1);
	}
		// printf("HERE\n");
	for (int i = 0; i < curVCID; ++i) {
		hopk.addEdge(n + 1 + i, SINK);
	}
		// printf("HERE\n");
	for (int i = 0; i < n; ++i) {
		for (int cs : possibleSV[i]) {
			hopk.addEdge(i + 1, n + 1 + varCompID[cs]);
		}
	}
	// printf("HERE\n");
	if (hopk.getMaxFlow() < n) fprintf(pout, "-1\n");
	else {
		// printf("YES\n");
		vector<pair<int, int>> fe; hopk.getFlowEdges(fe);
		vector<int> wordUsed(n);
		for (auto u_v : fe) {
			if (u_v.first == SOURCE or u_v.second == SINK) continue;
			wordUsed[u_v.first - 1] = compVars[u_v.second - n - 1];
		}
		char toPrint[5];
		for (int i = 0; i < n; ++i) {
			memset(toPrint, 0, sizeof(toPrint));
			decompWord(wordUsed[i], toPrint);
			fprintf(pout, "%s\n", toPrint);
		}
	}
	fclose(pin);
	fclose(pout);
	return 0;
}