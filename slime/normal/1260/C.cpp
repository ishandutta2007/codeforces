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
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
} 
int main() {
	int t;
	cin >> t;
	while (t--) {
		int x, y, k;
		scanf("%d%d%d", &x, &y, &k);
		if (x > y) swap(x, y);
		int g = gcd(x, y);
		x /= g, y /= g;
		int fl = 1;
		if (k == 1) fl = 0;
		else {
			if (1ll * x * (k - 1) + 1 < y) fl = 0;
		}
		if (!fl) puts("REBEL");
		else puts("OBEY");
	} 
	return 0;
}