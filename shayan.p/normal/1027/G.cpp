// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll Base=1e4;

map<ll,vector<pair<ll,int> > >mp;
vector<pair<ll,int> >vec,vec2,vec3;
ll ans,m,x;

inline void Zarb(ll &a,ll b,ll c){
    ll A=a*(b%Base);
    b/=Base;
    ll B=a*(b%Base) %c *Base;
    b/=Base;
    ll C=a*(b%Base) %c *Base %c *Base;
    b/=Base;
    ll D=a*(b%Base) %c *Base %c *Base %c *Base;
    b/=Base;
    ll E=a*(b%Base) %c *Base %c *Base %c *Base %c *Base;
    a=(A+B+C+D+E)%c;
}

ll tavan(ll a,ll b,ll md){// hame ta 10^14 hastan
    ll ans=1;
    while(b){
	if(b&1) Zarb(ans,a,md);
	Zarb(a,a,md);
	b/=2;
    }
    return ans;
}

// O lg^2 mitoonim tajzie konim baadesh O lg^2 Ord ro hesab konim

void go(int nw=0,ll num=1){
    if(nw==sz(vec)){
	ll Phi=num,Ord=0,w=1;
	vec2.clear();
	vec3.clear();
	for(int i=0;i<sz(vec);i++){
	    if(vec[i].S==0)continue;
	    if(vec[i].S>1)
	        vec2.PB({vec[i].F,vec[i].S-1});
	    Phi/=vec[i].F;
	    for(auto PP:mp[vec[i].F-1])
		vec2.PB(PP);
	    w*=vec[i].F-1;
	}
	Phi*=w;
	Ord=Phi;
	sort(vec2.begin(),vec2.end());
	for(int i=0;i<sz(vec2);i++){
	    if(i+1==sz(vec2) || vec2[i].F!=vec2[i+1].F)
		vec3.PB(vec2[i]);
	    else
		vec2[i+1].S+=vec2[i].S;
	}
	for(auto PP:vec3){
	    while(PP.S && tavan(x,Ord,num)==1)
		PP.S--,Ord/=PP.F;
	    if(tavan(x,Ord,num)!=1)
		Ord*=PP.F;
	}
	ans+=Phi/Ord;
	return;
    }
    int N=vec[nw].S;
    for(int i=0;i<=N;i++){
	vec[nw].S=i;
	go(nw+1,num);
	num*=vec[nw].F;
    }
    vec[nw].S=N;
}

void tajzie(ll x,vector<pair<ll,int> >&vec){
    for(ll p=2;(p*p)<=x;p++){
	if(x%p==0){
	    int cnt=0;
	    while(x%p==0)
		x/=p,cnt++;
	    vec.PB({p,cnt});
	}
    }
    if(x>1)
	vec.PB({x,1});
}

int main(){
    cin>>m>>x;
    tajzie(m,vec);		       
    for(auto PP:vec)
	tajzie(PP.F-1,mp[PP.F-1]);
    go();
    cout<<ans<<endl;
    return 0;
}