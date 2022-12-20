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
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;
const ll maxn=1e4+10;

ll tree[maxn];
ll	ask(ll ind){
	ll sum=0;
	while(ind>0){
		sum+=tree[ind];
		ind-=(ind & -ind);
	}
	return sum;
}
void add(ll ind,ll num){
	while(ind<=maxn){
		tree[ind]+=num;
		ind+=(ind & -ind);
	}
}

map<pll,ll>mp;//pos val
ll a[maxn],l[maxn],r[maxn],x[maxn];
int main(){
	ll n,m;cin>>n>>m;
	FOR(i,1,n)
		cin>>a[i];
	FOR(i,1,m){
		cin>>l[i]>>r[i]>>x[i];
		mp[MP(l[i]-1,a[x[i]])]=0;
		mp[MP(r[i],a[x[i]])]=0;
	}
	map<pll,ll>mp2=mp;
	ll now=0;
	for(map<pll,ll>::iterator it=mp2.begin();it!=mp2.end();it++){
		while(now<(it->F).F){
			add(a[now+1],1);
			now++;
		}
		mp[it->F]=ask(it->F.S-1);
//		cout<<it->F.F<<" "<<it->F.S<<" "<<mp[it->F]<<endl;
	}
	FOR(i,1,m){
//		cout<<mp[MP(r[i],a[x[i]])]<<" "<<mp[MP(l[i]-1,a[x[i]])]<<endl;
		if(x[i]<l[i]||r[i]<x[i])cout<<"Yes\n";
		else if(mp[MP(r[i],a[x[i]])]-mp[MP(l[i]-1,a[x[i]])]==x[i]-l[i])cout<<"Yes\n";
		else cout<<"No\n";
	}
}