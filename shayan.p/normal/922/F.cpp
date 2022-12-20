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
const ll maxn=3e5+10;

#pragma GCC Optimize("Ofast")

ll d[maxn];
bool no[maxn];

int main(){
	ll n,k,tot=0;cin>>n>>k;
	for(ll i=1;i<=n;i++){
		for(ll j=2*i;j<=n;j+=i){
			d[j]++;tot++;
		}
	}
	if(k>tot){
		cout<<"No";
		return 0;
	}
	if(k==3){
		cout<<"Yes\n";
		cout<<3<<endl<<1<<" "<<2<<" "<<4;
		return 0;
	}
	if(k==6){
		cout<<"Yes\n";
		cout<<5<<endl<<1<<" "<<2<<" "<<4<<" "<<5<<" "<<6;
		return 0;
	}
	while((tot-d[n])>=k){
		tot-=d[n--];
	}
	vector<pll>v;v.clear();
	ll i=n;
	while(i>(n/2)){
		v.PB(MP(d[i],i));
		i--;
	}
	sort(v.begin(),v.end(),greater<pll>());
	i=0;
	tot=tot-k;
	while(tot>0&&i<sz(v)){
		if(v[i].F<=tot){
			tot-=v[i].F;
			no[v[i].S]=1;
		}
		i++;
	}
	ll SZ=0;
	cout<<"Yes\n";
	FOR(i,1,n)
		if(!no[i])
			SZ++;
	cout<<SZ<<endl;
	FOR(i,1,n)
		if(!no[i])
			cout<<i<<" ";
}