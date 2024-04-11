#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll calc(ll n,ll b){
	ll ans=0;
	while(n)ans+=n/=b;
	return ans;
}

int main(){
	ll n,b,ans=1ll<<60;
	cin>>n>>b;
	for(ll i=2;i*i<=b;i++)
		if(b%i==0){
			int k=0;
			while(b%i==0)b/=i,k++;
			ans=min(ans,calc(n,i)/k);
		}
	if(b>1)ans=min(ans,calc(n,b));
	if(ans==(1ll<<60))ans=0;
	cout<<ans<<endl;
	return 0;
}