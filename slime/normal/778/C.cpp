#include <bits/stdc++.h>
#define ll long long
#define maxn 300005 /*rem*/
#define db double
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int ch[maxn][26];
int ans[maxn], sz[maxn];
int cal(vi s) {
	if (!s.size()) return 0;
	if (s.size() == 1) return sz[s[0]];
	int r = 1;
	for (int i = 0; i < 26; i++) {
		vi cur;
		for (auto v : s) 
			if (ch[v][i]) cur.pb(ch[v][i]);
		r += cal(cur);
		cur.clear();
		vi().swap(cur);
	}
	return r;
}
int dep[maxn];
void dfs(int a) {
	vi vs;
	sz[a] = 1;
	for (int i = 0; i < 26; i++) {
		int v = ch[a][i];
		if (v) {
			dep[v] = dep[a] + 1;
			dfs(v);
			vs.pb(v);
			sz[a] += sz[v];
		}
	}
	if (vs.size()) ans[dep[a] + 1] += sz[a] - cal(vs);
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		char x[4];
		scanf("%d%d", &u, &v);
		scanf("%s", x);
		ch[u][x[0] - 'a'] = v;
	}
	dfs(1);
	int mx = 0;
	for (int i = 1; i <= n; i++)
		if (ans[i] > ans[mx]) mx = i;
	cout << n - ans[mx] << endl << mx << endl;
	return 0;
}
/*
5 4
0 1 2 3

*/