#include <bits/stdc++.h>
#define ll long long
#define maxn 1005 /*rem*/
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
ll s[maxn];
vector<pair<ll, int> >res[2];
ll ask(int tp, int a, int b, int c) {
	cout << tp << ' ' << a << ' ' << b << ' ' << c << endl;
	fflush(stdout);
	ll ans;
	cin >> ans;
	return ans;
}
int main() {
	int n;
	cin >> n;
	int pl = 2;
	for (int i = 3; i <= n; i++) 
		if (ask(2, 1, pl, i) == 1) pl = i;
	int mxs = 0;
	for (int i = 2; i <= n; i++) {
		if (i == pl) s[i] = 0;
		else s[i] = ask(1, 1, pl, i);
		if (s[i] > s[mxs]) mxs = i;
	}
	for (int j = 2; j <= n; j++)
		if (j == mxs) continue;
		else {
			if (ask(2, 1, mxs, j) == 1) res[1].pb(mp(s[j], j));
			else res[0].pb(mp(s[j], j));
		}
	sort(res[0].begin(), res[0].end());
	sort(res[1].begin(), res[1].end());
	cout << 0 << ' ' << 1 << ' ';
	for (auto v : res[0])
		cout << v.se << ' ';
	cout << mxs << ' ';
	if (res[1].size())
		for (int j = res[1].size() - 1; j >= 0; j--)
			cout << res[1][j].se << ' ';
	cout << endl;
	fflush(stdout);
	return 0;
}
/*
1 2
..
*/