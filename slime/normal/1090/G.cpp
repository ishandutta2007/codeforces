#include <bits/stdc++.h>
#define ll long long
#define maxn 250005 /*rem*/
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
const int inf = 1000000007;
struct ST {
	ST *ch[2];
	int l, r;
	int nx, nd, len; // 
}p[12000005];
int stcnt = 0; 
ll pw[maxn + 30];
void bdtree(ST *a, int l, int r) {
//	assert(r - l + 1 <= maxn + 2);
	a->nx = 0, 
	a->nd = pw[r - l + 1], 
	a->l = l, a->r = r, 
	a->len = r - l + 1;
	if (l == r) return;
	int mid = (l + r) >> 1;
	a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
	bdtree(a->ch[0], l, mid), bdtree(a->ch[1], mid + 1, r);
}
void upd(ST *a) {
	a->nx = a->ch[1]->nx;
	ll ed = a->ch[1]->nd - a->ch[0]->nx;
	if (ed <= 0) {
		ll gg = (-ed) / pw[a->ch[1]->len];
		ed += gg * pw[a->ch[1]->len], a->nx += gg;
	}
	while (ed <= 0) a->nx++, ed += pw[a->ch[1]->len];
	ed = (ed - 1) * pw[a->ch[0]->len] + a->ch[0]->nd;
	ed = min(ed, (ll)inf);
	a->nd = ed;
//	if (a->ch[0]->)
	assert(a->nd > 0);
//	assert(a->nd > 0);
} 
void copy(ST *a, ST *b) {
	a->ch[0] = b->ch[0], 
	a->ch[1] = b->ch[1], 
	a->l = b->l, a->r = b->r, 
	a->nx = b->nx, 
	a->nd = b->nd, 
	a->len = b->len;
}
void uu(ST *a, int tp) {
	ST *n1 = &p[stcnt++]; 
	copy(n1, a->ch[tp]); 
	a->ch[tp] = n1;
}
void ch(ST *a, int pl) {
	if (a->l == a->r) {
		a->nd--;
		if (a->nd == 0) a->nx++, a->nd = 2;
		return ;
	}
	int mid = (a->l + a->r) >> 1;
	if (pl <= mid) uu(a, 0), ch(a->ch[0], pl);
	else uu(a, 1), ch(a->ch[1], pl);
	upd(a);
//	cout << a->l << ' ' << a->r << ' ' << a->nx << ' ' << a->nd << endl;
}
struct th {
	int a;
	int h;
	int t;
	ST *r;
	void upd(int cs, int um) {
		if (t != -1) return ;
		um = um + maxn + 1 - h;
		if (um <= maxn && um >= 0) {
		//	cout << "!!!" << um << endl;
			ch(r, um);
			if (r->nx > 0)
				t = cs;
		}
		else t = cs;
	}
}q[maxn];
int cnt = 0;
void nn(int id, int cs) {
	cnt++;
	q[cnt] = q[id];
	q[cnt].r = &p[stcnt++];
	copy(q[cnt].r, q[id].r);
	if (q[cnt].t != -1) 
		q[cnt].t = cs;
}
int main() {
	pw[0] = 1;
	for (int i = 1; i < maxn + 30; i++) {
		pw[i] = pw[i - 1] * 2;
		pw[i] = min(pw[i], (ll)inf);
	}
	q[0].a = 0, q[0].h = 0, q[0].t = -1;
	q[0].r = &p[stcnt++];
	bdtree(q[0].r, 0, maxn);
	//assert(q[0].r)
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t, a, b;
		scanf("%d", &t);
		if (t == 1) nn(0, i);
		else {
			scanf("%d", &a);
			if (t == 2) q[a].a++;
			else if (t == 3) q[a].h++;
			else if (t == 4) nn(a, i);
			else {
				scanf("%d", &b);
				if (q[a].t != -1 || q[b].t != -1) continue;
				q[a].upd(i, q[b].a);
				q[b].upd(i, q[a].a);
			}
		}
	}
	cout << cnt << endl;
	for (int i = 1; i <= cnt; i++)
		printf("%d ", q[i].t);
	return 0;
}