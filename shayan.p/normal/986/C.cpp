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
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=5e6+10;

#pragma GCC Optimize("Ofast")

ll n,m,S;
bool vis[2*maxn],is[maxn];
ll a[maxn],arr[2*maxn],vec[30],SZV;

void build_near(ll x){
    SZV=0;
    if(x<S){
	vec[SZV++]=S+S-1-x;
	REP(i,n){
	    if(!bit(x,i))
		vec[SZV++]=(x|(1<<i));
	}
    }
    else{
	vec[SZV++]=x-S;
    }
}

void dfs(ll u){
    ll SZ=1;
    arr[0]=u;
    while(SZ){
	ll t=arr[--SZ];
	if(t>=S && !is[t-S]) continue;
	build_near(t);
	REP(i,SZV){
	    if(!vis[vec[i]]){
		vis[vec[i]]=1;
		arr[SZ++]=vec[i];
	    }
	}
    }
}

int main(){
    cin>>n>>m;
    S=(1<<n);
    REP(i,m){
	cin>>a[i];
	is[a[i]]=1;
    }
    ll ans=0;
    REP(i,m){
	if(!vis[a[i]+S]){
	    ans++;
	    dfs(a[i]+S);
	}
    }
    cout<<ans;
}