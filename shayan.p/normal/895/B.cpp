#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll inf=1e12,maxn=1e5+10;
map<ll,ll>mp;
vector<pll> v;
ll ind1,ind2,ans,sum[maxn];
void upper(ll num,ll l=0,ll r=v.size()-1){
	if(l>r)return;
	ll mid=(l+r)/2;
	if(v[mid].F>num){
		ind1=mid;
		upper(num,l,mid-1);
	}
	else upper(num,mid+1,r);
}
void lower(ll num,ll l=0,ll r=v.size()-1){
	if(l>r)return;
	ll mid=(l+r)/2;
	if(v[mid].F<=num){
		ind2=mid;
		lower(num,mid+1,r);
	}
	else lower(num,l,mid-1);
}
int main()
{
	ll n,x,k;cin>>n>>x>>k;
	for(ll i=0;i<n;i++){
		ll a;cin>>a;mp[a]++;
	}
	v.PB(MP(0,0));
	for(map<ll,ll>::iterator it=mp.begin();it!=mp.end();it++)v.PB(*it);
	v.PB(MP(inf,inf));
	sum[0]=0;for(ll i=1;i<v.size();i++)sum[i]=sum[i-1]+v[i].S;
	for(ll i=1;i<v.size()-1;i++){
		ll num=v[i].F,t=v[i].S;
		if(num/x<k)continue;
		ll Min=((num/x)-k)*x;//should be equal or bigger than
		ll Max=Min+x;//should be equal or smaller
		lower(Max);
		upper(Min);
		ind2=min(ind2,i);
		if(ind1>ind2)continue;
//		cout<<ind2<<" "<<ind1<<" "<<sum[ind2]-sum[ind1-1]<<endl;
		ans+=t*(sum[ind2]-sum[ind1-1]);
	}
	cout<<ans;
}