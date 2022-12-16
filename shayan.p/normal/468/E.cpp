// High above the clouds there is a rainbow...

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

const int maxn=1e5+10,Max=55,MASK=(1<<18),mod=1e9+7;
const ll inf=1e18;

vector<pii> v[2*maxn],g[2*Max], gg[2*Max];
bool mark[2*maxn];

int who[2*maxn],C1,C2;

int a[Max],b[Max],c[Max],n;

int adj[Max][Max];

int val[Max],tmp[Max],tmp2[Max],fac[maxn];

void add(int &x,ll y){
    x=(y+x)%mod;
}

void dfs(int u){
    if(u<n) who[u]=C1++;
    else    who[u]=C2++;
    mark[u]=1;
    
    for(pii p:v[u]){
	int y=p.F;
	if(!mark[y]) dfs(y);
	if(u<n) g[who[u]].PB({who[y]+Max,p.S});
	else    g[Max+who[u]].PB({who[y],p.S});
    }
}

int Dp[MASK],dp[2*Max][Max][2],SZ[2*Max];
bool in[2*Max],mrk[2*Max];
vector<pair<pii,int> >vec;

void dfs2(int u,int par=-1){// initialize to 0?
    mrk[u]=1;
    for(pii p:g[u]){
	if(p.F==par) continue;
	if(!mrk[p.F])  dfs2(p.F,u), gg[u].PB(p);
	else if(u<Max) vec.PB({{u,p.F},p.S});
    }
}

int arr0[Max],arr1[Max];

void dfs3(int u){
    memset(dp[u],0,sizeof dp[u]);
    SZ[u]=1;
    
    dp[u][0][0]=dp[u][0][1]=1;
    
    for(pii p:gg[u]){
	int y=p.F;
	dfs3(y);

	for(int i=0;i<SZ[u]+SZ[y]+2;i++){
	    arr0[i]=arr1[i]=0;
	}
	
	for(int i=0;i<=SZ[u];i++){
	    for(int j=0;j<= SZ[y] ;j++){
		add( arr0[i+j+1], 1ll* dp[u][i][1]* dp[y][j][1] %mod *p.S);
		add( arr0[i+j], 1ll* (dp[u][i][0]-dp[u][i][1])* dp[y][j][0] );
		add( arr1[i+j], 1ll* dp[u][i][1]* dp[y][j][0] );
	    }
	}
	SZ[u]+=SZ[y];
	
	for(int i=0;i<=SZ[u];i++){
	    dp[u][i][0]=(arr0[i]+arr1[i])%mod;
	    dp[u][i][1]=arr1[i];
	}
    }
    if(in[u]){
	dp[u][0][1]=0;
	for(int i=1;i<Max;i++){
	    dp[u][i][0]=dp[u][i][1];
	    dp[u][i][1]=0;
	}
    }
}

int prep(int msk){
    int cof=1;
    for(int i=0;i<sz(vec);i++){
	if(bit(msk,i)){
	    if(in[vec[i].F.F] || in[vec[i].F.S]) return 0;
	    in[vec[i].F.F]=1, in[vec[i].F.S]=1, cof=1ll*cof*vec[i].S %mod;
	}
    }
    return cof;
}

void solve(int C1,int C2){
    if(C1+C2<2) return;
				
    memset(tmp,0,sizeof tmp);
    memset(tmp2,0,sizeof tmp2);
    
    if(C1+C2<=36){
	memset(Dp,0,sizeof Dp);
	Dp[0]=1;
       
	if(C1<=C2){
	    for(int i=Max;i<Max+C2;i++)
		for(int msk=(1<<C1)-1;msk>=0;msk--)
		    for(pii p:g[i])
			if(bit(msk,p.F))
			    add(Dp[msk], 1ll* p.S * Dp[msk ^ (1<<p.F)] );
	}
	else{
	    for(int i=0;i<C1;i++)
		for(int msk=(1<<C2)-1;msk>=0;msk--)
		    for(pii p:g[i])
			if(bit(msk,p.F-Max))
			    add(Dp[msk], 1ll* p.S * Dp[msk ^ (1<<(p.F-Max))] );
	}
	for(int msk=0; msk< (1<< (min(C1,C2)) ); msk++)
	    add(tmp[__builtin_popcount(msk)], Dp[msk]);
    }
    else{// Just one use
	dfs2(0);
	for(int msk=0;msk<(1<<sz(vec));msk++){
	    memset(in,0,sizeof in);
	    int cof=prep(msk);
	    dfs3(0);
	   
	    int CNT=__builtin_popcount(msk);
	    
	    for(int i=CNT;i<= ((C1+C2)/2); i++)
		add(tmp[i], 1ll* cof * dp[0][i-CNT][0]);
	}
    }

    for(int i=0;i<Max;i++){
	if(val[i]==0) continue;
	for(int j=0;j<Max;j++){
	    if(tmp[j]==0) continue;
	    add(tmp2[i+j], 1ll*val[i]*tmp[j]);
	}
    }
    memcpy(val,tmp2,sizeof val);
}

bool IS[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    int k; cin>>n>>k;

    for(int i=0;i<k;i++){
	cin>>a[i]>>b[i]>>c[i]; --a[i], --b[i], --c[i];
	v[a[i]].PB({b[i]+n,c[i]});
	v[b[i]+n].PB({a[i],c[i]});
	IS[a[i]]=1;
    }

    val[0]=1;
    
    for(int i=0;i<n;i++){
	if(!IS[i] || mark[i]) continue;
	for(int j=0;j<2*Max;j++){
	    g[j].clear();
	}
	C1=C2=0;
	dfs(i);
	solve(C1,C2);
    }
    
    fac[0]=1;
    for(int i=1;i<maxn;i++){
	fac[i]=1ll*i*fac[i-1] %mod;
    }
    
    int ans=0;
    for(int i=0;i<=k;i++){
	if(val[i]!=0) add(ans, 1ll*fac[n-i]*val[i]);
    }
    if(ans<0) ans+=mod;
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.