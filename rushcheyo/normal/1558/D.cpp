#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1000005, P = 998244353;
int fac[N], ifac[N];

int power(int a, int x) {
	int ans = 1;
	for (; x; x >>= 1, a = 1ll * a * a % P)
		if (x & 1) ans = 1ll * ans * a % P;
	return ans;
}
#define SZ(x) (x?x->size:0)
struct Treap{
	int st,ed,fix,size;
	Treap *l,*r;
	void update(){size=SZ(l)+SZ(r)+ed-st+1;}
}*root,t[N];
int rnd(){
	static unsigned x=1594702318;
	x^=(x<<13);x^=(x>>17);x^=(x<<5);
	return x;
}
Treap *newnode(int l,int r){
	if(l>r)return NULL;
	static Treap *ed=t;
	*ed=(Treap){l,r,rnd(),r-l+1};
	return ed++;
}
void split(Treap *p,int k,Treap *&l,Treap *&r){
	if (k<=0) l = NULL, r = p;
	else if (!p)l=r=0;
	else{
		if (k<=SZ(p->l))r=p,split(p->l,k,l,p->l);
		else l=p,split(p->r,k-SZ(p->l)-(p->ed-p->st+1),p->r,r);
		p->update();
	}
}
void split_max(Treap *p,Treap *&l,Treap *&r){
	auto tmp = p;
	while (tmp->r) tmp = tmp->r;
	split(p, SZ(p) - (tmp->ed - tmp->st + 1), l, r);
	// if (!p) l = r = 0;
	// else {
	// 	if (p->r) l=p,split_max(p->r,p->r,r);
	// 	else{
	// 		l = p->l;
	// 		r = p;
	// 	}
	// }
}
Treap *merge(Treap *p,Treap *q){
	if (!p)return q;
	if (!q)return p;
	if (p->fix<q->fix){
		p->r=merge(p->r,q);
		p->update();
		return p;
	}else{
		q->l=merge(p,q->l);
		q->update();
		return q;
	}
}

int binom(int n, int m) {
	return 1ll * fac[n] * ifac[m] % P * ifac[n - m] % P;
}

vector<pair<int, int>> all;
void dfs(Treap *p){
	if (!p)return;
	dfs(p->l);
	all.emplace_back(p->st,p->ed);
	dfs(p->r);
}


int main() {
	for (int i = fac[0] = 1; i < N; ++i) fac[i] = 1ll * fac[i - 1] * i % P;
	ifac[N - 1] = power(fac[N - 1], P - 2);
	for (int i = N - 1; i; --i) ifac[i - 1] = 1ll * ifac[i] * i % P;
	ios::sync_with_stdio(false), cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		//  
		// 
		// 
		// 
		// x[1] < x[2] <= x[3] < x[4] <= x[5] < x[6] <= x[7] <= ...
		// x[1] > 0, x[2] - x[1] > 0, x[3] - x[2] >= 0, ...
		// x[n + 1] - x[n] >= 0
		// x[i] = n
		//  k  q[i] > q[i + 1] n+1  n + k + 1C(n+k,n)
		int n, m;
		cin >> n >> m;
		root = newnode(1, 1);
		int lstx = 1;
		for (int i = 1; i <= m; ++i) {
			int x, y;
			cin >> x >> y;
			if (lstx + 1 <= x - 1) {
				root = merge(root, newnode(lstx + 1, x - 1));
			}
			Treap *a, *b, *c;
			split(root, y, a, c);
			split_max(a, a, b);
			Treap *d = newnode(b->st, b->st + y - SZ(a) - 2);
			Treap *e = newnode(x, x);
			Treap *f = newnode(b->st + y - SZ(a) - 1, b->ed);
			root = merge(merge(a, merge(merge(d, e), f)), c);
			lstx = x;
			// [lstx + 1 .. x - 1] 
			//  y 
		}
		if (lstx + 1 <= n) root = merge(root, newnode(lstx + 1, n));
		all.clear();
		dfs(root);
		int k = 0;
		for (int i = 0; i < all.size(); ++i)
			k += all[i].second - all[i].first;
		for (int i = 1; i < all.size(); ++i)
			k += all[i - 1].second < all[i].first;
		cout << binom(n + k, n) << '\n';
	}
}