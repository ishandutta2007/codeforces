#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,ans;
char s[N];
int a[N],b[N],t[30];
void Solve()
{
	int i,j;
	scanf("%d",&n);
	scanf("%s",s+1);for(i=1;i<=n;i++) a[i]=s[i]-'a'+1;
	scanf("%s",s+1);for(i=1;i<=n;i++) b[i]=s[i]-'a'+1;
	ans=0;
	for(i=1;i<=26;i++)
	{
		memset(t,0,sizeof(t));
		for(j=1;j<=n;j++)
		{
			if(b[j]==i)
			{
				if(a[j]>i) 
				{
					puts("-1");
					return ;
				}
				else if(a[j]<i)
				{
					t[a[j]]=1;
				}
			}
		}
		for(j=1;j<=26;j++) ans+=t[j];
		for(j=1;j<=n;j++) if(t[a[j]]) a[j]=i;
	}
	printf("%d\n",ans);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) Solve();
	return 0;
}