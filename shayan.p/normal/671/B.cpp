// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=5e5+30;
const ll mod=1e9+7;
const ll Big=1e9+10;

#pragma GCC Optimize("Ofast")

ll a[maxn],n,k,sm;
map<ll,ll>mp;
vector<ll>v,vs,vc;
ll mx,mn;

ll h=1;
ll dn,up;

ll Cnt_Min(ll val){
	ll l=0,r=sz(v)-1,ind=-1;
	while(l<=r){
		ll mid=(l+r)/2;
		if(v[mid]<val){
			ind=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	
	if(ind==-1)return 0;
	return (val*vc[ind])-(vs[ind]);
}

ll Cnt_Max(ll val){
	ll l=0,r=sz(v)-1,ind=-1;/////////
	while(l<=r){
		ll mid=(l+r)/2;
		if(v[mid]<=val){
			ind=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	if(ind==-1)return -1;
	return (sm-vs[ind])-(val*(n-vc[ind]));
}

ll calc_min(){
	ll l=mn,r=dn,ans=l;
	if(l==r)
		return ans;
	while(l<=r){
		ll mid=(l+r)/2;
		ll num=Cnt_Min(mid);
//		cout<<mid<<" "<<num<<endl;
		if(num!=-1&&num<=k){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
//		cout<<ans<<" "<<l<<" "<<r<<endl;
	}
	return ans;
}
ll calc_max(){
	ll l=up,r=mx,ans=l;
	if(l==r)
		return ans;
	while(l<=r){
		ll mid=(l+r)/2;
		ll num=Cnt_Max(mid);
//		cout<<mid<<" "<<num<<endl;
		if(num!=-1&&num<=k){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
//		cout<<"lr "<<l<<" "<<r<<endl;
	}
	return ans;
}

int main(){
	cin>>n>>k;
	mx=-inf;
	mn=inf;
	REP(i,n){
		ll x;scanf("%lld",&x);
		mn=min(mn,x);
		mx=max(mx,x);
		sm+=x;
		mp[x]++;
	}
	dn=sm/n;up=(sm/n)+(sm%n!=0);
	
	for(map<ll,ll>::iterator it=mp.begin();it!=mp.end();it++){
		v.PB(it->F);
		if(sz(v)!=1){
			vc.PB(vc.back()+(it->S));
			vs.PB(vs.back()+((it->S)*(it->F)));
		}
		else{
			vc.PB(it->S);
			vs.PB((it->S)*(it->F));
		}
	}
	
	cout<<calc_max()-calc_min();
}