#include <bits/stdc++.h>
using namespace std;
const int N=202;
typedef long long LL;
int r,g,b;
int R[N],G[N],B[N];
LL dp[N][N][N];
int main() {
	scanf("%d%d%d",&r,&g,&b);
	for(int i=1;i<=r;i++)scanf("%d",&R[i]);
	for(int i=1;i<=g;i++)scanf("%d",&G[i]);
	for(int i=1;i<=b;i++)scanf("%d",&B[i]);
	//printf("ok\n");
	sort(R+1,R+1+r);
	sort(G+1,G+1+g);
	sort(B+1,B+1+b);
	//printf("ok\n");
	for(int i=0;i<=r;i++){
		for(int j=0;j<=g;j++){
			for(int k=0;k<=b;k++){
				dp[i][j][k]=max((i>=1&&j>=1)?dp[i-1][j-1][k]+R[i]*G[j]:0,(i>=1&&k>=1)?dp[i-1][j][k-1]+R[i]*B[k]:0);
				dp[i][j][k]=max(dp[i][j][k],(j>=1&k>=1)?dp[i][j-1][k-1]+G[j]*B[k]:0);
			}
		}
	}
	cout<<dp[r][g][b]<<endl;
}