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

const int maxn=2e5+10,mod=1e9+7;

vector<int>v[maxn],pr[maxn];
int a[maxn],sm[maxn],zr[maxn][66],zzr[maxn][66],phi[maxn],inv[maxn],ans;
int ss[maxn],arr[66];
bool pp[maxn],mark[maxn];

int tavan(int a,int b){
    int ans=1;
    while(b){
	if(b&1) ans=1ll*ans*a %mod;
	a=1ll*a*a %mod;
	b/=2;
    }
    return ans;
}

void dfs_add(int u,bool is,int par){
    for(int msk=0;msk<(1<<sz(pr[u]));msk++){
	if(is)
	    sm[zr[u][msk]]+=phi[u];
	else
	    sm[zr[u][msk]]-=phi[u];
	sm[zr[u][msk]]%=mod;
    }
    for(int y:v[u]){
	if(y!=par && !mark[y])
	    dfs_add(y,is,u);
    }
}

void dfs_ans(int u,int H,int par){
    for(int msk=0;msk<(1<<sz(pr[u]));msk++)
	arr[msk]=(__builtin_popcount(msk)&1?-1:1)*sm[zr[u][msk]];
    for(int i=0;i<sz(pr[u]);i++)
	for(int msk=0;msk<(1<<sz(pr[u]));msk++)
	    if(bit(msk,i)==0)
		arr[msk]=(arr[msk]+arr[msk^(1<<i)])%mod;
    int num=1ll*phi[u]*H %mod;
    for(int msk=0;msk<(1<<sz(pr[u]));msk++)
	ans=(1ll*ans+(1ll*(__builtin_popcount(msk)&1?-1:1)*num*arr[msk] %mod *zzr[u][msk])) %mod;
    for(int y:v[u])
	if(y!=par && !mark[y])
	    dfs_ans(y,H+1,u);
}

void dfss(int u,int par=-1){
    ss[u]=1;
    for(int y:v[u]){
	if(y!=par && !mark[y]){
	    dfss(y,u);
	    ss[u]+=ss[y];
	}
    }
}

int center(int u,int N,int par=-1){
    for(int y:v[u]){
	if(y!=par && !mark[y] && ss[y]>N)
	    return center(y,N,u);
    }
    return u;
}

void run(int u){
    dfss(u);
    u=center(u,ss[u]/2);
    mark[u]=1;
    dfs_add(u,1,-1);
    for(int y:v[u]){
	if(!mark[y]){
	    dfs_add(y,0,u);
	    dfs_ans(y,1,u);
	    dfs_add(y,1,u);
	}
    }
    dfs_add(u,0,-1);
    for(int y:v[u])
	if(!mark[y])
	    run(y);
}

void prep(){
    inv[1]=1;
    for(int i=2;i<maxn;i++)
	inv[i]=-1ll*(mod/i)*inv[mod%i]%mod +mod;
    pp[1]=1;
    for(int i=1;i<maxn;i++){
	if(!pp[i])
	    for(int j=i;j<maxn;j+=i)
		pr[j].PB(i),pp[j]=1;
	zr[i][0]=zzr[i][0]=1;
	for(int msk=1;msk<(1<<sz(pr[i]));msk++){
	    int M=msk&-msk,num=pr[i][__builtin_ctz(M)];
	    zr[i][msk]=1ll*zr[i][msk^M]*num %mod;
	    zzr[i][msk]=1ll*zzr[i][msk^M]*num %mod * inv[num-1]%mod;
	}
	phi[i]=1ll*i*tavan(zzr[i][(1<<sz(pr[i]))-1],mod-2) %mod;
    }
}

int main(){ 
    prep();
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
    for(int i=2;i<=n;i++){
	int x,y;scanf("%d%d",&x,&y);
	v[a[x]].PB(a[y]);
	v[a[y]].PB(a[x]);
    }
    run(1);
    ans=2ll*ans*tavan(1ll*n*(n-1)%mod,mod-2)%mod;
    if(ans<0)ans+=mod;
    printf("%d\n",ans);
    return 0;
}