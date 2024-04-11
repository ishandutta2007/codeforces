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
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

const ll inf=4e18;
const ll maxn=3e5+10;
const ll mod=1e9+7;

vector<pii>v[maxn],vec;
bool mark[maxn],yep;
int n,ch[maxn];
ll P1,P2;

bool dfs1(int u,int par=-1){
    if(u==n){
	mark[u]=1;
	vec.PB({u,0});
	return 1;
    }
    for(pii p:v[u]){
	if(p.F!=par){
	    if(dfs1(p.F,u)){
		mark[u]=1;
		vec.PB({u,p.S});
		return 1;
	    }
	}
    }
    return 0;
}

int main(){
    int m;scanf("%d%d",&n,&m);
    REP(i,(n-1)){
	int a,b,c;scanf("%d%d%d",&a,&b,&c);
	v[a].PB({b,c});
	v[b].PB({a,c});
    }
    dfs1(1);
    reverse(all(vec));
    REP(i,sz(vec)){
	int x=vec[i].F;
	int S=2-(i==0)-(i==(sz(vec)-1));
	if(sz(v[x])>=(S+2)){
	    yep=1;
	}
	else if(sz(v[x])==(S+1)){
	    REP(j,S+1){
		if(!mark[v[x][j].F]){
		    if(sz(v[v[x][j].F])>=2)
			yep=1;
		    else
			ch[i]=v[x][j].S;
		}
	    }
	}
    }
    REP(i,sz(vec)){
	P1+=vec[i].S;
    }
    REP(i,(sz(vec)-1)){
	if(ch[i]==0 && ch[i+1]==0)continue;
	P2=max(P2,P1-vec[i].S+ch[i]+ch[i+1]);
    }
    REP(i,(sz(vec)-2)){
	P2=max(P2,P1-vec[i].S-vec[i+1].S+ch[i]+ch[i+2]);
    }
    while(m--){
	int x;scanf("%d",&x);
	if(yep)
	    printf("%lld\n",P1);
	else
	    printf("%lld\n",ll(min(P1,P2+x)));
    }
}