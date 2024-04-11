#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> nei[100005];
int c[3][100005];
long long dp[3][3][100005];
int deg[100005];
int bg;
int nxt[100005];
int dy[100005];
int ans[100005];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",c[0]+i);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",c[1]+i);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",c[2]+i);
	}
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		nei[a].push_back(b);
		nei[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}
	for(int i=1;i<=n;i++){
		if(deg[i]>=3){
			puts("-1");
			return 0;
		}
		if(deg[i]==1){
			bg=i;
		}
	}
	int lst=-1;
	for(int i=1;i<=n;i++){
		dy[i]=bg;
		for(int j=0;j<nei[bg].size();j++){
			if(nei[bg][j]!=lst){
				lst=bg;
				bg=nei[bg][j];
				nxt[bg]=nei[bg][j];
				break;
			}
		}
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(i!=j){
				dp[i][j][2]=c[i][dy[1]]+c[j][dy[2]];
			}
		}
	}
	for(int i=2;i<n;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				if(j==k){
					continue;
				}
				int l=3-j-k;
				dp[k][l][i+1]=min(dp[k][l][i+1],dp[j][k][i]+c[l][dy[i+1]]);
			}
		}
	}
	int mini=0,minj=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(dp[i][j][n]<dp[mini][minj][n]){
				mini=i;minj=j;
			}
		}
	}
	printf("%lld\n",dp[mini][minj][n]);
	ans[dy[n]]=minj+1;
	ans[dy[n-1]]=mini+1;
	int aa=mini,bb=minj;
	for(int i=n-2;i;i--){
		int to=3-aa-bb;
		ans[dy[i]]=to+1;
		bb=aa;
		aa=to;
	}
	for(int i=1;i<=n;i++){
		printf("%d%c",ans[i],i==n?'\n':' ');
	}
	return 0;
}