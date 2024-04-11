#include <bits/stdc++.h>
#define ll long long
#define maxn 20 /*rem*/
#define mod 998244353 
#define db double
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
map<ll, pi> pl;
int k, s[maxn], q[maxn];
const int N = 75005;
pi nx[N];
int a[16][5005];
int d[N];
int dp[1 << 16], ur[1 << 16], fl[N];
int mv[1 << 16];
int res[16], to[16];
int main() {
	cin >> k;
	ll S = 0;
	for (int i = 1; i <= k; i++) {
		cin >> s[i];
		for (int j = 1; j <= s[i]; j++)
			scanf("%d", &a[i][j]), 
			pl[a[i][j]] = mp(i, j), S += a[i][j];
	}
	if (S % k) cout << "No" << endl;
	else {
		S /= k;
		for (int i = 1; i <= k; i++) {
			q[i] = s[i] + q[i - 1];
			ll r = 0;
			for (int j = 1; j <= s[i]; j++)
				r += a[i][j];
			for (int j = 1; j <= s[i]; j++) {
				ll cr = S - (r - a[i][j]);
				nx[q[i - 1] + j] = pl[cr];
			}
		}
		int n = q[k];
		for (int i = 1; i <= n; i++) {
			pi uu = nx[i];
			if (!uu.fi) continue;
			d[q[uu.fi - 1] + uu.se]++;
		}
		queue<int> cur;
		for (int i = 1; i <= n; i++)
			if (!d[i]) cur.push(i);
		while (!cur.empty()) {
			int x = cur.front();
			fl[x] = 1;
			cur.pop();
			pi uu = nx[x];
			if (!uu.fi) continue;
			int v = q[uu.fi - 1] + uu.se;
			d[v]--;
			if (!d[v]) cur.push(v);
		}
		for (int i = 1; i <= n; i++) {
			if (fl[i]) continue;
			else {
				int pl = i;
				int x = 0, f = 0;
				while (1) {
					fl[pl] = 1;
					int cpl = lower_bound(q + 1, q + k + 1, pl) - q;
					if (x & (1 << (cpl - 1))) f = 1;
					x ^= (1 << (cpl - 1));
					pi uu = nx[pl];
					int v = q[uu.fi - 1] + uu.se;
					if (v == i) break;
					pl = v;
				} 
				if (f) continue;
				ur[x] = i;
			} 
		}
		dp[0] = 1;
		for (int i = 1; i < (1 << k); i++) {
			for (int j = i; 1; j = (j - 1) & i) {
				if (dp[j] && ur[i ^ j]) {
					dp[i] = 1;
					mv[i] = j;
					break;
				}
				if (j == 0) break;
			}
		}
		int nr = (1 << k) - 1;
		if (!dp[nr]) cout << "No" << endl;
		else {
			cout << "Yes" << endl;
			while (nr) {
				int cpl = ur[nr ^ mv[nr]];
				int npl = cpl;
				while (1) {
					pi uu = nx[npl];
					int epl = lower_bound(q + 1, q + k + 1, npl) - q;
					res[uu.fi] = a[uu.fi][uu.se], to[uu.fi] = epl;
					int v = q[nx[npl].fi - 1] + nx[npl].se;
					if (v == cpl) break;
					npl = v;
				}
				nr = mv[nr];
			} 
			for (int i = 1; i <= k; i++)
				cout << res[i] << ' ' << to[i] << endl;
		}
	}
	return 0;
}
/*
1 2
..
*/