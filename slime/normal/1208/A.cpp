#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
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

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		c %= 3;
		if (c == 0) cout << a << endl;
		else if (c == 1) cout << b << endl;
		else cout << (a ^ b) << endl;
	}
	return 0;
}