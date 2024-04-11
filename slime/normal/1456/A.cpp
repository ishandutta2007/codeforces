//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
#define mod 998244353
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
int n;
int fl[maxn];
int cnt[maxn];
char inp[maxn];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, p, k;
		scanf("%d%d%d", &n, &p, &k);
		scanf("%s", inp + 1);
		for (int i = 1; i <= n; i++)
			fl[i] = inp[i] - '0';
		for (int i = n; i >= 1; i--) {
			cnt[i] = 1 - fl[i];
			if (i + k <= n) cnt[i] += cnt[i + k];
		}
		int x, y;
		scanf("%d%d", &x, &y);
		ll ans = 1e18;
		for (int i = p; i <= n; i++)
			chkmin(ans, 1ll * cnt[i] * x + 1ll * (i - p) * y);
		cout << ans << endl;
	}
	return 0;
}