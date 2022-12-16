#include<bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ll long long
using namespace std;
const ll maxn=3e5+10;
ll n,ans[maxn];
bool mark[maxn];
int main()
{
	cin>>n;
	ll last=n;
	for(ll i=1;i<=n;i++)
	{
		ll x;cin>>x;mark[x]=1;
		while(mark[last])last--;//avalini ke nadare
		ans[i]=i-(n-last)+1;
	}
	ans[0]=1;
	for(ll i=0;i<=n;i++)cout<<ans[i]<<" ";
}