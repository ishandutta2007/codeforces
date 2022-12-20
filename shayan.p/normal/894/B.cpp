#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll mod=1e9+7;
ll pw(ll a,ll b){
	if(b==0)return 1;
	a%=mod;
	return (((b%2)?a:1)*pw((a*a)%mod,b/2))%mod;
}
ll f(ll a,ll b){
	a%=(mod-1);
	b%=(mod-1);
	ll pro=a*b;
	pro%=(mod-1);
	return pw(2,pro);
}
int main()
{
	ll n,m,k;
	cin>>n>>m>>k;
	if(k==1)cout<<f(n-1,m-1);
	else if(k==-1&&(n%2==m%2))cout<<f(n-1,m-1);
	else cout<<0;
}