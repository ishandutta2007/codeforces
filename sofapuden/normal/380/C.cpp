#include<bits/stdc++.h>

using namespace std;

struct seg {
	struct nod {
		int l, r;
	};

	int n;
	vector<nod> st;
	string A;

	seg(int _n) : n(_n), st(4*n) {}
	seg(string _A) : seg((int)_A.size()) {
		A = _A;
		build(0,n-1,1);
	}

	nod merge(nod a, nod b){
		nod c;
		c.l = a.l + b.l - min(b.l,a.r);
		c.r = a.r + b.r - min(b.l,a.r);
		return c;
	}

	void build(int l, int r, int p){
		if(l == r){
			st[p].l = A[l] == ')';
			st[p].r = A[l] == '(';
			return;
		}
		int m = (l+r)>>1;
		build(l,m,p<<1);
		build(m+1,r,p<<1|1);
		st[p] = merge(st[p<<1],st[p<<1|1]);
	}

	nod que(int i, int j, int l, int r, int p){
		if(l >= i && r <= j)return st[p];
		int m = (l+r)>>1;
		if(i > m)return que(i,j,m+1,r,p<<1|1);
		if(j <= m)return que(i,j,l,m,p<<1);
		return merge(que(i,j,l,m,p<<1),que(i,j,m+1,r,p<<1|1));
	}

};

void solve(){
	string s; cin >> s;
	int n = s.size();
	seg ST(s);
	int q; cin >> q;
	while(q--){
		int l, r; cin >> l >> r;
		auto x = ST.que(l-1,r-1,0,n-1,1);
		cout << r-l+1-x.l-x.r << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	solve();
}