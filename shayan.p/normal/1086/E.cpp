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

const int maxn=2010,mod=998244353;
const ll inf=1e18;

int fac[maxn],dp[maxn][maxn],bef[maxn],a[maxn],pos[maxn],n;

int Pow(int a,int b){
    int ans=1;
    while(b){
	if(b&1) ans=1ll*ans*a %mod;
	a=1ll*a*a %mod;
	b>>=1;
    }
    return ans;
}

struct fenwick{
    int fn[maxn];
    void clear(){
	memset(fn,0,sizeof fn);
    }
    void add(int id,int x){
	while(id<maxn)
	    fn[id]+=x,id+=(id & -id);
    }
    int ask(int id){
	int ans=0;
	while(id>0)
	    ans+=fn[id],id-=(id & -id);
	return ans;
    }
    
    int Pow(int a,int b){
	int ans=1;
	while(b){
	    if(b&1) ans=1ll*ans*a %mod;
	    a=1ll*a*a %mod;
	    b>>=1;
	}
	return ans;
    }
};fenwick fn1,fn2;

set<int>st1,st2;

int calc(bool is=0){
    fn1.clear();fn2.clear();;st1.clear();st2.clear();
    int ans=0;
    if(is){
	for(int i=1;i<=n;i++){
	    cin>>bef[i];
	    fn1.add(bef[i],1);
	    int x=bef[i]-fn1.ask(bef[i]);
	    ans=(1ll*ans+1ll*x*fac[n-i])%mod;
	}
	return ans;
    }
    for(int i=1;i<=n;i++){
	cin>>a[i];
	pos[bef[i]]=i;
    }
    for(int i=1;i<=n;i++){
	int fr=fn1.ask(n),nfr=!st2.count(bef[i]);
	fn2.add(a[i],1);
	if(fr>0) ans=(1ll*ans+1ll*dp[n-i][n-i-fr-nfr+1]*fn1.ask(a[i]-1))%mod;
	ans=(1ll*ans+1ll*dp[n-i][n-i-fr-nfr]*(a[i]-fn2.ask(a[i])-fn1.ask(a[i]-1)-(nfr && bef[i]<a[i])))%mod;	
	fn1.add(bef[i],1);
	st2.insert(a[i]);
	if(st1.count(a[i]))
	    fn1.add(a[i],-1);
	st1.insert(bef[i]);
	if(st2.count(bef[i]))
	    fn1.add(bef[i],-1);
	bef[i]=a[i];
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    fac[0]=1;
    for(int i=1;i<maxn;i++){
	fac[i]=1ll*i*fac[i-1] %mod;
    }
    for(int i=0;i<maxn;i++){
	dp[i][0]=fac[i];
	for(int j=1;j<=i;j++)
	    dp[i][j]=(dp[i][j-1]-dp[i-1][j-1])%mod;
    }
    int ans=0;cin>>n;
    for(int i=1;i<=n;i++)
	ans=(1ll*ans+1ll*calc(i==1)*Pow(dp[n][n],n-i))%mod;
    if(ans<0) ans+=mod;
    cout<<ans<<endl;
    return 0;
}