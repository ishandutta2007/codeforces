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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;
const ll mod=1e9+7;
const ll maxn=1e5+10;


ll lazy[4*maxn],val[4*maxn];
void get(ll l,ll r,ll ind){
	val[ind]+=lazy[ind];
	if(l!=r){
		lazy[2*ind]+=lazy[ind];
		lazy[2*ind+1]+=lazy[ind];
	}
	lazy[ind]=0;
}
ll ask(){
	get(1,maxn,1);
	return val[1];
}
void add(ll targl,ll targr,ll value,ll ind=1,ll l=1,ll r=maxn){
	if(l>r)return;
	get(l,r,ind);
	if(targr<l||r<targl)return;
	if(targl<=l&&r<=targr){
		lazy[ind]+=value;
		get(l,r,ind);
		return;
	}
	ll mid=(l+r)/2;
	add(targl,targr,value,2*ind,l,mid);
	add(targl,targr,value,2*ind+1,mid+1,r);
	val[ind]=min(val[2*ind],val[2*ind+1]);
}
void build(ll l=1,ll r=maxn,ll ind=1){
	if(l==r){
		val[ind]=l;
		return;
	}
	ll mid=(l+r)/2;
	build(l,mid,2*ind);
	build(mid+1,r,2*ind+1);
	val[ind]=min(val[2*ind],val[2*ind+1]);
}

ll last[maxn],d[maxn],a[maxn];

int main(){
	build();
	ll n,m;cin>>n>>m;
	FOR(i,1,n)
		cin>>d[i];
	FOR(i,1,m)
		cin>>a[i];
	ll seen=0;
	FOR(i,1,n){
		if(d[i]==0)
			continue;
		if(last[d[i]]==0){
			seen++;
			last[d[i]]=i;
			add(i,maxn,-(a[d[i]]+1));
		}
		else{
			add(last[d[i]],maxn,(a[d[i]]+1));
			last[d[i]]=i;
			add(i,maxn,-(a[d[i]]+1));
		}
		if(seen==m){
			if(ask()>=0){
				cout<<i;
				return 0;
			}
		}
	}
	cout<<-1;
}