#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,ans;
char a[105][5],b[105][5],c[1005],ch;

void dfs(int x)
{
	if(x>n)
	{
		int i,j,k;
		ch=c[1];
		for(i=2;i<=n;++i)
		{
			for(j=1;j<=m;++j)
			if(a[j][1]==ch&&a[j][2]==c[i])
			{
				ch=b[j][1];
				break;
			}
			if(j>m)return;
		}
		if(ch=='a')++ans;
		return;
	}
	for(char i='a';i<='f';++i)c[x]=i,dfs(x+1);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)scanf("%s%s",a[i]+1,b[i]+1);
	dfs(1);
	printf("%d\n",ans);
}