// Wanna Hack? GL...

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

const int maxn=110,inf=1e5;

bool forb[maxn],good[maxn][maxn];
int dis[maxn][maxn],dis2[maxn][maxn],d[maxn][maxn],dp[maxn],n;
vector<int>wh[maxn];

void floyd(int dis[][maxn]){
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	    if(forb[i] || forb[j])
		dis[i][j]=inf;
	    else
		dis[i][j]=d[i][j];
	}
    }
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	    for(int k=0;k<n;k++){
		dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
	    }
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    for(int i=0;i<maxn;i++)
	for(int j=0;j<maxn;j++)
	    d[i][j]=inf;
    for(int i=0;i<maxn;i++)
	d[i][i]=0;
    for(int i=0;i<maxn;i++)
	dp[i]=inf;
    int m,A,B;cin>>n>>m>>A>>B;
    --A,--B;
    while(m--){
	int a,b;cin>>a>>b;
	--a,--b;
	d[a][b]=1;
    }
    floyd(dis);
    int Q;cin>>Q;
    while(Q--){
	int a,b;cin>>a>>b;
	--a,--b;
	if(dis[a][b]==inf) continue;
	for(int i=0;i<n;i++){
	    wh[i].clear();
	}
	for(int i=0;i<n;i++){
	    if(dis[a][i]!=inf)
		wh[dis[a][i]].PB(i);
	}
	for(int i=0;i<=dis[a][b];i++){
	    int CNT=0,LST=-1;
	    for(int u:wh[i]){
		if(dis[a][u]+dis[u][b]==dis[a][b])
		    CNT++,LST=u;
	    }
	    if(CNT==1){
		good[LST][b]=1;
	    }
	}
    }
    queue<int>q;
    dp[B]=0;
    q.push(B);
    int Now=0;
    while(sz(q)){
	while(sz(q)){
	    int u=q.front(); q.pop();
	    forb[u]=1;
	}
	floyd(dis2);
	for(int i=0;i<n;i++){
	    if(dp[i]!=inf) continue;
	    for(int j=0;j<n;j++){
		if(good[i][j] && dis2[i][j]>dis[i][j]){
		    q.push(i);
		    dp[i]=Now+1;
		    break;
		}
	    }
	}
	Now++;
    }
    int ans=dp[A];
    if(ans==inf) ans=-1;
    return cout<<ans<<endl,0;
}