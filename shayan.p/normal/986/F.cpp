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

const int maxn=1e5+10,MAX=35e6;
const ll inf=2e18;

map<ll,vector<pair<ll,int> > >mp;
vector<ll>vec,prm;

ll dp[maxn];
bool ans[maxn],pp[MAX];

void prep(ll n){
    vec.clear();
    for(int p:prm){
	if(n%p==0){
	    while(n%p==0)
		n/=p;
	    vec.PB(p);
	}
    }
    if(n>1)
	vec.PB(n);
    if(sz(vec)<3)return;
    fill(dp,dp+maxn,inf);
    dp[0]=0;
    for(int i=1;i<sz(vec);i++){
	int num=vec[i]%vec[0];
	int g=__gcd(vec[i],vec[0]),SZ=vec[0]/g;
	for(int rm=0;rm<g;rm++){
	    int id=rm;
	    for(int k=0,nw=rm;k<SZ;nw=(nw+num)%vec[0],k++)
		if(dp[id]>dp[nw]) id=nw;
	    for(int k=0,nw=id;k<SZ;nw=(nw+num)%vec[0],k++)
		dp[(nw+num)%vec[0]]=min(dp[(nw+num)%vec[0]],dp[nw]+vec[i]);
	}
    }
}

ll tavan(ll a,ll b,ll md){
    a%=md;
    ll ans=1;
    while(b){
	if(b&1) ans=ans*a %md;
	a=a*a %md;
	b>>=1;
    }
    return ans;
}

int main(){
    for(int i=2;i<MAX;i++){
	if(!pp[i]){
	    prm.PB(i);
	    for(int j=min(1ll*i*i,ll(MAX));j<MAX;j+=i)
		pp[j]=1;
	}
    }
    int t;scanf("%d",&t);
    for(int tsk=0;tsk<t;tsk++){
	ll a,b;scanf("%lld%lld",&a,&b);
	mp[b].PB({a,tsk});
    }
    for(auto it:mp){
	if(it.F==1)continue;
	prep(it.F);
	if(sz(vec)>=3){
	    for(auto p:it.S)
		ans[p.S]= dp[p.F%vec[0]]<=p.F;
	}
	if(sz(vec)==2){
	    for(auto p:it.S)
		ans[p.S]= ((p.F%vec[0])*tavan(vec[1],vec[0]-2,vec[0]) %vec[0])*vec[1] <=p.F;
	}
	if(sz(vec)==1){
	    for(auto p:it.S)
		ans[p.S]= p.F%vec[0]==0;
	}
    }
    for(int tsk=0;tsk<t;tsk++)
	printf(ans[tsk]?"YES\n":"NO\n");
}