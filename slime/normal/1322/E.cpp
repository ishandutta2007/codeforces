#pragma GCC optimize(3)
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
using namespace std;
int h[maxn]; // 
vi tr; // 
int res[maxn];
int ans;
int poi; 
vi pl[maxn];
set<int> r[2]; //  
int tp[maxn];
int n;
void upd(int pl) {
	r[(tp[pl] + pl) % 2].erase(pl);
	tp[pl] ^= 1;
	r[(tp[pl] + pl) % 2].insert(pl);
}
#define iter set<int>::iterator
pi gt(int pl) {
	int df = (tp[pl] + pl) % 2;
	pi gg;
	int t = 0;
	for (int k = pl + 1; k <= pl + 7; k++)
		if (((tp[k] ^ k ^ df) & 1) || (k > n)) {
			gg.se = k - 1, t++;
			break;
		}
	for (int k = pl - 1; k >= pl - 7; k--)
		if (((tp[k] ^ k ^ df) & 1) || (k <= 0)) {
			gg.fi = k + 1, t++;
			break;
		}
	if (t >= 2) return gg;
	df ^= 1;
	iter rs = r[df].lower_bound(pl);
	iter ls = rs;
	ls--;
	pi fn = mp((*ls) + 1, (*rs) - 1);
	return fn;
}
int fa[maxn];
vi gg[maxn];
int gfa(int a) {
	if (fa[a] == a) return a;
	return fa[a] = gfa(fa[a]);
}
vi cur;
void push(int l, int r, int tp) {
//	cout << l << ' ' << r << ' ' << tp << endl; 
	int i = gfa(l);
	while (i <= r) {	
	//	cout << "PUSH" << l << ' ' << r << ' ' << tp << ' ' << i << endl;
		fa[i] = i + 1;
		res[i] = tp;
		cur.pb(i);
		i = gfa(i + 1);
	}
}
void work(int l, int r, int t) {
	if (tp[l] && tp[r]) push(l, r, t);
	else {
		int mid = (l + r) >> 1;
		if (tp[l]) push(l, mid, t);
		if (tp[r]) push(mid + 1, r, t);
	}
} 
void read(int &a) {
	a = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9')
		a = a * 10 + ch - '0', ch = getchar(); 
}
int st[30];
void otp(int a) {
	int cnt = 0;
	if (!a) st[cnt++] = 0;
	while (a)
		st[cnt++] = a % 10, a /= 10;
	for (int i = cnt - 1; i >= 0; i--)
		putchar('0' + st[i]);
	putchar(' ');
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++) 
		read(h[i]), 
		tr.pb(h[i]);
	sort(tr.begin(), tr.end());
	if (n <= 2) {
		cout << 0 << endl;
		for (int i = 1; i <= n; i++) cout << h[i] << ' ';
		return 0; 
	}
	for (int i = 1; i <= n; i++)
		h[i] = lower_bound(tr.begin(), tr.end(), h[i]) - tr.begin(), 
		pl[h[i]].pb(i);
	for (int i = 0; i <= n + 1; i++)
		fa[i] = i;
	//	cout << i << ' ' << h[i] << endl;
	
	res[1] = h[1], res[n] = h[n];
	poi = n;
	r[0].insert(0), r[0].insert(n + 1);
	r[1].insert(0), r[1].insert(n + 1);
	for (int i = 1; i <= n; i++)
		r[(tp[i] + i) % 2].insert(i);
	for (int i = n - 1; i >= 0; i--) {
		cur.clear();
		for (auto v : pl[i]) {
			pi tx = gt(v);
			upd(v);
			work(v + 1, tx.se, i);
			work(tx.fi, v - 1, i);
			tx = gt(v);
			work(tx.fi, tx.se, i);
		}
		
		for (auto v : cur) {
			pi tx = gt(v);
			ans = max(ans, min(v - tx.fi, tx.se - v));
		}
	} 
	// ans
	r[0].clear(), r[1].clear();
	r[0].insert(0), r[0].insert(n + 1);
	r[1].insert(0), r[1].insert(n + 1);
	memset(tp, 0, sizeof(tp));
	for (int i = 1; i <= n; i++)
		r[(tp[i] + i) % 2].insert(i);
	for (int i = 2; i < n; i++)
		gg[res[i]].pb(i);
//	cout << "AF" << endl;
	for (int i = 0; i < n; i++) {
		for (auto v : pl[i]) upd(v);
		for (auto g : gg[i]) {
			pi q = gt(g);
			int na = min(g - q.fi, q.se - g);
			ans = max(ans, na); 
		}
	}
	/*
	r[0].clear(), r[1].clear();
	r[0].insert(0), r[0].insert(n + 1);
	r[1].insert(0), r[1].insert(n + 1);
	memset(tp, 0, sizeof(tp));
	for (int i = 1; i <= n; i++)
		r[(tp[i] + i) % 2].insert(i);
	for (int i = n - 1; i >= 0; i--) {
		for (auto v : pl[i]) upd(v);
		for (auto g : gg[i]) {
			pi q = gt(g);
			int na = min(g - q.fi, q.se - g);
			ans = max(ans, na); 
		}
	} */
	//otp(ans);
	printf("%d\n", ans);
//	printf("\n");
	for (int i = 1; i <= n; i++)
		printf("%d ", tr[res[i]]); // otp(tr[res[i]]);
//	printf("\n");
	return 0;
}
/*
;CHHOCH
*/