#include <bits/stdc++.h>
using namespace std;

long long a,b,n,x;
const int jt=1000000007;

inline pair<long long,long long> mii(long long x){
	if(!x){
		return make_pair(1,0);
	}
	pair<long long,long long> v=mii(x>>1);
	v=make_pair(v.first*v.first%jt,(v.first*v.second+v.second)%jt);
	if(x&1){
		v=make_pair(a*v.first%jt,(a*v.second+b)%jt);
	}
	return v;
}

int main(){
	cin>>a>>b>>n>>x;
	pair<long long,long long> f=mii(n);
	cout<<(f.first*x+f.second)%jt<<endl;
	return 0;
}