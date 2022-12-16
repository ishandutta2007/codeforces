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
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;///////// to be corrected
const ll mod=1e9+7;
const ll MXLG=20;

pll e[maxn];
vector<ll>v[maxn],g[maxn];
ll cn,fn[maxn],dp[2][maxn],wh[maxn][MXLG+3],h[maxn];
vector<pll>vec;
bool is[maxn];

void dfs(ll u,ll par=-1){
    for(ll y:v[u]){
	if(y!=par){
	    wh[y][0]=u;
	    h[y]=h[u]+1;
	    dfs(y,u);
	}
    }
    fn[u]=(cn++);
}

ll LCA(ll a,ll b){
    if(h[a]<h[b])swap(a,b);
    FORD(i,MXLG,0){
	if(h[wh[a][i]]>=h[b])
	    a=wh[a][i];
    }
    if(a==b)return a;
    FORD(i,MXLG,0){
	if(wh[a][i]!=wh[b][i]){
	    a=wh[a][i];
	    b=wh[b][i];
	}
    }
    return wh[a][0];
}

ll solve(ll u){
    ll mx=0,sm0=0,sm1=0,bad=0;
    for(ll y:g[u]){
	solve(y);
	if(dp[1][y]==-1){
	    if(wh[y][0]==u)
		bad++;
	    else
		dp[1][y]=dp[0][y]+1;
	}
	mx=max(mx,dp[1][y]-dp[0][y]);
	sm0+=dp[0][y];
	if(dp[1][y]!=-1)
	    sm1+=dp[1][y];
	else
	    sm1+=dp[0][y];
    }
    if(is[u]){
	dp[0][u]=sm1;
	dp[1][u]=-1;
    }
    else{
	if(bad>1){
	    dp[1][u]=dp[0][u]=1+sm0;
	}
	if(bad==1){
	    dp[1][u]=1+sm0;
	    dp[0][u]=min(1+sm0,sm1);
	}
	if(bad==0){
	    dp[1][u]=min(1+sm0,sm1);
	    dp[0][u]=min(dp[1][u],sm1-mx);
	}
    }
    return dp[0][u];
}

int main(){
    ll n;cin>>n;
    REP(i,n-1){
	cin>>e[i].F>>e[i].S;
	v[e[i].F].PB(e[i].S);
	v[e[i].S].PB(e[i].F);
    }
    h[0]=-1;
    dfs(1);
    FOR(j,1,MXLG){
	FOR(i,1,n){
	    wh[i][j]=wh[wh[i][j-1]][j-1];
	}
    }

    ll q;cin>>q;
    while(q--){
	vec.clear();
	ll m;cin>>m;
	REP(i,m){
	    ll x;cin>>x;
	    is[x]=1;
	    vec.PB(MP(fn[x],x));
	}
	sort(vec.begin(),vec.end());
	REP(i,m-1){
	    ll x=LCA(vec[i].S,vec[i+1].S);
	    if(wh[vec[i].S][0]==x && is[x]){
		cout<<-1<<endl;
		goto END;
	    }
	    vec.PB(MP(fn[x],x));
	}
	sort(vec.begin(),vec.end());
	REP(i,sz(vec)-1){
	    if(vec[i]!=vec[i+1])
		g[LCA(vec[i].S,vec[i+1].S)].PB(vec[i].S);
	}

	cout<<solve(vec.back().S)<<endl;
    END:;
	REP(i,sz(vec)){
	    g[vec[i].S].clear();
	    is[vec[i].S]=0;
	    dp[0][vec[i].S]=dp[1][vec[i].S]=0;
	}
    }
}