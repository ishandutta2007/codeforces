#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<n;++i)

vector<int> vec[30010];
int n,d,ret,p[30010],f[30010],dp[30010][510];

int main(){
    scanf("%d%d",&n,&d);
    vec[d].pb(d);
    rep(i,n){scanf("%d",&p[i]);++f[p[i]];}
    memset(dp,-1,sizeof(dp));
    dp[d][300]=f[d];
   
    for(int i=d;i<=30000;++i){
	for(int j=0;j<510;++j)if(dp[i][j]>=0){
	    ret=max(ret,dp[i][j]);
	    for(int k=-1;k<=1;++k){
		int np=d+j-300+k;
		if(np<1)continue;
		if(i+np<=30000){
		    dp[i+np][np-d+300]=max(dp[i+np][np-d+300],dp[i][j]+f[i+np]);
		}
	    }
	}
    }
    printf("%d\n",ret);
    return 0;
}