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

const int maxn=5010,inf=1e9+10;

int dp[maxn][maxn][2],tmp[maxn][2],SZ[maxn],c[maxn],d[maxn];
vector<int>v[maxn];

int main(){
    int n,b;scanf("%d%d",&n,&b);
    scanf("%d%d",&c[1],&d[1]);
    for(int i=2;i<=n;i++){
	int x;scanf("%d%d%d",&c[i],&d[i],&x);
	v[x].PB(i);
    }
    for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	    dp[i][j][0]=dp[i][j][1]=inf;
    for(int i=n;i>=1;i--){
	for(int k:v[i]){
	    for(int s=1;s<=SZ[k]+SZ[i];s++)
		tmp[s][0]=tmp[s][1]=inf;
	    for(int s1=0;s1<=SZ[i];s1++){
		for(int s2=0;s2<=SZ[k];s2++){
		    tmp[s1+s2][0]=min(tmp[s1+s2][0],dp[i][s1][0]+dp[k][s2][0]);
		    tmp[s1+s2][1]=min(tmp[s1+s2][1],dp[i][s1][1]+dp[k][s2][1]);
		}
	    }
	    SZ[i]+=SZ[k];
	    for(int s=0;s<=SZ[i];s++){
		dp[i][s][0]=tmp[s][0];
		dp[i][s][1]=tmp[s][1];
	    }
	}
	for(int s=1;s<=SZ[i]+1;s++)
	    dp[i][s][0]=dp[i][s][1]=inf;
	for(int s=0;s<=SZ[i];s++){
	    dp[i][s][0]=min(dp[i][s][0],tmp[s][0]);
	    dp[i][s][1]=min(dp[i][s][1],tmp[s][0]);
	    dp[i][s+1][0]=min(dp[i][s+1][0],c[i]+tmp[s][0]);
	    dp[i][s+1][1]=min(dp[i][s+1][1],c[i]-d[i]+tmp[s][1]);
	}
	SZ[i]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
	if(dp[1][i][1]<=b)
	    ans=i;
    printf("%d\n",ans);
    return 0;
}