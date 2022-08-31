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
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
struct ST {
	int l, r, cnt[2];
	int lz;
	ST *ch[2];
}p[maxn << 1], *root;
int stcnt = 0;
int ed[maxn];
void upd(ST *a){
	for (int i = 0; i < 2; i++)
		a->cnt[i] = a->ch[0]->cnt[i] + a->ch[1]->cnt[i];
}
void bdtree(ST *a, int l, int r) {
	a->l = l, a->r = r, a->lz = -1;
	a->cnt[0] = a->cnt[1] = 0;
	if (l == r) a->cnt[ed[l]]++;
	else {
		int mid = (l + r) >> 1;
		a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
		bdtree(a->ch[0], l, mid), 
		bdtree(a->ch[1], mid + 1, r);
		upd(a); 
	}
}
void push(ST *a, int lz) {
	a->cnt[lz] = a->cnt[0] + a->cnt[1];
	a->cnt[lz ^ 1] = 0;
	a->lz = lz;
}
void pushdown(ST *a) {
	if (a->lz != -1) {
		for (int i = 0; i < 2; i++)
			push(a->ch[i], a->lz);
		a->lz = -1;
	}
}
void act(ST *a, int l, int r, int lz) {
	if (a->l == l && a->r == r) {
		push(a, lz);
		return ;
	}
	pushdown(a);
	int mid = (a->l + a->r) >> 1;
	if (r <= mid) act(a->ch[0], l, r, lz);
	else if (l > mid) act(a->ch[1], l, r, lz);
	else act(a->ch[0], l, mid, lz), act(a->ch[1], mid + 1, r, lz);
	upd(a);
}
int q(ST *a, int l, int r) {
	if (a->l == l && a->r == r) 
		return a->cnt[0];
	pushdown(a);
	int mid = (a->l + a->r) >> 1;
	if (r <= mid) return q(a->ch[0], l, r);
	else if (l > mid) return q(a->ch[1], l, r);
	else return q(a->ch[0], l, mid) + q(a->ch[1], mid + 1, r);
}
int s[maxn];
char in[maxn];
int l[maxn], r[maxn];
int main() {
	int t;
	cin >> t;
	while (t--) {
		stcnt = 0;
		int n, qq;
		scanf("%d%d", &n, &qq);
		scanf("%s", in + 1);
		for (int i = 1; i <= n; i++) s[i] = in[i] - '0';
		scanf("%s", in + 1);
		for (int i = 1; i <= n; i++) ed[i] = in[i] - '0';	
		root = &p[stcnt++];
		bdtree(root, 1, n);
		for (int i = 1; i <= qq; i++)
			scanf("%d%d", &l[i], &r[i]);
		int fl = 1;
		for (int i = qq; i >= 1; i--) {
			int cnt[2];
			cnt[0] = q(root, l[i], r[i]), cnt[1] = r[i] - l[i] + 1 - cnt[0];
		//	cout << cnt[0] << ' ' << cnt[1] << endl;
			if (cnt[0] == cnt[1]) fl = 0;
			int mx = 0;
			if (cnt[1] > cnt[0]) mx = 1;
			act(root, l[i], r[i], mx);
		}
		for (int i = 1; i <= n; i++)
			if (q(root, i, i) != 1 - s[i]) fl = 0;
		if (fl) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}