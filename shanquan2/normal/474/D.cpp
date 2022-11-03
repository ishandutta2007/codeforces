#include<cstdio>
using namespace std;

const int n=100000;
const int M=1000000007;
int dp[n+10],s[n+10];
int main(){
	int t,k;scanf("%d%d",&t,&k);
	for(int i=0;i<k;i++)dp[i]=1,s[i]=i;
	for(int i=k;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-k];
		dp[i]%=M;
		s[i]=s[i-1]+dp[i];
		s[i]%=M;
	}
//	for(int i=0;i<=10;i++)printf("%d %d\n",dp[i],s[i]);printf("\n");
	for(int i=0;i<t;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",(s[y]-s[x-1]+M)%M);
	}
	return 0;
}