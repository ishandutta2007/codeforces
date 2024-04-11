#include <bits/stdc++.h>
#define ll long long
#define maxn 400005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int n;
int p[maxn];
int fl[maxn]; 
vi nr;
int main() {
	ll k, d, t;
	cin >> k >> d >> t;
	ll m = k % d;
	if (m) m = d - m;
	ll ts = (t * 2) / (2 * k + m);
	ll us = 2 * t - (2 * k + m) * ts;
	ll ans = ts * (k + m);
	if (us <= 2 * k)
		printf("%.10lf\n", (ans) + (1.0 * us / 2));
	else
		printf("%lld\n", ans + k + (us - 2 * k));
	return 0;
}