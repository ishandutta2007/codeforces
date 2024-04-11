// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define FORK(i,a,b,c) for(int i=int(a);i<=b;i+=c)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn=2e6+10;
const int Big=1e9+10;

pii p[maxn];
int N,M,n;
vector<int>vec,v[maxn],g[maxn];
int dg[maxn];
int dc[maxn];
bool mark[maxn];

void dfs(int u){
    M+=sz(v[u]);
    N++;
    mark[u]=1;
    for(int x:v[u]){
	if(!mark[x])
	    dfs(x);
    }
}

bool ok(int x){
    REP(i,n){
	if(p[i].F>x && p[i].S>x)return 0;
	else if(p[i].S>x)dg[i]=1,vec.PB(i);
	else if(p[i].F>x)dg[i]=2,vec.PB(i);
	else dg[i]=3;
    }
    while(sz(vec)){
	int w=vec.back(),y=-1;
	vec.POB();
	if(dg[w]==1)
	    y=p[w].F;
	if(dg[w]==2)
	    y=p[w].S;
	for(ll x:g[y]){
	    if(x!=w){
		if(dg[x]!=3)return 0;
		if(p[x].F==y)dg[x]=2;
		else dg[x]=1;
		vec.PB(x);
	    }
	}
	dg[w]=0;
    }
    REP(i,n){
	if(dg[i]==3){
	    v[p[i].F].PB(p[i].S);
	    v[p[i].S].PB(p[i].F);
	}
    }
    REP(i,maxn){
	N=M=0;
	if(!mark[i]){
	    dfs(i);
	    M/=2;
	    if(M!=(N-1) && M!=N)return 0;
	}
    }
    return 1;
}

int main(){
    scanf("%d",&n);
    int last=0;
    REP(i,n){
	scanf("%d%d",&p[i].F,&p[i].S);
	dc[last++]=p[i].F;
	dc[last++]=p[i].S;
	//cd[p[i].F]=cd[p[i].S]=0;
    }
    sort(dc,dc+last);
    last=unique(dc,dc+last)-dc;
    REP(i,n){
	p[i].F=lower_bound(dc,dc+last,p[i].F)-dc;
	p[i].S=lower_bound(dc,dc+last,p[i].S)-dc;
    }
    REP(i,n){
	g[p[i].F].PB(i);
	g[p[i].S].PB(i);
    }
    int l=0,r=last-1,ans=-1;
    while(l<=r){
	int mid=(l+r)/2;
	memset(dg,0,sizeof dg);
	memset(mark,0,sizeof mark);
	REP(i,maxn){
	    v[i].clear();
	}
	vec.clear();
	if(ok(mid)){
	    ans=dc[mid];
	    r=mid-1;
	}
	else{
	    l=mid+1;
	}
    }
    printf("%d\n",ans);
}