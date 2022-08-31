//Awwawa! Dis cold yis ratten buy tEMMIE!
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
int pl[5500];
struct th {
	int sz;
	int l, r;
	vi pls;
	th *ch[2];
	vector<vi> id;
}p[200005], *rt[70];
int cal(th *a, int l, int r) {
	int p1 = lower_bound(a->pls.begin(), a->pls.end(), l) - a->pls.begin();
	int p2 = lower_bound(a->pls.begin(), a->pls.end(), r + 1) - a->pls.begin() - 1;
	if (p1 > p2) return 0;
//	cout << a->r - a->l + 1 << ' ' << p1 << ' ' << p2 << endl;
	return a->id[p1][p2]; 
}
int cnt = 0;
vector<pi> g;
int mer(int x, int y) {
	if (!x) return y;
	if (!y) return x;
	cnt++;
	g.pb(mp(x, y));
	return cnt;
}
int stcnt = 0;
void bdtree(th *a, int l, int r) {
	// 
	a->l = l, a->r = r;
	for (int i = l; i <= r; i++)
		a->pls.pb(pl[i]);
	int sz = r - l + 1;
	sort(a->pls.begin(), a->pls.end());
	a->id.resize(sz);
	for (int j = 0; j < sz; j++)
		a->id[j].resize(sz);
	if (sz == 1)
		a->id[0][0] = a->pls[0];
	else {
		int mid = (l + r) >> 1;
		a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
		bdtree(a->ch[0], l, mid);
		bdtree(a->ch[1], mid + 1, r);
	//	cout << "BUO" << l << ' ' << r << endl;
		for (int i = 0; i < sz; i++)	
			for (int j = i; j < sz; j++)
				a->id[i][j] = mer(cal(a->ch[0], a->pls[i], a->pls[j]), 
								  cal(a->ch[1], a->pls[i], a->pls[j]));
	}
}
int re[maxn];
int main() {
	int n, qs;
	scanf("%d%d", &n, &qs);
	cnt = n;
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a), 
		pl[a] = i;
	}
	vector<th*> q;
	int nr = 1;
	while (nr <= n) {
		th *n1 = &p[stcnt++];
		int ur = min(n, nr + 200);
		bdtree(n1, nr, ur);
		q.pb(n1);
		nr = ur + 1;
	//	cout << "AF" << endl;
	}
//	cout << "Q" << endl;
	for (int i = 1; i <= qs; i++) {
		int pr = 0;
		int l, r;
		scanf("%d%d", &l, &r);
		for (auto m : q)
			pr = mer(pr, cal(m, l, r));
		re[i] = pr;
	}
	cout << cnt << endl;
	for (auto h : g)
		printf("%d %d\n", h.fi, h.se);
	for (int i = 1; i <= qs; i++)
		printf("%d ", re[i]);
	return 0;
}