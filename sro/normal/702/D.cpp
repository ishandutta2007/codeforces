#include <bits/stdc++.h>
using namespace std;

long long d,k,a,b,t;

int main(){
	cin>>d>>k>>a>>b>>t;
	if(k>=d){
		cout<<a*d<<endl;
	}else{
		long long ans=a*k;
		d-=k;
		long long tm=min(a*k+t,b*k);
		ans+=d/k*tm;
		d%=k;
		ans+=min(a*d+t,b*d);
		cout<<ans<<endl;
	}
	return 0;
}