#include<bits/stdc++.h>
using namespace std;
int n,m,k;
char s[1111][1111];
int pa[1111111];
int find(int x){return pa[x]?pa[x]=find(pa[x]):x;}
void onion(int u,int v)
{
	int pu=find(u),pv=find(v);
	if(pu!=pv)pa[pu]=pv;
}
int rh[1111],ch[1111];
int rl[1111],rr[1111],cl[1111],cr[1111];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)rl[i]=m+1,rr[i]=0;
	for(int j=1;j<=m;j++)cl[j]=n+1,cr[j]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='#')
			{
				rh[i]=ch[j]=1;
				rl[i]=min(rl[i],j);
				rr[i]=max(rl[i],j);
				cl[j]=min(cl[j],i);
				cr[j]=max(cr[j],i);
			}
			if(i>1&&s[i][j]=='#'&&s[i-1][j]=='#')onion((i-1)*m+j,(i-2)*m+j);
			if(j>1&&s[i][j]=='#'&&s[i][j-1]=='#')onion((i-1)*m+j,(i-1)*m+j-1);
		}
	}
	int fr=0,fc=0;
	for(int i=1;i<=n;i++)
	{
//		cerr<<i<<' '<<rh[i]<<' '<<rl[i]<<' '<<rr[i]<<endl;
		if(!rh[i])fr=1;
		else
		{
			for(int j=rl[i];j<=rr[i];j++)
			{
				if(s[i][j]=='.')
				{
					cout<<-1<<endl;
					return 0;
				}
			}
		}
	}
	for(int j=1;j<=m;j++)
	{
		if(!ch[j])fc=1;
		else
		{
			for(int i=cl[j];i<=cr[j];i++)
			{
				if(s[i][j]=='.')
				{
					cout<<-1<<endl;
					return 0;
				}
			}
		}
	}
	if(fr^fc)
	{
		cout<<-1<<endl;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='.')continue;
			int t=(i-1)*m+j;
			if(!pa[t])ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}