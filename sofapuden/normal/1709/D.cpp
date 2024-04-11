#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct seg {
	struct nod {
		int val;
	};
	int n;
	vector<nod> st;
	vector<int> A;

	seg(int sz) : n(sz), st(4*n) {}
	seg(vector<int> &_A) : seg((int)_A.size()) {
		A = _A;
		build(0,n-1,1);
	}
 
	nod merge (nod a, nod b) {
		if(a.val > b.val)return a;
		return b;
	}
	
	void build(int l, int r, int p){
		if(l == r){
			st[p].val = A[l];
			return;
		}
		int m = (l+r) >> 1;
		build(l,m,p<<1);
		build(m+1,r,p<<1|1);
		st[p] = merge(st[p<<1],st[p<<1|1]);
	}
 
	nod que(int i, int j, int l, int r, int p){
		if(l >= i && r <= j)return st[p];
		int m = (l+r)>>1;
		if(m < i)return que(i,j,m+1,r,p<<1|1);
		else if(m >= j)return que(i,j,l,m,p<<1);
		else return merge(que(i,j,l,m,p<<1),que(i,j,m+1,r,p<<1|1));
	}
};

void solve(){
	int n, m; cin >> n >> m;
	vector<int> v(m);
	for(auto &x : v)cin >> x;
	seg st(v);
	int q; cin >> q;
	while(q--){
		int x1, y1, x2, y2, k; cin >> x1 >> y1 >> x2 >> y2 >> k;
		if(y1 > y2)swap(y1,y2);
		if(((x1-x2)%k+k)%k){
			cout << "NO\n";
			continue;
		}
		if(((y1-y2)%k+k)%k){
			cout << "NO\n";
			continue;
		}
		if(st.que(y1-1,y2-1,0,m-1,1).val < ((n-x1)/k)*k+x1){
			cout << "YES\n";
			continue;
		}
		else cout << "NO\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
}