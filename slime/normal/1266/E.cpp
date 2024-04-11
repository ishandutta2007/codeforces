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
int a[maxn], b[maxn];
ll S;
map<pi, int> r;
void upd(int x, int tp) {
	S += min(b[x], a[x]);
	b[x] += tp;
	S -= min(b[x], a[x]);
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), S += a[i];
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int s, t, u;
		scanf("%d%d%d", &s, &t, &u);
		if (r[mp(s, t)]) 
			upd(r[mp(s, t)], -1);
		r[mp(s, t)] = u, 
		upd(u, 1);
		printf("%lld\n", S);
	}
	return 0;
}