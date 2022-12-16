#include<bits/stdc++.h>
#define ll long long
#define PB push_back
#define MP make_pair
#define F first
#define S second
const ll maxn=400;
bool on[4*maxn];
ll light[4*maxn];
ll hf(ll num){return num+maxn;}
using namespace std;
int main()
{
	ll ans=0,m,t,r;cin>>m>>t>>r;ll g[m];for(ll i=0;i<m;i++) cin>>g[i];
	sort(g,g+m);
	for(ll i=0;i<m;i++)
	{
		ll mom=hf(g[i]);
		for(ll j=1;light[mom]<r&&j<=t;j++)
		if(!on[mom-j]) {on[mom-j]=1;ans++;for(ll k=1;k<=t;k++) light[mom-j+k]++;}
		if(light[mom]<r) {cout<<-1;return 0;}
	}
	cout<<ans;
}