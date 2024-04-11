//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
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
int cnt[22];
int a[maxn];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		for (int j = 0; j < 20; j++)
			if (a[i] & (1 << j)) cnt[j]++;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int nr = 0;
		for (int j = 0; j < 20; j++)
			if (cnt[j]) {
				nr += (1 << j);
				cnt[j]--;
			}
		ans += 1ll * nr * nr;
	}
	cout << ans << endl;
	return 0;
}