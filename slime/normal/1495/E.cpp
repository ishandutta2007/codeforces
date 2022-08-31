//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 5000005 /*rem*/
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}

ll seed = 0;
ll base = 0;

ll rnd() {
	ll ret = seed;
	seed = (seed * base + 233) % mod;
	return ret;
}
int t[maxn], a[maxn];
const int M = 200005;
int b[M], w[M], p[M], k[M];
ll e[maxn];
ll ans[maxn];
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) scanf("%d%d%d%d", &p[i], &k[i], &b[i], &w[i]);
	p[0] = 0;
	for (int i = 1; i <= m; i++) {
		seed = b[i],
		base = w[i];
		for (int j = p[i - 1] + 1; j <= p[i]; j++) {
			t[j] = (rnd() % 2) + 1;
			a[j] = (rnd() % k[i]) + 1;
		}
	}
	ll ss[3] = {0, 0, 0};
	for (int i = 1; i <= n; i++) 
		ss[t[i]] += a[i];
	int ls = 0;
	if (ss[1] == ss[2]) ls = 3 - t[1];
	else if (ss[1] < ss[2]) ls = 2;
	else ls = 1;
	
	ll ns = 0;
	for (int i = n; i >= 1; i--) {
		if (t[i] == 3 - ls) ns += a[i];
		else ns -= a[i];
		e[i] = ns;
	}
	for (int i = n; i >= 1; i--)
		chkmax(e[i], e[i + 1]); 
	
	ll mns = 0, s = 0;
	for (int i = 1; i <= n; i++) {
		if (t[i] == 3 - ls) s += a[i], ans[i] = a[i];
		else {
			s -= a[i];
			ans[i] = s - mns + a[i];//max(ans[i], s - mns + a[i]);
			ans[i] = max(ans[i], s + e[i + 1] + a[i]);
		}
	//	cout << i << ' ' << s << ' ' << endl;
		chkmin(mns, s);
	}
	if (ls == t[1]) {
		for (int i = 1; i <= n; i++) 
			if (ans[i] < a[i]) {
				ans[i]++;
				break;
			}
	}
	ll res = 1;
	ll q = 0;
	for (int i = 1; i <= n; i++) {
		if (ans[i] > a[i]) ans[i] = a[i];
		if (ans[i] < a[i]) q += ans[i] - a[i];
		assert(ans[i] >= 0);
//		cout << i << ' ' << ans[i] << ' ' << t[i] << ' ' << a[i] << ' ' << ls << endl;
		ll cr = ans[i] ^ (1ll * i * i);
		cr += 1;
		cr %= mod;
		res = res * cr % mod;
	}
	
	cout << res << endl;
	return 0;
}