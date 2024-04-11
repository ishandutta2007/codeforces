//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
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
int x[2], y[2];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 2; i++)
		cin >> x[i] >> y[i];
	ll cur = 1ll * x[0] * y[1] - 1ll * y[0] * x[1];
	if (abs(cur) != n) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	int gc = __gcd(abs(y[0]), abs(y[1]));
	for (int i = 0; i < n / gc; i++)
		for (int j = 0; j < gc; j++)
			printf("%d %d\n", i, j);
	return 0;
}