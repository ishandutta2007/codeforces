#include<bits/stdc++.h>
using namespace std;
char s[1111111],ans[1111][1111];
int n,k,l;
int main()
{
	scanf("%d%d%d %s",&n,&l,&k,s+1);
	sort(s+1,s+n*l+1);
	
	int cnt=0,t=1;
	for(int i=1;i<=l;i++)
	{
		for(int j=t;j<=k;j++)
		{
//			cerr<<i<<' '<<j<<' '<<s[cnt+1]<<endl;
			ans[j][i]=s[++cnt];
			if(s[cnt]!=s[cnt-1])
			{
//				cerr<<"change"<<endl;
				t=j;
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=l;j++)
			if(!ans[i][j])ans[i][j]=s[++cnt];
	for(int i=1;i<=n;i++)
		printf("%s\n",ans[i]+1);
	return 0;
}