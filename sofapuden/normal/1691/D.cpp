#include<bits/stdc++.h>
 
using namespace std;

typedef long long ll;

class segTree{
private:
	int n;
	vector<ll> A;
	vector<array<ll,2>> st;
 
	int l(int p){return p<<1;}
	int r(int p){return (p<<1)+1;}
 
	array<ll,2> conquer(array<ll,2> a, array<ll,2> b){
		if(a[0] > b[0])return a;
		else return b;
	}
 
	void build(int p, int L, int R){
		if(L == R){
			st[p] = {A[L],L};
			return;
		}
		int m = (L+R)>>1;
		build(l(p),L,m);
		build(r(p),m+1,R);
		st[p] = conquer(st[l(p)],st[r(p)]);
	}
 
	array<ll,2> que(int p, int L, int R, int i, int j){
		if(i > j)return {-(1ll<<60),0ll};
		if(L >= i && R <= j)return st[p];
		int m = (L+R)>>1;
		return conquer(que(l(p),L,m,i,min(j,m)),que(r(p),m+1,R,max(i,m+1),j));
	}
 
	void update(int p, int L, int R, int i, int j, ll val){
		if(i > j)return;
		if(L == R){
			A[L] = val;
			st[p] = {val,L};
		}
		else{
			int m = (L+R)>>1;
			update(l(p),L,m,i,min(j,m),val);
			update(r(p),m+1,R,max(i,m+1),j,val);
			st[p] = conquer(st[l(p)],st[r(p)]);
		}
	}
public:
	segTree(int sz) : n(sz), st(4*n) {}
	segTree(const vector<ll> &ini) : segTree((int)ini.size()){
		A = ini;
		build(1,0,n-1);
	}
 
	void update(int x, ll val){update(1,0,n-1,x,x,val);}
	array<ll,2> que(int i, int j){return que(1,0,n-1,i,j);}
};

void solve(){
	int n; cin >> n;
	vector<ll> v(n);
	vector<ll> pre, suf;
	for(auto &x : v)cin >> x;
	pre = v;
	suf = v;
	for(int i = 1; i < n; ++i){
		pre[i] += pre[i-1];
	}
	for(int i = n-2; ~i; --i){
		suf[i] += suf[i+1];
	}
	segTree a(v), b(pre), c(suf);
	for(int i = 0; i < n; ++i){
		array<ll,2> x = c.que(0,i);
		array<ll,2> y = b.que(i,n-1);
		array<ll,2> z = a.que(x[1],i);
		array<ll,2> w = a.que(i,y[1]);
		if(z[0] < pre[i]-(x[1] ? pre[x[1]-1] : 0)){
			cout << "NO\n";
			return;
		}
		if(w[0] < pre[y[1]]-(i ? pre[i-1] : 0)){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)solve();
}