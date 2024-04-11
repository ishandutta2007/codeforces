#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
unordered_map <ll, ll> r;
vector<pair<ll, ll> > g[1024];
 
ll md;
int k;
int hs (ll a) {
	return (((a << 30) ^ (a << 17) ^ a) >> 17) & 1023;
}
ll gt1(ll a) {
	// a * (k + 1)
	if (a == 0) return 0;	
	if (a == 1) return 1ll * k * (k + 1) / 2;
	for (auto v : g[hs(a)])
		if (v.fi == a) return v.se;
	ll c = 1ll * (a - 1) * k + 1;
	ll uu;	
	ll cur = c + c / md - 2;
	ll ls = -1, lans = 0;
	if (c <= k) uu = c;
	else {
		while (1) {
			ll gs = (cur + md) / (md + 1);
			if (gs != ls) 
				ls = gs, lans = gt1(gs);
			if (lans > cur) gs--;
			if (cur - gs < c) cur++;
			else break;
		}
		uu = cur;
	}
	ll us = 0;
	ll cc = uu + k - 1;
	ll ccc = (cc + md) / (md + 1);
	if (ccc == ls) {
		if (lans > cc) ccc--, us = gt1(ccc);
		else us = lans;
	}
	else {
		ll gg = gt1(ccc);
		if (gg > cc) {
			ccc--;
			if (ccc == ls) us = lans;
			else us = gt1(ccc);
		}
		else us = gg;
	}
	cur = k * (2 * uu + k - 1) / 2;
	if (us >= uu)
		cur += uu + k - us;
	g[hs(a)].pb(mp(a, cur)); 
	return cur; 
}
ll gt3(ll c, ll m, ll lans) {
	ll ur = (c + md) / (md + 1);
	if (ur == m) {
		if (lans > c) ur--;
	}
	else if (gt1(ur) > c) ur--;
	return ur; 
}
ll rd() {
	return (rand() * 1ll << 45) + (rand() * 1ll << 30) + (rand() * 1ll << 15) + rand();
}
void read(ll &a) {
	a = 0;
	char ch = getchar();
	while (ch > '9' || ch < '0') ch = getchar();
	while (ch >= '0' && ch <= '9')
		a = a * 10 + ch - '0', 
		ch = getchar();
}
void read(int &a) {
	a = 0;
	char ch = getchar();
	while (ch > '9' || ch < '0') ch = getchar();
	while (ch >= '0' && ch <= '9')
		a = a * 10 + ch - '0', 
		ch = getchar();
}
int st[30];
void otp(ll a) {
	int cnt = 0;
	while (a)
		st[cnt++] = a % 10, a /= 10;
	for (int i = cnt - 1; i >= 0; i--)
		putchar('0' + st[i]);
	putchar('\n');
}
int main() {
	int test = 0;
	if (test) {
		freopen("1.out", "w", stdout);
	}
	int t;
	if (test) t = 1e5;
	else read(t);
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < 1024; j++)
			g[j].clear();
		ll n;
		if (test) n = rd(), k = 3;
		else read(n), read(k);
		md = 1ll * k * k;
		ll id = gt3(n, -1, -1);
		ll ans = 0;
		if (gt1(id) == n) ans = 1ll * id * (k + 1);
		else {
			n -= id;
			ans = (n - 1) / k * (k + 1) + (n - 1) % k + 1; 
		} 
	//	if (test) otp(r.size());
	//	else 
		otp(ans);
	}
	return 0;
}