// Phoenix

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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int a[maxn],b[maxn],n,m,phin,phim;
map<int,pair<vector<int>,vector<int> > >mp;
bool is[maxn];
vector<pair<int,pair<int,bool> > >vec,vv;

int phi(int x){
    int ans=x;
    for(int i=2;(1ll*i*i)<=x;i++){
	if(x%i==0){
	    while(x%i==0)
		x/=i;
	    ans/=i;
	    ans*=(i-1);
	}
    }
    if(x>1)
	ans/=x,ans*=x-1;
    return ans;
}

int Pow(int a,int b,int md){
    int ans=1;
    while(b){
	if(b&1) ans=1ll*ans*a %md;
	a=1ll*a*a %md;
	b>>=1;
    }
    return ans;
}

ll solve2(int n,int m){
    ll ans=0;
    sort(vec.begin(),vec.end());
    vv.clear();
    for(int i=0;i<sz(vec);i++){
	if(i==0 || vec[i].F!=vec[i-1].F)
	    vv.PB(vec[i]);
    }
    vec=vv;
    int st=0;
    for(int i=0;i<sz(vec);i++){
	if(vec[i].S.F<vec[st].S.F)
	    st=i;
    }
    ll ds=vec[st].S.F;
    for(int i=0;i<sz(vec);i++){
	auto NW=vec[(i+st)%sz(vec)],NXT=vec[(i+st+1)%sz(vec)];
	if(NW.S.S==0 && (NW.F+1)%n==NXT.F){
	    ds=min(ds,ll(NW.S.F))+m;
	}
	else{
	    ds=min(ds,ll(NW.S.F))+1ll*m*((NXT.F-NW.F-1+n)%n);
	    ans=max(ans,ds);
	    ds+=m;
	}
    }
    return ans;
}

ll solve(vector<int>&v1,vector<int>&v2){
    int cof1=Pow(m,phin-1,n),cof2=Pow(n,phim-1,m);
    vec.clear();
    for(int i=0;i<sz(v1);i++)
	vec.PB({1ll*v1[i]*cof1%n,{v1[i],0}});
    for(int i=0;i<sz(v2);i++)
	vec.PB({1ll*v2[i]*cof1%n,{v2[i],1}});
    ll ans=solve2(n,m);
    vec.clear();
    for(int i=0;i<sz(v1);i++)
	vec.PB({1ll*v1[i]*cof2%m,{v1[i],1}});
    for(int i=0;i<sz(v2);i++)
	vec.PB({1ll*v2[i]*cof2%m,{v2[i],0}});
    ans=max(ans,solve2(m,n));
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    cin>>n>>m;
    phin=phi(n);
    phim=phi(m);
    int A;cin>>A;
    for(int i=0;i<A;i++)
	cin>>a[i];
    int B;cin>>B;
    for(int i=0;i<B;i++)
	cin>>b[i];
    int g=__gcd(n,m);
    for(int i=0;i<A;i++)
	mp[a[i]%g].F.PB(a[i]/g);
    for(int i=0;i<B;i++)
	mp[b[i]%g].S.PB(b[i]/g);

    if(sz(mp)<g)
	return cout<<-1<<endl,0;
    
    n/=g;m/=g;
    ll ans=0;
    for(auto it:mp){
	if(sz(it.S.F)==n && sz(it.S.S)==m) continue;
	ll num=solve(it.S.F,it.S.S);
	if(num==-1)
	    return cout<<-1<<endl,0;
	num=num*g+it.F;
	ans=max(ans,num);
    }
    cout<<ans<<endl;
    return 0;
}