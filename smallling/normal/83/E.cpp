#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n,l,pre[250010][21],last[250010][21];
int a[250010],g[250010],f[1<<20][21];
char s[110];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		l=strlen(s+1);
		for(int j=1;j<=l;j++)
			pre[i][j]=pre[i][j-1]*2+s[j]-'0';
		for(int j=1;j<=l;j++)
			last[i][j]=(1<<(j-1))*(s[l-j+1]-'0')+last[i][j-1];
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=l;j++)
			if(pre[i][j]==last[i-1][j])a[i]=j;
		a[i]+=a[i-1];
	}
	for(int i=2;i<=n;i++)
		g[i]=-0x3f3f3f3f;
	int S=1<<l;
	for(int i=0;i<S;i++)
		for(int j=0;j<=l;j++)
			f[i][j]=-0x3f3f3f3f;
	f[0][0]=0;
	for(int i=2;i<=n;i++)
	{
		g[i]=g[i-1]+a[i]-a[i-1];
		int now=0;
		for(int j=0;j<=l;j++)
			now=max(now,f[pre[i][j]][j]+j);
		g[i]=max(g[i],now+a[i-1]);
		for(int j=0;j<=l;j++)
			f[last[i-1][j]][j]=max(f[last[i-1][j]][j],now+a[i-1]-a[i]);
	}
	printf("%d",n*l-g[n]);
}