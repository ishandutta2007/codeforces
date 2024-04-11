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
	int num, tt;
	th() {}
	th(int a, int b) {
		num = a, tt = b;
	}
};
th u(th r, th b) {
	if (r.num > b.num) swap(r, b);
	th ans = r;
	if (r.num == b.num) ans.tt += b.tt;
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
		a->ns = th(q[l], 1);
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
//	cout << a->l << ' ' << a->r << ' ' << a->ns.num << ' ' << a->ns.tt << endl;
}
void work(int a, int b) {
	// a : ) b : (
	if (a < b) act(rt, a, b - 1, 2);
	else {
		swap(a, b);
		act(rt, a, b - 1, -2);
	}
}
char inp[maxn];

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", inp + 1);
	rt = &p[stcnt++];
	for (int i = 1; i <= n; i++) {
		q[i] = q[i - 1];
		if (inp[i] == '(') q[i]++;
		else q[i]--;
	//	cout << q[i] << ' ';
	}
	bdtree(rt, 1, n);
	if (q[n] != 0) {
		cout << 0 << endl << 1 << ' ' << 1 << endl;
		return 0;
	}
	else {
		int nans = rt->ns.tt, nl = 1, nr = 1;
		int lpl = 0;
		int mns = maxn;
		for (int i = 1; i <= n; i++)
			if (q[i] < mns) mns = q[i];
		for (int pls = mns; pls <= mns + 1; pls++) {
			for (int i = 1; i <= n; i++)
				if (q[i] <= pls) lpl = i;
			for (int i = 1; i <= n; i++) {
				if (inp[i] == ')') {
					int npl = lpl + 1;
					if (npl > n) npl -= n;
					work(i, npl);
					int u1 = rt->ns.tt;
					if (u1 > nans) nans = u1, nl = i, nr = npl;
					work(npl, i);
				}
				if (q[i] <= pls) lpl = i;
			}
		} 
		cout << nans << endl;
		cout << nl << ' ' << nr << endl;
	}
	return 0;
}