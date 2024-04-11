#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll maxn=1e6+10,mod=1e9+7;
ll two[maxn],ans[maxn],num[maxn],Ans;
int main()
{
	two[0]=1;for(ll i=1;i<maxn;i++)two[i]=(two[i-1]*2)%mod;
	ll n;cin>>n;
	for(ll x,i=0;i<n;i++){cin>>x;num[x]++;}
	for(ll i=2;i<maxn;i++)for(ll j=i+i;j<maxn;j+=i)	{num[i]+=num[j];num[i]%=mod;}
		for(ll i=maxn-6;i>1;i--)
		{
			ans[i]=num[i]*two[num[i]-1];ans[i]%=mod;
			for(ll j=i+i;j<maxn;j+=i){ans[i]-=ans[j];ans[i]%=mod;}
			Ans=(Ans+ans[i]*i)%mod;
		}
		cout<<(Ans+mod)%mod;
}