// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

vector<pii>v[maxn];
set<pii>s1,s2;// finishing time // node
map<int,int>mp;
int t[maxn],T,sp[20][maxn],h[maxn];
ll spw[maxn];
ll ANS;

void dfs(int u,int par=0,ll W=0,int H=1){
    sp[0][u]=par;
    spw[u]=W;
    h[u]=H;
    for(pii p:v[u]){
	if(p.F!=par)
	    dfs(p.F,u,W+p.S,H+1);
    }
    t[u]=T++;
}

int LCA(int a,int b){
    if(h[a]<h[b])swap(a,b);
    for(int i=19;i>=0;i--){
	if(h[sp[i][a]]>=h[b]){
	    a=sp[i][a];
	}   
    }
    if(a==b)   return a;
    for(int i=19;i>=0;i--){
	if(sp[i][a]!=sp[i][b]){
	    a=sp[i][a];
	    b=sp[i][b];
	}
    }
    return sp[0][a];
}

void ADD(int u){
    auto it=s2.upper_bound({t[u],u});
    pii p1={-1,-1},p2=(it==s2.end()?MP(-1,-1):*it);
    if(it!=s2.begin())
	p1=*(--it);
    if(p1.F!=-1 && p2.F!=-1)
	ANS-=spw[p1.S]-spw[LCA(p1.S,p2.S)];
    if(p1.F!=-1)
	ANS+=spw[p1.S]-spw[LCA(p1.S,u)];
    if(p2.F!=-1)
	ANS+=spw[u]-spw[LCA(u,p2.S)];
    s2.insert({t[u],u});
}

void DEL(int u){
    s2.erase({t[u],u});
    auto it=s2.upper_bound({t[u],u});
    pii p1={-1,-1},p2=(it==s2.end()?MP(-1,-1):*it);
    if(it!=s2.begin())
	p1=*(--it);
    if(p1.F!=-1 && p2.F!=-1)
	ANS+=spw[p1.S]-spw[LCA(p1.S,p2.S)];
    if(p1.F!=-1)
	ANS-=spw[p1.S]-spw[LCA(p1.S,u)];
    if(p2.F!=-1)
	ANS-=spw[u]-spw[LCA(u,p2.S)];
}

void Add(int u,int x){
    if(mp.count(u)){
	if((mp[u]=mp[u]+x)>0)return;
	mp.erase(u);
	DEL(u);
    }
    else{
	mp[u]+=x;
	ADD(u);
    }
}

int main(){
    int n;scanf("%d",&n);
    for(int i=2;i<=n;i++){
	int a,b,c;scanf("%d%d%d",&a,&b,&c);
	v[a].PB({b,c});
	v[b].PB({a,c});
    }
    dfs(1);
    for(int i=1;i<20;i++){
	for(int j=1;j<=n;j++){
	    sp[i][j]=sp[i-1][sp[i-1][j]];
	}
    }
    int q;scanf("%d",&q);
    while(q--){
	char ch;scanf(" %c",&ch);
	if(ch=='?'){
	    printf("%lld\n",ANS);
	}
	if(ch=='+'){
	    int u;scanf("%d",&u);
	    auto it=s1.upper_bound({t[u],u});
	    pii p1={-1,-1},p2=(it==s1.end()?MP(-1,-1):*it);
	    if(it!=s1.begin())
		p1=*(--it);
	    if(p1.F!=-1 && p2.F!=-1)
		Add(LCA(p1.S,p2.S),-1);
	    if(p1.F!=-1)
		Add(LCA(p1.S,u),1);
	    if(p2.F!=-1)
		Add(LCA(p2.S,u),1);
	    Add(u,1);
	    s1.insert({t[u],u});
	}
	if(ch=='-'){
	    int u;scanf("%d",&u);
	    s1.erase({t[u],u});
	    auto it=s1.upper_bound({t[u],u});
	    pii p1={-1,-1},p2=(it==s1.end()?MP(-1,-1):*it);
	    if(it!=s1.begin())
		p1=*(--it);
	    if(p1.F!=-1 && p2.F!=-1)
		Add(LCA(p1.S,p2.S),1);
	    if(p1.F!=-1)
		Add(LCA(p1.S,u),-1);
	    if(p2.F!=-1)
		Add(LCA(p2.S,u),-1);
	    Add(u,-1);
	}
    }
}