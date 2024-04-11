#include<bits/stdc++.h>

using namespace std;

const int MX = 1e9+5;

struct seg{
	seg(int sz) : n(sz), stGCD(4*n,0), stMN(4*n,0), stAM(4*n,0) {}
	seg(vector<int> &ini) : seg((int)ini.size()){
		A = ini;
		build(1,0,n-1);
	}
	
	int n;
	vector<int> stGCD, stMN, stAM;
	vector<int> A;

	void mer(int a, int b, int c){
		stGCD[c] = __gcd(stGCD[a],stGCD[b]);
		stMN[c] = min(stMN[a],stMN[b]);
		stAM[c] = 0;
		if(stMN[c] == stMN[a])stAM[c]+=stAM[a];
		if(stMN[c] == stMN[b])stAM[c]+=stAM[b];
	}

	void build(int p, int l, int r){
		if(l == r){
			stGCD[p] = A[l];
			stMN[p] = A[l];
			stAM[p] = 1;
			return;
		}
		int m = (l+r)>>1;
		build(p<<1,l,m);
		build((p<<1)+1,m+1,r);
		mer(p<<1,(p<<1)+1,p);
	}
	array<int,3> que(int p, int l, int r, int i, int j){
		if(l > j || r < i){
			return {0,MX,0};
		}
		if(l >= i && r <= j){
			return {stGCD[p],stMN[p],stAM[p]};
		}
		int m = (l+r)>>1;
		array<int,3> x = que(p<<1,l,m,i,j);	
		array<int,3> y = que((p<<1)+1,m+1,r,i,j);	
		x[0] = __gcd(x[0],y[0]);
		if(x[1] > y[1]){
			x[2] = y[2];
			x[1] = y[1];
		}
		else if(x[1] == y[1])x[2]+=y[2];
		return x;
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> v(n);
	for(auto &x : v)cin >> x;
	seg st(v);
	int q; cin >> q;
	while(q--){
		int l, r; cin >> l >> r;
		l--, r--;
		auto x = st.que(1,0,n-1,l,r);
		if(x[0]%x[1] == 0){
			cout << r-l+1-x[2] << '\n';
		}
		else{
			cout << r-l+1 << '\n';
		}

	}
}