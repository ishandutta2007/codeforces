// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

ll a[maxn],f[maxn],val[maxn],dg[maxn];
set<pll>s[maxn];// val // who
set<pll>tot;

inline void Add(ll x){
    if(s[x].empty())return;
    ll delta=a[x]/dg[x];
    pll p1=*s[x].begin(),p2=*s[x].rbegin();
    tot.insert(MP(p1.F+delta,p1.S));
    tot.insert(MP(p2.F+delta,p2.S));
}
inline void Erase(ll x){
    if(s[x].empty())return;
    ll delta=a[x]/dg[x];
    pll p1=*s[x].begin(),p2=*s[x].rbegin();
    tot.erase(MP(p1.F+delta,p1.S));
    tot.erase(MP(p2.F+delta,p2.S));
}
inline void Modify(ll x,ll y){
    s[f[x]].erase(MP(val[x],x));
    val[x]=y;
    s[f[x]].insert(MP(val[x],x));
}
inline ll calc(ll x,ll d){
    return x-((d-1)*(x/d));
}

int main(){
    ll n,q;cin>>n>>q;
    REP(i,n){
	cin>>a[i];
	dg[i]=1;
    }
    REP(i,n){
	cin>>f[i];
	f[i]--;
	dg[i]++;
	dg[f[i]]++;
    }
    REP(i,n){
	val[i]+=calc(a[i],dg[i]);
	val[f[i]]+=a[i]/dg[i];
    }
    REP(i,n){
	s[f[i]].insert(MP(val[i],i));
    }
    REP(i,n){
	if(s[i].empty())continue;
	ll delta=a[i]/dg[i];
	pll p1=*s[i].begin(),p2=*s[i].rbegin();
	tot.insert(MP(p1.F+delta,p1.S));
	tot.insert(MP(p2.F+delta,p2.S));
    }

    while(q--){
	ll task,x,y;cin>>task;
	if(task==1){
	    cin>>x>>y;
	    x--;y--;
	    
	    Erase(x);
	    Erase(y);
	    Erase(f[y]);
	    Erase(f[x]);
	    Erase(f[f[x]]);
	    Erase(f[f[y]]);
	    Erase(f[f[f[x]]]);

	    Modify(y,val[y]+(a[x]/dg[x])+calc(a[y],dg[y]+1)-calc(a[y],dg[y]));
	    Modify(f[y],val[f[y]]+(a[y]/(dg[y]+1))-(a[y]/dg[y]));
	    Modify(f[x],val[f[x]]-(a[x]/(dg[x]))+calc(a[f[x]],dg[f[x]]-1)-calc(a[f[x]],dg[f[x]]));
	    Modify(f[f[x]],val[f[f[x]]]+(a[f[x]]/(dg[f[x]]-1))-(a[f[x]]/dg[f[x]]));

	    dg[f[x]]--;
	    dg[y]++;

	    s[f[x]].erase(MP(val[x],x));
	    s[y].insert(MP(val[x],x));
	    
	    Add(x);
	    Add(y);
	    Add(f[y]);
	    Add(f[x]);
	    Add(f[f[x]]);
	    Add(f[f[y]]);
	    Add(f[f[f[x]]]);

	    f[x]=y;
	}
	if(task==2){
	    cin>>x;
	    x--;
	    cout<<val[x]+(a[f[x]]/dg[f[x]])<<endl;
	}
	if(task==3){
	    cout<<(tot.begin()->F)<<" "<<(tot.rbegin()->F)<<endl;
	}
    }
}