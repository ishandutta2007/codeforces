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

const int maxn=30100,SQ=400;

int dp[maxn+10][2*SQ+10],cn[maxn];

int main(){
    int n,d;scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++){
	int x;scanf("%d",&x);
	cn[x]++;
    }
    for(int i=30002;i>=0;i--){
	for(int j=1;j<(2*SQ);j++){
	    int jm=d-SQ+j;
	    if(jm>0 && i+jm<30010)
		dp[i][j]=max(dp[i][j],dp[i+jm][j]);
	    if(jm-1>0 && i+jm-1<30010)
		dp[i][j]=max(dp[i][j],dp[i+jm-1][j-1]);
	    if(jm+1>0 && i+jm+1<30010)
		dp[i][j]=max(dp[i][j],dp[i+jm+1][j+1]);
	    dp[i][j]+=cn[i];
	}
    }
    printf("%d\n",dp[d][SQ]);
}