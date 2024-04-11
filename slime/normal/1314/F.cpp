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
#define ull unsigned long long 
using namespace std;
const ull mt[6] = {2, 4, 16, 256, 65536, 1ll * 65536 * 65536};
const int g[7] = {3, 5, 17, 257, 641, 65537, 6700417};
const int base[7] = {2, 4, 6, 20, 30, 300, 2600};
const ull tot = -1;
ll ksm(ll a, ll b, ll c) {
	if (!b) return 1;
	ll ns = ksm(a, b >> 1, c);
	ns = ns * ns % c;
	if (b & 1) ns = ns * a % c;
	return ns; 
}
int mu[256][256]; // 
ull mul(ull a, ull b, int dep, int tp) {
	if (a < b) swap(a, b);
//	if (tp) cout << a << ' ' << b << ' ' << dep << ' ' << tp << endl;
	if (a == 1 || b == 1) return a * b;
	if (a == 0 || b == 0) return 0; 
	if (a == mt[dep] && b == mt[dep]) return a * 3 / 2;
	if (a == mt[dep]) return a * b;
	if (tp && a < 256 && b < 256) return mu[a][b];
	ull g1 = mul(a / mt[dep], b % mt[dep], dep - 1, tp) ^ mul(a % mt[dep], b / mt[dep], dep - 1, tp);
	g1 *= mt[dep];
	g1 ^= mul(a % mt[dep], b % mt[dep], dep - 1, tp);
	ull cur = mul(a / mt[dep], b / mt[dep], dep - 1, tp);
	g1 ^= cur * mt[dep];
	g1 ^= mul(cur, mt[dep] / 2, dep - 1, tp);
	return g1;
}
ull ksm(ull a, ull b) {
	if (b == 0) return 1;
	ull ns = ksm(a, b >> 1);
	ns = mul(ns, ns, 5, 1);
	if (b & 1) ns = mul(ns, a, 5, 1);
	return ns;
}
int res[7];
ull cal() { // res  
	ll cur = 1;
	ull ans = 0;
	for (int i = 0; i < 7; i++) {
		if (res[i] == -1) continue;
		ll t = 1ll * (res[i] - (ll)ans % g[i]) * ksm(cur % g[i], g[i] - 2, g[i]) % g[i];	
		if (t < 0) t += g[i];
		ans += ((ull)cur) * ((ull)t);
		cur *= g[i];
	}
	for (int i = 0; i < 7; i++) 
		if (res[i] != -1) assert(ans % g[i] == res[i]);
	return ans;
}
const ull rt = (1ll << 32) + 7;
vi gt(ull a) {
	vi fn;
	for (int i = 0; i < 7; i++) {
		unordered_map<ull, int> id;
		ull cur = 1, step = rt;
		step = ksm(step, tot / g[i]);
		ull bstep = ksm(step, tot - 1);
		ull beg = ksm(a, tot / g[i]);
	//	cout << beg << ' ' << step << ' ' << bstep << endl; 
		for (int j = 0; j < base[i]; j++) {
			id[cur] = j + 1;
			cur = mul(cur, bstep, 5, 1);
		}
		cur = ksm(step, base[i]);
		
		for (int j = 0; j < base[i]; j++) {
			if (id[beg]) {
				int u = id[beg] - 1;
			//	cout << u << ' ' << j << endl;
				u += j * base[i];
				u = -u;
				u %= g[i];
				if (u < 0) u += g[i];
			//	ull cur = mul(beg, ksm(step, u), 5, 1);
			//	cout << "???" << cur << endl;
				fn.pb(u);
				break; 
			}
			beg = mul(beg, cur, 5, 1);
		}
	//	cout << "AF" << ' ' << fn.size() << endl;
	//	while (1); 
	//	ull gg = mul(a, ksm(rt, (g[i] - fn[i]) % g[i]), 5, 1);
	//	cout << "CUR" << ksm(gg, (tot) / g[i]) << ' ' << fn[i] << ' ' << endl;
	//	cout << i << ' ' << fn[i] << ' ' << fn.size() << endl; 
	}
	return fn;
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < 256; i++)
		for (int j = 0; j < 256; j++)
			mu[i][j] = mul(i, j, 5, 0);
//	cout << ksm(2, 3) << endl;
//	cout << ksm(rt, tot) << endl;
//	for (int i = 0; i < 7; i++) {
//		cout << ksm(rt, (tot) / g[i]) << endl;
//	}
//	while (1);
	for (int i = 0; i < t; i++) {
		ull a, b;
		cin >> a >> b;
		vi f1 = gt(a);
		vi f2 = gt(b);
		int s = 0;
		for (int i = 0; i < 7; i++) {
			if (f1[i] == 0 && f2[i] != 0) {
				cout << "-1" << endl;
				s = 1;
				break;
			}
			else {
				if (f1[i] == 0) res[i] = -1;
				else res[i] = 1ll * f2[i] * ksm(f1[i], g[i] - 2, g[i]) % g[i];
			}
		}
		if (!s) cout << cal() << endl;
	}
	return 0;
}