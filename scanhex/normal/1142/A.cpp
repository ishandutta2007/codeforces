#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())
nagai n,k;
nagai a,b;

nagai gcd(nagai a,nagai b){
	 while(b){
		  a%=b;
		  swap(a,b);
	 }
	 return a;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	cin>>a>>b;
	nagai mn=n*k+1,mx=-1;
	nagai kek=(b-a+n*k)%k;
	nagai mem=(kek+k-2*b+k)%k;
	for(nagai i=0;i<=n*k;i+=k){
		for(nagai l:{i+kek,i+mem}){
//			if(min(kek,k-kek)==b){
			if(l==0)continue;
//			cerr<<l<<'\n';
				nagai ans=n*k/gcd(l,n*k);
				mn=min(mn,ans);
				mx=max(mx,ans);
			}
	}
	cout<<mn<<' '<<mx<<'\n';
	return 0;
}