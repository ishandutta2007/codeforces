#include <bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
int n, m;
ll s[maxn];
int r[maxn], f[maxn];
ll pls;
int st[maxn];
int main() {
	int n, m;
	cin >> n >> m;
	r[0] = f[0] = -2e9;
	for (int i = 1; i <= n; i++) {
		int l;
		scanf("%d", &l);
		int mpl = 0;
		for (int j = 1; j <= l; j++) {
			scanf("%d", &r[j]);
			if (r[j] > r[mpl]) mpl = j;
		}
		if (l * 2 <= m) {
			int nr = r[mpl];
			if (nr >= 0) {
				pls += r[mpl];
				for (int j = 1; j <= mpl - 1; j++) {
					f[j] = max(f[j - 1], r[j]);
					int ch = f[j];
					ch = max(ch, 0);
					s[j] += ch - nr;
				}
				for (int j = l; j >= mpl + 1; j--) {
					if (j == l) f[j] = r[j];
					else f[j] = max(f[j + 1], r[j]);
					int ch = f[j];
					int nid = j + m - l;
					ch = max(ch, 0);
					s[nid] += ch - nr;
				}
			}
		}
		else {
			int mx = 0;
			int fr = 0, ed = 0;
			for (int j = 1; j <= m; j++) {
				if (j <= l) {
					while (fr < ed && r[st[ed - 1]] <= r[j]) ed--;
					st[ed++] = j;
				}
				while (fr < ed && st[fr] < j - (m - l)) fr++;
				int mu = r[st[fr]];
				if (j > l || j <= m - l) mu = max(mu, 0);
				s[j] += mu;
			}
		}
	}
	for (int j = 1; j <= m; j++)
		printf("%lld ", s[j] + pls);
	return 0;
}
/*
1 3
2 -3 -7
*/