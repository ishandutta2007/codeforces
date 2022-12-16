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

const int maxn=2010,mod=1e9+7;
const ll inf=1e18;

ll ds1[maxn],ds2[maxn],arr[maxn],sm1[maxn][maxn],sm2[maxn][maxn],dp[2][maxn][maxn];
int adj[maxn][maxn],smc1[maxn][maxn],smc2[maxn][maxn],p[maxn],C,n;
bool mark[maxn];

void dij(ll* ds,int s){
    fill(ds,ds+maxn,inf);
    memset(mark,0,sizeof mark);
    ds[s]=0;
    for(int q=0;q<n;q++){
	int wh=-1;
	for(int i=0;i<n;i++){
	    if(!mark[i] && (wh==-1 || ds[wh]>ds[i]))
		wh=i;
	}
	mark[wh]=1;
	for(int i=0;i<n;i++){
	    if(!mark[i] && adj[wh][i]!=-1)
		ds[i]=min(ds[i],ds[wh]+adj[wh][i]);
	}
    }
    C=0;
    for(int i=0;i<n;i++){
	arr[C++]=ds[i];
    }
    sort(arr,arr+C);
    C=unique(arr,arr+C)-arr;
    for(int i=0;i<n;i++){
	ds[i]=lower_bound(arr,arr+C,ds[i])-arr;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int m,s,t;cin>>n>>m>>s>>t;
    memset(adj,-1,sizeof adj);
    --s,--t;
    for(int i=0;i<n;i++){
	cin>>p[i];
    }
    for(int i=0;i<m;i++){
	int a,b,c;cin>>a>>b>>c;
	--a,--b;
	if(adj[a][b]==-1 || adj[a][b]>c)
	    adj[a][b]=adj[b][a]=c;
    }
    dij(ds1,s);
    int N=C;
    dij(ds2,t);
    int M=C;
    for(int i=0;i<n;i++){
	smc1[ds1[i]][ds2[i]]++;
	sm1[ds1[i]][ds2[i]]+=p[i];
	smc2[ds1[i]][ds2[i]]++;
	sm2[ds1[i]][ds2[i]]+=p[i];
    }
    for(int i=N-1;i>=0;i--){
	for(int j=M-1;j>=0;j--){
	    smc1[i][j]+=smc1[i][j+1];
	    sm1[i][j]+=sm1[i][j+1];
	}
    }
    for(int j=M-1;j>=0;j--){
	for(int i=N-1;i>=0;i--){
	    smc2[i][j]+=smc2[i+1][j];
	    sm2[i][j]+=sm2[i+1][j];
	}
    }
    for(int i=N-1;i>=0;i--){
	for(int j=M-1;j>=0;j--){
	    dp[0][i][j]=dp[0][i+1][j]+sm1[i][j];
	    dp[1][i][j]=dp[1][i][j+1]-sm2[i][j];
	    if(smc1[i][j]!=0) dp[0][i][j]=max(dp[0][i][j],dp[1][i+1][j]+sm1[i][j]);
	    if(smc2[i][j]!=0) dp[1][i][j]=min(dp[1][i][j],dp[0][i][j+1]-sm2[i][j]);
	}
    }
    ll Num=dp[0][0][0];
    if(Num<0) cout<<"Cry\n";
    if(Num==0) cout<<"Flowers\n";
    if(Num>0) cout<<"Break a heart\n";
}