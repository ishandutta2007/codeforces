#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN=1e6+5;

int n;

int dp[MAXN],p[MAXN];

int mx1[MAXN],mx2[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=2;i<=n+1;++i){
		scanf("%d",p+i);
		dp[i]=1;
		int cur=i;
		while(cur!=1){
			int par=p[cur];
			if(dp[cur]>mx1[par]){
				mx2[par]=mx1[par];
				mx1[par]=dp[cur];
			}
			else if(dp[cur]>mx2[par]){
				mx2[par]=dp[cur];
			}
			cur=par;
			int res=max(mx1[cur],mx2[cur]+1);
			if(res==dp[cur])break;
			dp[cur]=res;
		}
		printf("%d ",mx1[1]);
	}
	return 0;
}