#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int n,m,i,j,k;
bool ban[300][300];
char s[100005],ss[5];
int f[100005][300];

void Min(int &a,int b){if(b<a)a=b;}

int main()
{
	scanf("%s",s+1);
	scanf("%d",&m);
	for(;m;--m)
	{
		scanf("%s",ss);
		ss[0]-='a';ss[1]-='a';
		ban[ss[0]][ss[1]]=ban[ss[1]][ss[0]]=true;
	}
	n=strlen(s+1);
	for(i=1;i<=n;++i)s[i]-='a';
	for(i=0;i<26;++i)f[0][i]=1000000000;
	for(i=1;i<=n;++i)
	{
		for(j=0;j<26;++j)f[i][j]=f[i-1][j]+1;
		Min(f[i][s[i]],i-1);
		for(j=0;j<26;++j)
		if(!ban[s[i]][j])
		Min(f[i][s[i]],f[i-1][j]);
	}
	k=10000000;
	for(i=0;i<26;++i)Min(k,f[n][i]);
	printf("%d\n",k);
}