#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
vector<ll>p;
const ll maxn=(1<<20)+10,mod=1e9+7;
ll dp[3][maxn],change[80],num[80],tw[maxn];
bool prime(ll num){
	for(ll i=2;i<num;i++)if(num%i==0)return 0;
	return 1;
}
ll tajzie(ll num){
	ll two=1;
	ll ans=0;
	for(ll i=0;i<p.size();i++){
		ll t=0;
		while(num%p[i]==0){
			num/=p[i];
			t++;
		}
		t=t%2;
		ans+=t*two;
		two*=2;
	}
	return ans;
}
int main()
{
	for(ll i=2;i<=70;i++)if(prime(i))p.PB(i);
	for(ll i=1;i<=70;i++)change[i]=tajzie(i);
	tw[0]=1;for(ll i=1;i<=maxn;i++)tw[i]=(tw[i-1]*2)%mod;
	ll n;cin>>n;
	for(ll i=0;i<n;i++){
		ll x;cin>>x;
		num[x]++;
	}
	ll now=0,bef=1;
	for(ll i=1;i<=70;i++){
		ll I=change[i];
		swap(now,bef);
		if(num[i]==0){
			swap(now,bef);
			continue;
		}
		for(ll j=0;j<maxn;j++)dp[now][j]=0;
		dp[now][I]+=tw[num[i]-1];
		dp[now][0]+=(tw[num[i]-1]-1+mod)%mod;
		for(ll j=0;j<maxn;j++){
			dp[now][j]+=dp[bef][j]*tw[num[i]-1];
			dp[now][j]%=mod;
			dp[now][j]+=dp[bef][I xor j]*tw[num[i]-1];
			dp[now][j]%=mod;
		}
	}
	cout<<dp[now][0];
}