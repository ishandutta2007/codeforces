#include <bits/stdc++.h>
#define ll long long
#define maxn 300005 /*rem*/
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
// from csdn
vi eg[maxn];
int dfn[maxn];
int col[maxn]; 
vi q;
void dfs(int a) {
	dfn[a] = q.size() + 1;
	q.pb(a);
	for (auto v : eg[a]) {
		if (dfn[v]) continue;
		dfs(v);
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			eg[i].clear(), dfn[i] = 0, col[i] = 0;
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			eg[u].pb(v), eg[v].pb(u);
		}
		q.clear();
		dfs(1);
		if (q.size() != n) 
			printf("NO\n");
		else {
			printf("YES\n");
			vi ed;
			for (auto x : q) {
				col[x] = 1;
				for (auto v : eg[x])
					if (col[v]) col[x] = 0;
				if (col[x])
					ed.pb(x);
			}
			printf("%d\n", ed.size());
			for (auto v : ed)
				printf("%d ", v);
			printf("\n");
		}
		
	}
	return 0;
}