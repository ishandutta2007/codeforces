#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> after;
int bef[27];
bool ok;
string ans;
bool proc[27];
bool tc[27];
string alph;

void rec(int u) {
	if (proc[u]) {
		ok = false;
		return;
	}
	tc[u] = true;
	if (proc[u]) return;
	proc[u] = true;
	ans += alph[u];
	if (after[u].size() == 0) return;
	sort(after[u].begin(), after[u].end());
	if (after[u][0] != after[u][after[u].size()-1]) {
		ok = false;
		return;
	}
	rec(after[u][0]);
}

int main() {
	alph = "abcdefghijklmnopqrstuvwxyz";
	int n;
	cin >> n;
	map<int, int> spottoalph;
	map<int, int> alphtospot;
	string cur;
	bool in[27];
	string lines[n];
	for (int i = 0; i <= 26; i++) {
		vector<int> b;
		after.push_back(b);
		proc[i] = false;
		in[i] = false;
		bef[i] = 0;
	}
	ok = true;
	for (int s = 0; s < n; s++) {
		cin >> cur;
		lines[s] = cur;
		bool seen[26];
		for (int i = 0; i < 26; i++) {
			seen[i] = false;
		}
		int prev = -1;
		for (int i = 0; i < cur.length(); i++) {
			int c = cur[i]-'a';
			if (seen[c]) ok = false;
			seen[c] = true;
			if (prev != -1) {
				after[prev].push_back(c);
				bef[c]++;
			}
			prev = c;
			in[c] = true;
		}
	}
	ans = "";
	for (int i = 0; i < 26; i++) {
		if (bef[i] == 0 && in[i]) {
			for (int j = 0; j < 26; j++) {
				tc[j] = false;
			}
			rec(i);
		}
	}
	for (int i = 0; i < 26; i++) {
		if (!proc[i] && in[i]) ok = false;
	}
	if (!ok) {
		cout << "NO" << endl;
	}
	else {
		cout << ans << endl;
	}
	// cin >> n;

}