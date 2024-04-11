// Remember...

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

int Pow(int a,int b){
    int ans=1;
    for(; b; b>>=1, a=1ll*a*a %mod)
	if(b&1)
	    ans=1ll*ans*a %mod;
    return ans;
}


struct Fenwick{
    int vl[maxn];

    void add(int i,int x){
	for(i+=3; i<maxn; i+=i & -i)
	    vl[i]=(vl[i] + x) %mod;
    }
    int ask(int i){
	int ans=0;
	for(i+=3; i>0; i-=i & -i)
	    ans=(ans + vl[i]) %mod;
	return ans;
    }
    int ask(int l,int r){
	return (ask(r) - ask(l)) %mod;
    }
};

struct Segment{
    Fenwick fn1,fn2;
    
    void add(int l,int r,int x){
	fn2.add(l+1,x);
	fn2.add(r+1,-x);
	fn1.add(l+1, -1ll*l*x %mod);
	fn1.add(r+1, 1ll*r*x %mod);
    }
    int ask(int l,int r){
	return (1ll*fn1.ask(r) - 1ll*fn1.ask(l) + 1ll*r*fn2.ask(r) - 1ll*l*fn2.ask(l)) %mod;
    }
};
Segment sga, sgb;

int VAL;

void add(int l,int r,int x){
    VAL=(1ll*VAL - 1ll*sga.ask(l,r)*x + 1ll*sgb.ask(l,r)*x - 1ll*(r-l)*x %mod * x)%mod;
    sga.add(l,r,x);
    sgb.add(l,r,-x);
}
inline int ask(){
    return VAL;
}

int SZ[maxn], L[maxn], R[maxn], iv[maxn], z=1, ANS, n;
int big[maxn];
vector<int> v[maxn], con[maxn];

void prepSZ(int u,int par=-1){
    SZ[u]=1;
    big[u]=-1;
    for(int i=0;i<sz(v[u]);i++){
	if(v[u][i]==par){
	    swap(v[u][i], v[u][sz(v[u])-1]);
	    v[u].pop_back();
	    break;
	}
    }
    for(int y:v[u]){
	if(y!=par){
	    prepSZ(y,u);
	    SZ[u]+=SZ[y];
	    if(big[u]==-1 || (SZ[big[u]] < SZ[y]))
		big[u]=y;
	}
    }
    sort(v[u].begin(), v[u].end(), [](int a,int b){ return SZ[a]<SZ[b]; } );///////
}
void dfs(int u,bool is=1){
    for(int y:v[u])
	if(y!=big[u])
	    dfs(y, 0);
    if(big[u]!=-1){
	dfs(big[u], 1);
	swap(con[u], con[big[u]]);
	for(int y:v[u])
	    if(y!=big[u])
		for(int w:con[y])
		    con[u].PB(w), add(L[w], R[w], iv[w]);
    }
    con[u].PB(u), add(L[u], R[u], iv[u]);

    ANS= (ANS + ask()) %mod;
    if(is==0){
	for(int w:con[u])
	    add(L[w], R[w], -iv[w]);
    }
}

int main(){
    scanf("%d", &n);
    
    for(int i=1;i<=n;i++){
	scanf("%d%d", &L[i], &R[i]);
	L[i]--;
	iv[i]=Pow(R[i]-L[i], mod-2);
	z=1ll*z*(R[i]-L[i]) %mod;
	sgb.add(L[i], R[i], iv[i]);
    }
    for(int i=0;i<n-1;i++){
	int a,b; scanf("%d%d", &a, &b);
	v[a].PB(b);
	v[b].PB(a);	
    }
    
    prepSZ(1);
    dfs(1);
    
    ANS= 1ll*ANS*z %mod;
    if(ANS<0) ANS+=mod;
    printf("%d", ANS);
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.