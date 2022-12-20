// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define qqq(a) cerr<<"error "<<a<<endl;
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll maxn=2e5+10,mod=1e9+7;

pll p[maxn];

struct Fenwick{
    ll sm[maxn];
    
    void add(int ind,ll x,bool is){
	if(is)
	    x%=mod;
	while(ind<maxn){
	    sm[ind]+=x;
	    if(is)
		sm[ind]%=mod;
	    ind+=(ind & -ind);
	}
    }
    ll ask(int ind,bool is){
	ll ans=0;
	while(ind>0){
	    ans+=sm[ind];
	    if(is)
		ans%=mod;
	    ind-=(ind & -ind);
	}
	return ans;
    }
};
Fenwick fen1,fen2;

int main(){
    int n,q;scanf("%d%d",&n,&q);
    FOR(i,1,n){
	scanf("%lld",&p[i].F);
	p[i].F-=i;
    }
    FOR(i,1,n){
	scanf("%lld",&p[i].S);
    }
    FOR(i,1,n){
	fen1.add(i,p[i].F*p[i].S,1);
	fen2.add(i,p[i].S,0);
    }
    
    while(q--){
	ll a,b;scanf("%lld%lld",&a,&b);
	if(a<0){
	    a=-a;
	    fen1.add(a,-p[a].F*p[a].S,1);
	    fen2.add(a,-p[a].S,0);
	    p[a].S=b;
	    fen1.add(a,p[a].F*p[a].S,1);
	    fen2.add(a,p[a].S,0);
	}
	else{
	    ll bf=fen2.ask(a-1,0);
	    ll tot=fen2.ask(b,0)-bf;
	    ll l=a,r=b,ans=-1;
	    while(l<=r){
		int mid=(l+r)/2;
		if((2*(fen2.ask(mid,0)-bf))>=tot){
		    ans=mid;
		    r=mid-1;
		}
		else{
		    l=mid+1;
		}
	    }
	    ll BF=fen1.ask(a-1,1);
	    ll ANS=(p[ans].F*((2*(fen2.ask(ans,0)-bf)-tot)%mod)-2*(fen1.ask(ans,1)-BF)+(fen1.ask(b,1)-BF))%mod;
	    if(ANS<0)ANS+=mod;
	    printf("%lld\n",ANS);
	}
    }
}