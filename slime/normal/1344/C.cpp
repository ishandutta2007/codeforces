#include <bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
#define fi first
#define pi pair<int, int>
#define se second
#define mp make_pair
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
vi eg[maxn][2];
int tp[maxn][2];
void work(int a, int b) {
	tp[a][b] = 1;
	for (auto v : eg[a][b]) {
		if (tp[v][b]) continue;
		work(v, b);
	}
}
int d[maxn];
int q[maxn], fr = 0, ed = 0;
int re[maxn];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		d[y]++;
		eg[x][0].pb(y), eg[y][1].pb(x);
	}
	for (int i = 1; i <= n; i++) 
		if (d[i] == 0) q[ed++] = i;
	while (fr < ed) {
		int x = q[fr];
		fr++;
		for (auto v : eg[x][0]) {
			d[v]--;
			if (!d[v]) q[ed++] = v;
		}
	}
	if (ed != n) {
		cout << -1 << endl;
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!tp[i][0] && !tp[i][1]) ans++, re[i] = 1;
		if (!tp[i][0]) work(i, 0);
		if (!tp[i][1]) work(i, 1);
	}
	cout << ans << endl;
	for (int i = 1; i <= n; i++) {
		if (re[i]) printf("A");
		else printf("E");
	}
	printf("\n");
	return 0;
}