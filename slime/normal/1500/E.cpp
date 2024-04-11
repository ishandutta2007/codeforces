//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 500005 /*rem*/
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
struct ST {
	int l, r;
	ST *ch[2];
	ll sum, rs; // rs : 
	int sz; 
}p[maxn << 1], *root;
void upd(ST *a) {
	a->sz = a->ch[0]->sz + a->ch[1]->sz;
	a->sum = a->ch[0]->sum + a->ch[1]->sum;
	a->rs = a->ch[0]->rs + a->ch[1]->rs + a->ch[1]->sum * a->ch[0]->sz;
}
ll tr[maxn];
int stcnt = 0;
void bdtree(ST *a, int l, int r) {
	a->l = l, a->r = r, a->sum = a->rs = a->sz = 0;
	if (l == r) 
		return ;
	int mid = (l + r) >> 1;
	a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
	bdtree(a->ch[0], l, mid);
	bdtree(a->ch[1], mid + 1, r);
}
void ins(ST *a, int pl, int tp) {
	if (a->l == a->r) {
		a->rs += tp * tr[a->l];
		a->sum += tp * tr[a->l];
		a->sz += tp;
		return ;
	}
	int mid = (a->l + a->r) >> 1;
	if (pl <= mid) ins(a->ch[0], pl, tp);
	else if (pl > mid) ins(a->ch[1], pl, tp);
	upd(a);
}
pair<ll, ll> q(ST *a, int l, int r) {
	l = max(l, a->l);
	r = min(r, a->r); 
//	if (l > r) return mp(0, 0); 
//	cout << a->l << ' ' << l << ' ' << a->r << ' ' << r << endl;
	if (a->l == l && a->r == r)
		return mp(a->sum, a->rs);
		
	int mid = (a->l + a->r) >> 1;
	if (r <= mid) return q(a->ch[0], l, r);
	else if (l > mid) return q(a->ch[1], l, r);
	else {
		pair<ll, ll> u[2] = {q(a->ch[0], l, mid), q(a->ch[1], mid + 1, r)};
		return mp(u[0].fi + u[1].fi, u[0].se + u[1].se + u[1].fi * a->ch[0]->sz);
	} 
}
int fd(ST *a, int k) {
	if (a->l == a->r) return a->l;
	if (k <= a->ch[0]->sz) return fd(a->ch[0], k);
	return fd(a->ch[1], k - a->ch[0]->sz);
}
vector<ll> as;
ll s[maxn];
int t[maxn];
ll a[maxn];
int n, m;
ll sum;
int pp(ll q) {
	return lower_bound(as.begin(), as.end(), q) - as.begin() + 1;
}
ll f(int p) {
	// 1   p 
	if (p <= 0) return 0;
	if (p > n) p = n;
	int id = fd(root, p);
	assert(id >= 1);
	pair<ll, ll> cr = q(root, 1, id);
	ll ans = (p + 1) * cr.fi - cr.se;
//	cout << p << ' ' << ans << endl;
	return ans; 
}
ll cal(int p) {
	ll ed = f(p + 1) - (1ll * (p + 1) * sum - (f(n) - f(n - p - 1)));
	return ed;
}
ll gans() {
	ll ans = 0;
		if (n <= 1) ans = 0;
		else {
			int l = 0, r = (n - 1) / 2; //  n 
			while (l < r) {
				int mid = (l + r) >> 1;
			//	cout << "CHK" << mid << endl; 
				ll cm = q(root, 1, fd(root, mid + 2)).fi - q(root, fd(root, n + 1 - (mid + 1)), root->r).fi;//  mid  
			//	cout << "AFT" << endl;
				if (cm >= 0) l = mid + 1;
				else r = mid;
			} 
			ll res = 2 * cal(l);
		//	cout << n << ' ' << l << ' ' << sum << ' ' << res << endl;
			if (n % 2 == 1 && l == (n - 1) / 2) {
				ll cm = q(root, 1, fd(root, l + 1)).fi;
				if (l > 0) {
					int id = fd(root, n + 1 - l);
					cm -= q(root, id, root->r).fi;
				}
				res -= cm;
			}
			ans = sum - res;
		}
	return ans;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) scanf("%lld", &s[i]), as.pb(s[i]), sum += s[i];

	for (int i = 1; i <= m; i++)
		scanf("%d%lld", &t[i], &a[i]), 
		as.pb(a[i]);
	sort(as.begin(), as.end());
	for (int i = 0; i < n + m; i++)
		tr[i + 1] = as[i]; 
	
	root = &p[stcnt++];
	bdtree(root, 1, n + m);
	for (int i = 1; i <= n; i++)
		ins(root, pp(s[i]), 1);
	printf("%lld\n", gans());
	for (int i = 1; i <= m; i++) {
		if (t[i] == 1) {
			//  min 
			int id = pp(a[i]);
			ins(root, id, 1);
			n++;
			sum += a[i];
		}
		else {
			int id = pp(a[i]);
			ins(root, id, -1);
			n--;
			sum -= a[i];
		}
		printf("%lld\n", gans());
	}
	return 0;
}
/*
3 11
1 2 3
2 1
1 5
1 6
1 7
2 6
2 2
2 3
1 10
2 5
2 7
2 10
*/