#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int r,n;
int t[N],x[N],y[N],dp[N],mx[N];
int main() {
	scanf("%d%d",&r,&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&t[i],&x[i],&y[i]);
	}
	for(int i=0;i<=n;i++)dp[i]=-1e9,mx[i]=-1e9;
	t[0]=0,x[0]=1,y[0]=1; dp[0]=mx[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=0;j--){
			int d=abs(x[i]-x[j])+abs(y[i]-y[j]);
			if(t[i]-t[j]>2*(r-1)) {
				dp[i]=max(dp[i],mx[j]+1); break;
			}
			if(d<=t[i]-t[j]){
				//printf("%d->%d\n", j,i);
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		mx[i]=max(mx[i-1],dp[i]);
		//printf("dp[%d]=%d\n", i,dp[i]);
	}
	cout<<mx[n]<<endl;
}