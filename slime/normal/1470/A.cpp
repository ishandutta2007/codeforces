#include <bits/stdc++.h>
#define ll long long
#define maxn 400005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int fa[maxn], sz[maxn];
int gfa(int a) {
	if (fa[a] == a) return a;
	return fa[a] = gfa(fa[a]);
}
int n, m;
int k[maxn];
int c[maxn];
int sum[maxn];
bool chk(int r) {
	for (int i = 1; i <= m; i++)
		sum[i] = 0;
	for (int p = r + 1; p <= n; p++)
		sum[k[p]]++;
	for (int p = 1; p <= m; p++) {
		sum[p] += sum[p - 1];
		if (sum[p] > p) return 0;
	}
	return 1;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			scanf("%d", &k[i]);
		for (int i = 1; i <= m; i++)
			scanf("%d", &c[i]);
		sort(k + 1, k + n + 1);
		int l = 0, r = n;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (chk(mid)) r = mid;
			else l = mid + 1;
		}
		ll ans = 0;
		int pl = l;
		for (int i = 1; i <= n - l; i++)
			ans += c[i];
		for (int i = 1; i <= l; i++)
			ans += c[k[i]];
		while (pl <= n && c[k[pl + 1]] < c[n - pl])
			ans += c[k[pl + 1]], 
			ans -= c[n - pl], 
			pl++;
		cout << ans << endl;
	}
	return 0;
}