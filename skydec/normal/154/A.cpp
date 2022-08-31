#include<stdio.h>
#include<cstring>
#define MAXN 110000
using namespace std;
char str[MAXN];int n;
int f[MAXN][27];
bool go[27][27];
inline void Min(int &x,int y){if(y<x)x=y;}
int main()
{
	memset(f,63,sizeof f);
	scanf("%s",str+1);
	n=strlen(str+1);
	int k;scanf("%d",&k);
	while(k--)
	{
		char opt[5];scanf("%s",opt+1);
		go[opt[1]-'a'+1][opt[2]-'a'+1]=go[opt[2]-'a'+1][opt[1]-'a'+1]=1;
	}
	for(int i=1;i<=n;i++)
	f[i][str[i]-'a'+1]=i-1;
	for(int i=1;i<n;i++)
	for(int j=1;j<=26;j++)
	{
		if(go[j][str[i+1]-'a'+1]==0)
		Min(f[i+1][str[i+1]-'a'+1],f[i][j]);
		Min(f[i+1][j],f[i][j]+1);
	}
	int ans=2100000;
	for(int i=1;i<=26;i++)Min(ans,f[n][i]);
	printf("%d\n",ans);
	return 0;
}