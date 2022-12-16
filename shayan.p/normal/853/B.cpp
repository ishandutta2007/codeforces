// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e13;
const ll maxn=1e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

ll arr[maxn];
vector< pair<ll,pll> >es,cm;// day // who // price
ll pes[maxn],pcm[maxn];// price of coming/escaping with flights 0 till i

ll Find(ll x){// Find first greater or equal to x
    if(sz(es)==0)return -1;
    ll l=0,r=sz(es)-1,id=-1;
    while(l<=r){
	ll mid=(l+r)/2;
	if(es[mid].F>=x){
	    id=mid;
	    l=mid+1;
	}
	else{
	    r=mid-1;
	}
    }
    return id;
}

int main(){
    ll n,m,k;cin>>n>>m>>k;
    REP(i,m){
	ll d,f,t,c;cin>>d>>f>>t>>c;
	if(f==0)
	    es.PB(MP(d,MP(t,c)));
	else
	    cm.PB(MP(d,MP(f,c)));
    }
    
    sort(cm.begin(),cm.end());
    fill(arr,arr+maxn,inf);
    ll NUM=inf*n;
    REP(i,sz(cm)){
	ll bef=arr[cm[i].S.F];
	ll aft=min(bef,cm[i].S.S);
	arr[cm[i].S.F]=aft;
	NUM+=aft-bef;
	pcm[i]=NUM;
    }
    
    sort(es.begin(),es.end(),greater<pair<ll,pll> >() );
    fill(arr,arr+maxn,inf);
    NUM=inf*n;
    REP(i,sz(es)){
	ll bef=arr[es[i].S.F];
	ll aft=min(bef,es[i].S.S);
	arr[es[i].S.F]=aft;
	NUM+=aft-bef;
	pes[i]=NUM;
    }

    ll ANS=inf;
    REP(i,sz(cm)){
	ll ind=Find(cm[i].F+k+1);
	if(ind!=-1)
	    ANS=min(ANS,pcm[i]+pes[ind]);
    }
    if(ANS>(2000000*n))
	cout<<-1;
    else
	cout<<ANS;
}