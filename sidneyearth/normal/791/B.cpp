#include<bits/stdc++.h>
using namespace std;
const int maxn = 150100;
int f[maxn], d[maxn], s[maxn];
int find(int u){ return u == f[u] ? u : f[u] = find(f[u]); }
int main(){
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		f[i] = i;
	for(int i = 0; i < m; i++){
		int u, v; scanf("%d%d", &u, &v);
		d[u]++; d[v]++;
		f[find(u)] = find(v);
	}
	for(int i = 1; i <= n; i++)
		s[find(i)]++;
	bool ans = true;
	for(int i = 1; i <= n; i++)
		if(d[i] != s[find(i)] - 1)
			ans = false;
	printf("%s\n", ans ? "YES" : "NO");
	return 0;
}