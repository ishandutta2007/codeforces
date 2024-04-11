#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
#define fi first
#define pi pair<int, int>
#define se second
#define mp make_pair
#define iter multiset<int>::iterator
struct BIT {
	ll d[maxn];
	int lb(int x) {
		return x & -x;
	}
	void ch(int pl, int num) {
		while (pl < maxn)
			d[pl] += num, 
			pl += lb(pl);
	}
	ll q(int pl) {
		ll ans = 0;
		while (pl)
			ans += d[pl], 
			pl -= lb(pl);
		return ans;
	}
}bb[2];
void act(int a, int y) {
	// min(ax, y)
	if (a == 0) return ;
	bb[1].ch(1, a);
	int dv = y / a + 1;
	bb[1].ch(dv, -a),
	bb[0].ch(dv, y);
}
ll q(int num) {
	num = min(num, maxn - 1);
	return 1ll * bb[1].q(num) * num + bb[0].q(num);
}
int w[maxn];
int ts[maxn];
vi ins[maxn], era[maxn];
int s[maxn], m[maxn], r[maxn];
ll ans[maxn];
void upd(int a, int b) {
//	cout << " UPD" << a << ' ' << b << endl;
	ans[a] += q(w[a]) - q(b);
	w[a] = b;
}
set<int> g;
void upd(iter r) {
	if (r == g.end()) return ;
	if (r == g.begin()) {
		upd(*r, ts[*r]);
		return ;
	}
	iter q = r;
	q--;	
	upd(*r, ts[*r] - ts[*q]);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		scanf("%d%d%d", &s[i], &m[i], &r[i]);
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int l, r;
		scanf("%d%d%d", &ts[i], &l, &r);
		ins[l].pb(i), 
		era[r + 1].pb(i);
	}
	
	for (int i = 1; i <= n; i++) {
		for (auto s: ins[i]) {
			g.insert(s);
		//	cout << "INS" << s << endl;
			iter r = g.find(s);
			upd(r);
			r++;
			upd(r);
		}
		for (auto s: era[i]) {
			upd(s, 0);
			g.erase(s);
			iter r = g.lower_bound(s);
			upd(r);
		}
		act(r[i], m[i]);
		if (g.size()) {
			int id = *g.begin();
			ans[id] += min((ll)m[i], s[i] + 1ll * r[i] * ts[id]) - min((ll)m[i], 1ll * r[i] * ts[id]);
		}
	}
	for (int i = 1; i <= q; i++)
		upd(i, 0); 
	for (int i = 1; i <= q; i++)
		printf("%lld\n", ans[i]);
	return 0;
}