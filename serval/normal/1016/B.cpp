#include <cstdio>
using namespace std;
int n,m,q;
int i,j;
char s[1005];
char t[1005];
int nx[1005];
int ck[1005];
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	scanf("%s",s+1);
	scanf("%s",t+1);
	for (i=2;i<=m;i++)
	{
		while (j&&t[j+1]!=t[i])
			j=nx[j];
		if (t[j+1]==t[i])
			j++;
		nx[i]=j;
	}
	j=0;
	for (i=1;i<=n;i++)
	{
		while (j&&t[j+1]!=s[i])
			j=nx[j];
		if (t[j+1]==s[i])
			j++;
		if (j==m)
		{
			ck[i]=1;
			j=nx[j];
		}
	}
	for (i=1;i<=n;i++)
		ck[i]+=ck[i-1];
	while (q--)
	{
		scanf("%d%d",&i,&j);
		if (i+m-2<j)
			printf("%d\n",ck[j]-ck[i+m-2]);
		else
			printf("0\n");
	}
	return 0;
}