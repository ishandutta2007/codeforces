#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
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
ll x, y;
vector<ll> cur;
ll gcd(ll a, ll b) {
	if (!b) return a;
	return gcd(b, a % b);
}
ll work(ll x, ll y) {
	if (y == 0) return 0;
	ll g = gcd(x, y);
	x /= g, y /= g;
	ll mn = y;
	for (auto v : cur)
		if (x % v == 0) mn = min(mn, y % v);
	return mn + work(x, y - mn);
}
int main() {
	cin >> x >> y;
	for (int i = 1; 1ll * i * i <= x; i++)
		if (x % i == 0) {
			if (i != 1) cur.pb(i);
			if (x / i != 1) cur.pb(x / i);
		}
	cout << work(x, y) << endl;
	return 0;
}