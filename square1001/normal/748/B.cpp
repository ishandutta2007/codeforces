#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
string s, t; vector<int> G[26];
int main() {
	cin >> s >> t;
	for (int i = 0; i < s.size(); i++) {
		G[s[i] - 97].push_back(t[i] - 97);
		G[t[i] - 97].push_back(s[i] - 97);
	}
	for (int i = 0; i < 26; i++) {
		sort(G[i].begin(), G[i].end());
		G[i].erase(unique(G[i].begin(), G[i].end()), G[i].end());
	}
	bool flag = true;
	for (int i = 0; i < 26; i++) {
		if (G[i].size() >= 2) flag = false;
		if (G[i].size() && G[G[i][0]].size() && G[G[i][0]][0] != i) flag = false;
	}
	if (!flag) puts("-1");
	else {
		vector<string> ret;
		for (int i = 0; i < 26; i++) {
			if (G[i].size() && (!G[G[i][0]].size() || i < G[i][0]) && i != G[i][0]) ret.push_back(string(1, i + 97) + " " + string(1, G[i][0] + 97));
		}
		cout << ret.size() << endl;
		for (string i : ret) cout << i << endl;
	}
	return 0;
}