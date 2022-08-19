#include <bits/stdc++.h>
#define ll long long
#define maxn 600005 /*rem*/
#define mod 998244353
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
struct th {
	int num, pl;
	th() {}
	th(int a, int b) {
		num = a, pl = b;
	}
};
th u(th r, th b) {
	if (r.num > b.num) swap(r, b);
	th ans = r;
	if (r.num == b.num) ans.pl = min(ans.pl, b.pl);
	return ans;
}
struct ST {
	int l, r, lz;
	ST *ch[2];
	th ns;
}p[maxn << 1], *rt;
int stcnt = 0;
int q[maxn];
void upd(ST *a) {
	a->ns = u(a->ch[0]->ns, a->ch[1]->ns);
}
void bdtree(ST*a, int l, int r) {
	a->l = l, a->r = r;
	if (l == r) {
		a->ns = th(maxn, l);
		return  ;
	}
	int mid = (l + r) >> 1;
	a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
	bdtree(a->ch[0], l, mid), bdtree(a->ch[1], mid + 1, r);
	upd(a);
} 
void actlz(ST *a, int b) {
	a->lz += b, a->ns.num += b;
}
void pushdown(ST *a) {
	if (a->lz) {
		actlz(a->ch[0], a->lz), 
		actlz(a->ch[1], a->lz);
		a->lz = 0;
	}
}
void act(ST *a, int l, int r, int lz) {
	if (l > r) return ;
	if (a->l == l && a->r == r) {
		actlz(a, lz);
		return;
	}
	int mid = (a->l + a->r ) >> 1;
	pushdown(a);
	if (r <= mid) act(a->ch[0], l, r, lz);
	else if (l > mid) act(a->ch[1], l, r, lz);
	else act(a->ch[0], l, mid, lz), 
		act(a->ch[1], mid + 1, r, lz);
	upd(a);
}
struct ev {
	ll a;
	int b;
	ev(ll x, int y) {
		a = x, b = y;
	}
	bool operator < (const ev &r) const{
		if (a != r.a) return a > r.a;
		return b > r.b;
	}
};
priority_queue <ev> s;
ll ans[maxn];
ll ns = 0;
int main() {
	int n, tm;
	scanf("%d%d", &n, &tm);
	rt = &p[stcnt++];
	bdtree(rt, 1, n);
	for (int i = 1; i <= n; i++) {
		int t;
		scanf("%d", &t);
		s.push(ev(t, i));
	}
	while (!s.empty()) {
		ll ntm = s.top().a;
		while (!s.empty()) {
			ev r = s.top();
			if (r.a != ntm) break;
			s.pop();
			if (r.b > 0) act(rt, r.b, r.b, -maxn);//, cout << "INQ" << r.b << endl;
			else 
				act(rt, -r.b + 1, n, -1);
		}
		if (rt->ns.num == 0) {
			int npl = rt->ns.pl;
		//	cout << "INS" << npl << endl;
			act(rt, npl, n, 1);
			ll ned = max(ntm, ns) + tm;
			ans[npl] = ned;
			s.push(ev(ned, -npl));
			ns = ned;
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%lld ", ans[i]);
	return 0;
}