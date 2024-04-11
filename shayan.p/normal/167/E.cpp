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

const int maxn=610;

vector<int> ins,ous,srt,v[maxn];
bool mark[maxn],dgi[maxn],dgo[maxn];
int dp[maxn],adj[maxn][maxn],n,p;

int tavan(int a,int b){
    int ans=1;
    while(b){
	if(b&1) ans=1ll*ans*a %p;
	a=1ll*a*a %p;
	b/=2;
    }
    return ans;
}

vector<int> operator*(vector<int>v,int c){
    for(int i=0;i<sz(v);i++)
	v[i]=1ll*v[i]*c %p;
    return v;
}
void operator-=(vector<int>&v1,vector<int>v2){
    for(int i=0;i<sz(v1);i++)
	v1[i]=(v1[i]-v2[i])%p;
}

void dfs(int u){
    mark[u]=1;
    for(int y=0;y<n;y++)
	if(adj[u][y] && !mark[y])
	    dfs(y);
    srt.PB(u);
}

int main(){
    int m;scanf("%d%d%d",&n,&m,&p);
    for(int i=0;i<m;i++){
	int a,b;scanf("%d%d",&a,&b);
	adj[--a][--b]++;
	dgi[b]=dgo[a]=1;
    }
    for(int i=0;i<n;i++)
	if(!mark[i])
	    dfs(i);
    for(int i=0;i<n;i++){
	if(!dgi[i]) ous.PB(i);
	if(!dgo[i]) ins.PB(i);
    }
    int k=sz(ous);
    for(int i=0;i<k;i++){
	memset(dp,0,sizeof dp);
	dp[ous[i]]=1;
	for(int j=n-1;j>=0;j--){
	    for(int k=j;k<n;k++)
		if(adj[srt[k]][srt[j]])
		    dp[srt[j]]=(dp[srt[j]]+1ll*adj[srt[k]][srt[j]]*dp[srt[k]])%p;
	}
	for(int j=0;j<k;j++)
	    v[i].PB(dp[ins[j]]);
    }
    int ans=1;
    for(int i=0;i<k;i++){
	int id=-1;
	for(int j=i;j<k;j++)
	    if(v[j][i]!=0)
		id=j;
	if(id==-1){
	    ans=0;
	    break;
	}
	if(id!=i){
	    swap(v[id],v[i]);
	    ans*=-1;
	}
	ans=1ll*ans*v[i][i] %p;
	v[i]=v[i]*tavan(v[i][i],p-2);
	for(int j=0;j<k;j++)
	    if(i!=j && v[j][i]!=0)
		v[j]-=v[i]*v[j][i];
    }
    if(ans<0)ans+=p;
    printf("%d\n",ans);
    return 0;
}