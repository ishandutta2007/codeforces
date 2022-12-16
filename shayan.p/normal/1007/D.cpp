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
 
const int maxn=1e5+10, MAXN=18e6;
 
int n,m;
 
int SZ[maxn], sp[20][maxn], h[maxn];
vector<int> v[maxn];
vector<int> era[maxn], ins[maxn];
 
bool eras[maxn];
 
int lca(int a,int b){
    if(h[a]<h[b]) swap(a,b);
    for(int i=19;i>=0;i--){
	if(h[ sp[i][a] ] >= h[b]) a=sp[i][a];
    }
    if(a==b) return a;
    for(int i=19;i>=0;i--){
	if(sp[i][a] != sp[i][b]) a=sp[i][a], b=sp[i][b];
    }
    return sp[0][a];
}
void prep(int u,int par=0){
    h[u]= h[par]+1;
    sp[0][u]= par;
    for(int i=1;i<20;i++)
	sp[i][u]= sp[i-1][sp[i-1][u]];
    for(int y:v[u]){
	if(y!=par)
	    prep(y,u);
    }
    for(int i=0;i<sz(v[u]);i++){
	if(v[u][i]==par){
	    swap(v[u][i], v[u][sz(v[u])-1]);
	    v[u].pop_back();
	    break;
	}
    }
}
void prepsz(int u){
    for(int y:v[u]){
	prepsz(y);
	SZ[u]+= SZ[y];
    }
    sort(v[u].begin(), v[u].end(), [](int a,int b){ return SZ[a]<SZ[b]; } );
}
 
int C, sg[maxn], who[maxn];
set<int> st[maxn];
bool inside[maxn];
 
int Ced;
int bf[3*MAXN], tp[MAXN], to[3*MAXN], tp2[MAXN];

void add(int a,int b){
    bf[Ced]= tp[a], tp[a]= Ced, to[Ced]= b;
    swap(a,b), a^=1, b^=1;
    Ced++;
    bf[Ced]= tp[a], tp[a]= Ced, to[Ced]= b;
    Ced++;
}
 
void build(){
    for(int i=1;i<2*m;i++)
	sg[i]= C++;
    for(int i=m;i<2*m;i++)
	who[i-m]= sg[i];
    for(int i=m-1;i>0;i--){
	add(2*sg[2*i], 2*sg[i]);
	add(2*sg[2*i+1], 2*sg[i]);
	add(2*sg[2*i], 2*sg[2*i+1]+1);
    }	
}
void put(int i){
    who[i]= C;
    i+= m;
    sg[i]= C++;
    for(i>>=1; i>0; i>>=1){
	sg[i]= C++;
	add(2*sg[2*i], 2*sg[i]);
	add(2*sg[2*i+1], 2*sg[i]);
	add(2*sg[2*i], 2*sg[2*i+1]+1);
    }
}
 
void Add(int x){
    put(x/2);
    add(x,2*who[x/2]);
    inside[x]=1;
    if(inside[x^1]) add(x^1,2*who[x/2]);
}
void Era(int x){
    put(x/2);
    inside[x]=0;
    if(inside[x^1]) add(x^1,2*who[x/2]);	
}
 
void dfs(int u,bool clr){// enters empty
    for(int i=0;i<sz(v[u])-1;i++)
	dfs(v[u][i],1);
    for(auto x:era[u])
	eras[x]=1;
    for(auto x:ins[u])
	if(eras[x]==0) st[u].insert(x);
    for(int i=0;i<sz(v[u])-1;i++)
	for(int x:st[v[u][i]])
	    if(eras[x]==0) st[u].insert(x);
    for(auto x:era[u])
	eras[x]=0;
    if(sz(v[u])){
	int y=v[u].back();
	dfs(y,0);
	for(auto x:era[u])
	    eras[x]=1;
	for(auto x:era[u]){
	    eras[x]=0;
	    if(st[y].count(x))
		Era(x), st[y].erase(x);
	}
	swap(st[y], st[u]);
	for(auto x:st[y])
	    st[u].insert(x), Add(x);
    }
    else{
	for(int x:st[u])
	    Add(x);
    }
    if(clr)
	for(int x:st[u])
	    Era(x);
}
 
int vec[MAXN], Cvec;
int COL, col[MAXN];
 
void sat1(int u){
    col[u]=0;
    for(int id= tp[u]; id!=-1;){
	if(col[to[id]]==-1) sat1(to[id]);
	int x= bf[id];
	bf[id]= tp2[to[id]], tp2[to[id]]= id, to[id]=u;
	id=x;
    }
    vec[ Cvec++ ]=u;
}
void sat2(int u){
    col[u]=COL;
    for(int id= tp2[u]; id!=-1; id=bf[id])
	if(col[to[id]]==-1) sat2(to[id]);
}
bool satsolver(){
    memset(col,-1,sizeof col);
    for(int i=0;i<2*C;i++) if(col[i]==-1) sat1(i);
    memset(col,-1,sizeof col);
    for(int i=2*C-1;i>=0;i--) if(col[vec[i]]==-1) sat2(vec[i]), COL++;
    for(int i=0;i<C;i++) if(col[2*i]==col[2*i+1]) return 0;
    return 1;
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    memset(tp,-1,sizeof tp);
    memset(tp2,-1,sizeof tp2);
    
    cin>>n;
    for(int i=1;i<=n-1;i++){
	int a,b; cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    prep(1);
    
    cin>>m;
    C=m;
  
    for(int i=0;i<m;i++){
	int a,b,c,d; cin>>a>>b>>c>>d;
	ins[a].PB(2*i), ins[b].PB(2*i), ins[c].PB(2*i+1), ins[d].PB(2*i+1);
	int x=lca(a,b), y=lca(c,d);
	era[x].PB(2*i), era[y].PB(2*i+1);
	SZ[a]++, SZ[b]++, SZ[c]++, SZ[d]++, SZ[x]-=2, SZ[y]-=2;
    }
 
    prepsz(1);
    
    build();
    dfs(1,1);
 
    assert(Ced<3*MAXN && 2*C<MAXN);
    
    if(satsolver()==0) return cout<<"NO\n",0;
    cout<<"YES\n";
    
    for(int i=0;i<m;i++){
	cout<<(col[2*i]<col[2*i+1])+1<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.