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
int n;
int a[maxn];
int cnt[maxn];
int tot[maxn];
const int dv = 350;
#define iter multiset<int>::iterator
struct qr {
	int l, r, id;
	bool operator < (const qr &s)const { 
		if (l / dv != s.l / dv) return l < s.l;
		return r < s.r;
	}
}p[maxn];
int res[maxn];
const int DV = 705;
priority_queue<int, vector<int>, greater<int> >g;
vector<pi> r;
void ins(int pl, int tp) {
	cnt[tot[pl]]--;
	tot[pl] += tp;
	cnt[tot[pl]]++;
	if (tot[pl] >= DV) 
		r.pb(mp(pl, tot[pl]));
}
int fl[maxn];
int nr[DV];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		p[i].id = i, scanf("%d%d", &p[i].l, &p[i].r);
	}
	sort(p + 1, p + q + 1);
	int L = 1, R = 0;
	for (int i = 1; i <= q; i++) {
		while (R < p[i].r) ins(a[R + 1], 1), R++;
		while (L > p[i].l) ins(a[L - 1], 1), L--;
		while (R > p[i].r) ins(a[R], -1), R--;
		while (L < p[i].l) ins(a[L], -1), L++;
		memset(nr, 0, sizeof(nr));
		while (g.size())
			g.pop();
		vector<pi> u;
		for (auto i: r)
			if (fl[i.fi]) continue;
			else if (tot[i.fi] != i.se) continue;
			else {
				fl[i.fi] = 1;
				u.pb(i);
				g.push(i.se);
			}
		r = u;
		for (auto i: u)
			fl[i.fi] = 0;
		for (int i = 0; i < DV; i++)
			nr[i] = cnt[i];
		int ls = 0;
		int ans = 0;
		for (int i = 1; i < DV; i++) {
			if (nr[i] && ls) {
				int nm = ls + i;
				ans += nm;
				if (nm < DV) nr[nm]++;
				else g.push(nm);
				nr[i]--;
				ls = 0;
			}
			int nd = i * 2;
			ans += nd * (nr[i] / 2);
			if (nd < DV)
				nr[nd] += nr[i] / 2;
			else {
				for (int j = 0; j < nr[i] / 2; j++)
					g.push(nd);
			}
			nr[i] %= 2;
			if (nr[i]) ls = i;
		}
		if (ls) g.push(ls);
		while (g.size() >= 2) {
			int f = g.top();
			g.pop();
			int q = g.top();
			g.pop();
			ans += f + q;
			g.push(f + q);
		}
		res[p[i].id] = ans;
	}
	for (int i = 1; i <= q; i++)
		printf("%d\n", res[i]);
	return 0;
}