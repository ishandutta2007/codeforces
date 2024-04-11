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

vector<int>v[maxn];
vector<pii>vec;
int sp[20][maxn],h[maxn],SZ[maxn],pr[maxn],tp[maxn],n;
ll ANS,val[maxn];

inline ll P2(ll n){
    return n*(n-1);
}
inline ll P3(ll n){
    return n*(n-1)*(n-2);
}

int dfs(int u,int par=0,int H=1){
    SZ[u]=1;
    h[u]=H;
    sp[0][u]=par;
    for(int i=1;i<20;i++)
	sp[i][u]=sp[i-1][sp[i-1][u]];
    for(int y:v[u])
	if(y!=par)
	    SZ[u]+=dfs(y,u,H+1),val[u]+=P2(SZ[y]),ANS-=P2(SZ[y]);
    ANS-=P2(n-SZ[u]);
    val[u]+=P2(n-SZ[u]);
    ANS+=P2(n-1);
    return SZ[u];
}

int LCA(int a,int b){
    if(h[a]<h[b]) swap(a,b);
    for(int i=19;i>=0;i--){
	if(h[sp[i][a]]>=h[b])
	    a=sp[i][a];
    }
    if(a==b) return a;
    for(int i=19;i>=0;i--){
	if(sp[i][a]!=sp[i][b])
	    a=sp[i][a],b=sp[i][b];
    }
    return sp[0][a];
}

int Find(int a){
    return pr[a]<0?a:pr[a]=Find(pr[a]);
}

void Merge(int a,int b){
    if(h[tp[a]]<h[tp[b]]) swap(a,b);
    int ss=SZ[tp[a]];
    a=Find(a);b=Find(b);
    ANS-=P3(-pr[a])+P3(-pr[b])+2ll*P2(-pr[a])*(n+pr[a])+2ll*P2(-pr[b])*(n+pr[b]);
    ANS+=P3(-pr[a]-pr[b])+2ll*P2(-pr[a]-pr[b])*(n+pr[a]+pr[b]);
    ANS-=(P2(n+pr[a])-val[a])*(-pr[a])+(P2(n+pr[b])-val[b])*(-pr[b]);
    ll x=val[a]-P2(n-ss)+val[b]-P2(ss);
    ANS+=(P2(n+pr[a]+pr[b])-x)*(-pr[a]-pr[b]);
    if(pr[a]>pr[b]) swap(a,b);
    pr[a]+=pr[b];
    pr[b]=a;
    tp[a]=h[tp[a]]>h[tp[b]]?tp[b]:tp[a];
    val[a]=x;
}

void PUSH(int a,int b){
    while(a!=b){
	int c=Find(sp[0][tp[a]]);
	vec.PB({a,c});
	a=c;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    
    memset(pr,-1,sizeof pr);
    iota(tp,tp+maxn,0);
    
    cin>>n;
    for(int i=0;i<n-1;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    dfs(1);
    cout<<ANS<<"\n";
    int m;cin>>m;
    for(int i=0;i<m;i++){
	int A,B;cin>>A>>B;
	int lc=LCA(A,B);
	A=Find(A);
	B=Find(B);
	lc=Find(lc);
	vec.clear();
	PUSH(A,lc);
	int SS=sz(vec);
	PUSH(B,lc);
	reverse(vec.begin()+SS,vec.end());
	for(pii p:vec)
	    Merge(Find(p.F),Find(p.S));
	cout<<ANS<<"\n";
    }
    return 0;
}