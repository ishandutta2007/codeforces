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
int x[maxn];
int pr[maxn];
int main() {
	int n;
	cin >> n;
	int ans = 0;
	if (n >= 300) ans = 1;
	else {
		for (int i = 1; i <= n; i++)
			scanf("%d", &x[i]), 
			pr[i] = x[i] ^ pr[i - 1];
		ans = 1e9;
		for (int pl = 2; pl <= n; pl++) 
			for (int l = 1; l < pl; l++)
				for (int r = pl; r <= n; r++) {
					int lsum = pr[pl - 1] ^ pr[l - 1], rsum = pr[r] ^ pr[pl - 1];
					if (lsum > rsum)
						chkmin(ans, r - l - 1);
				}
		if (ans > n) ans = -1;
	}
	cout << ans << endl;
	return 0;
}