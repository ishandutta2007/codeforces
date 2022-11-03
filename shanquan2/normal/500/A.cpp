#include<cstdio>
using namespace std;

int a[100000];
bool dp[100000]={0};
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<n-1;i++)scanf("%d",&a[i]);
	dp[0]=1;
	for(int i=0;i<n;i++)if(dp[i])dp[i+a[i]]=1;
	if(dp[m-1])printf("YES\n");else printf("NO\n");
	return 0;
}