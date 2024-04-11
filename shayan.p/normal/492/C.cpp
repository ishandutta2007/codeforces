#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define F first
#define S second
using namespace std;
const ll maxn=1e5+10;
pll p[maxn];
int main(){
	ll n,r,avg,sum=0;cin>>n>>r>>avg;
	for(ll i=0;i<n;i++){
		cin>>p[i].S>>p[i].F;//a b
		sum+=p[i].S;
	}
	sort(p,p+n);
	ll need=(avg*n)-sum,h=0,ans=0;
	while(need>0){
		ll M=min(need,r-p[h].S);
		ans+=M*p[h].F;
		need-=M;
		h++;
	}
	cout<<ans;
}