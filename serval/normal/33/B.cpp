#include <cstdio>
using namespace std;
char s[100005],t[100005];
char ans[100005];
int ret;
int n,i,j,k,w,q;
char a,b;
int d[26][26];
int main()
{
	scanf("%s",s+1);
	scanf("%s",t+1);
	scanf("%d",&n);
	for (i=0;i<26;i++)
		for (j=0;j<26;j++)
			if (i!=j)
				d[i][j]=-1;
	for (i=1;i<=n;i++)
	{
		scanf("%c",&a);
		while (a<'a'||a>'z')
			scanf("%c",&a);
		scanf("%c",&b);
		while (b<'a'||b>'z')
			scanf("%c",&b);
		scanf("%d",&w);
		if (w<d[a-'a'][b-'a']||d[a-'a'][b-'a']==-1)
			d[a-'a'][b-'a']=w;
	}
	for (k=0;k<26;k++)
		for (i=0;i<26;i++)
			for (j=0;j<26;j++)
				if (i!=k&&j!=k&&i!=j)
					if (d[i][k]!=-1&&d[k][j]!=-1)
						if (d[i][k]+d[k][j]<d[i][j]||d[i][j]==-1)
							d[i][j]=d[i][k]+d[k][j];
	for (i=1;s[i];i++)
	{
		if (t[i]==0)
		{
			printf("-1\n");
			return 0;
		}
		q=1000000000;
		for (w=0;w<26;w++)
		{
			j=d[s[i]-'a'][w];
			k=d[t[i]-'a'][w];
			if (j==-1||k==-1)
				continue;
			if (j+k<=q)
			{
				q=j+k;
				ans[i]=w+'a';
			}
		}
		if (q==1000000000)
		{
			printf("-1\n");
			return 0;
		}
		ret+=q;
	}
	if (t[i]!=0)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n",ret);
	printf("%s\n",ans+1);
	return 0;
}