#include<bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
 
using namespace std;

const int MAX = 2e5+5;
int n,m,x[MAX],a,le,ri,res;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i = 0; i<n; ++i){
		cin>>a;
		x[a]^= 262143;
	}
	cin>>m;
	while(m--){
		cin>>le>>ri;
		res = 0;
		++ri;
		for(int i = le; i<ri; ++i) res^= x[i]&(i-le);
		cout<<"AB"[res==0];
	}
	return 0;
}