#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=1e9+7;
long long fact[11];
long long ans;
int mp[11][11],qwq[11][11],ok[11][11];
int n,m,k,pcnt;
int W(int x,int y)
{
	if(x-y<=0)return fact[x];
	return fact[x]/fact[x-y];
}
inline bool chk()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			qwq[i][j]=qwq[i-1][j]|qwq[i][j-1];
			if(mp[i][j]==0)continue;
			if(qwq[i][j]&(1<<(mp[i][j]-1)))
				return false;
			qwq[i][j]|=1<<(mp[i][j]-1);
		}
	}
	return true;
}
void s(int x,int y,int cnt)
{
	if(cnt>k)return;
	if(y==m+1)
	{
		x++,y=1;
	}
//	cout<<x<<' '<<y<<' '<<cnt<<endl;
	if(x==n+1)
	{
/*
		cout<<endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<mp[i][j]<<' ';
			}
			cout<<endl;
		}
		cout<<cnt<<endl;
*/
		ans+=W(k-pcnt,cnt-pcnt);
		return;
	}
	if(mp[x][y])
	{
		qwq[x][y]=qwq[x][y-1]|qwq[x-1][y];
		if(qwq[x][y]&(1<<(mp[x][y]-1)))return;
		qwq[x][y]|=1<<(mp[x][y]-1);
		s(x,y+1,cnt);
	}
	else
	{
		for(int i=1;i<=cnt+1;i++)
		{
			if(ok[x][y]&(1<<(i-1)))continue;
			qwq[x][y]=qwq[x][y-1]|qwq[x-1][y];
			if(qwq[x][y]&(1<<(i-1)))continue;
			qwq[x][y]|=1<<(i-1);
			s(x,y+1,max(i,cnt));
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	if(n+m-1>k)
	{
		printf("0\n");
		return 0;
	}
	fact[0]=1;
	for(int i=1;i<=k;i++)fact[i]=fact[i-1]*i%MOD;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&mp[i][j]);
		}
	}
	for(int t=1;t<=k;t++)
	{
		int q=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(mp[i][j]==t)
				{
					if(!q)pcnt++;
					mp[i][j]=pcnt,q=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j])
			{
				for(int x=1;x<=i;x++)
				{
					for(int y=1;y<=j;y++)
					{
						ok[x][y]|=1<<(mp[i][j]-1);
					}
				}
				for(int x=i;x<=n;x++)
				{
					for(int y=j;y<=m;y++)
					{
						ok[x][y]|=1<<(mp[i][j]-1);
					}
				}
			}
		}
	}
	s(1,1,pcnt);
	printf("%lld\n",ans%MOD);
	return 0;
}