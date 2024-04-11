#include <cstdio>
using namespace std;
bool map[30][30];
int n,i,j;
char s[100005],t[100005];
int ans;
char l[100005],r[100005];
int f[30];
int getf(int u)
{
	return f[u]?f[u]=getf(f[u]):u;
}
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%c",&s[i]);
		while (s[i]<'a'||s[i]>'z')
			scanf("%c",&s[i]);
	}
	for (i=1;i<=n;i++)
	{
		scanf("%c",&t[i]);
		while (t[i]<'a'||t[i]>'z')
			scanf("%c",&t[i]);
		map[s[i]-'a'+1][t[i]-'a'+1]=map[t[i]-'a'+1][s[i]-'a'+1]=1;
	}
	for (i=1;i<=26;i++)
		for (j=1;j<=26;j++)
			if (i!=j&&map[i][j])
				if (getf(i)!=getf(j))
				{
					ans++;
					l[ans]=i+'a'-1;
					r[ans]=j+'a'-1;
					f[getf(i)]=getf(j);
				}
	printf("%d\n",ans);
	for (i=1;i<=ans;i++)
		printf("%c %c\n",l[i],r[i]);
	return 0;
}