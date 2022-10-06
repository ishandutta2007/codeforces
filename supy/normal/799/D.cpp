#include<cstdio>
#include<algorithm>
#include<cstring> 
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
const int inf = 1e8;
int a,b,h,w,N,n,m,ans=inf;
int A[100005],dp[100005];
int cmp(int a, int b) {
	return a>b;
}
inline int solve(int a, int b, int h, int w) {
	if (a<=h&&b<=w) return 0;
	a=(a-1)/h+1; b=(b-1)/w+1;
	memset(dp,0,sizeof(dp));
	dp[1]=1;
	rep(i,1,N) {
		for (int j=a; j>=1; j--) {
			int mn=min((ll)j*A[i],a);
			dp[mn]=max(dp[mn],dp[j]);
			dp[j]=min((ll)dp[j]*A[i],b);
		}
	//	rep(j,1,a) printf("%d ",dp[j]); puts("");
		if (dp[a]>=b) return i;
	}
	return inf;
}
int main() {
	scanf("%d%d%d%d%d",&a,&b,&h,&w,&N);
	rep(i,1,N) scanf("%d",&A[i]);
	sort(A+1,A+N+1,cmp); N=min(N,34);
	ans=min(solve(a,b,h,w),solve(a,b,w,h));
	if (ans==inf) puts("-1"); else printf("%d",ans);
	return 0;
}