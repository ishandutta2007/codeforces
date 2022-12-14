#include<cstdio>

const int N=5005,P=1000000007;
int n,f[N][N];
char s[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf(" %c",s+i);
	f[1][1]=1;
	for(int i=2;i<=n;i++)
		if(s[i-1]=='f')for(int j=1;j<=i-1;j++)f[i][j+1]=f[i-1][j];
		else for(int j=i-1;j;j--)f[i][j]=(f[i][j+1]+f[i-1][j])%P;
	int ans=0;
	if(s[n]=='s')for(int i=1;i<=n;i++)ans=(ans+f[n][i])%P;
	printf("%d\n",ans);
	return 0;
}