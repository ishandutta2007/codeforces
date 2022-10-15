#include<bits/stdc++.h>
#define MAXN 200005
#define MAXS 305
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,t1,t2,t,query1[MAXN][2],query2[MAXN],st[MAXN];
int main()
{
	scanf("%d",&n);
	t1=t2=0;
	for(int i=1;i<=n;i++)
	{
		int type;
		scanf("%d",&type);
		if(type==1||type==3||type==5) query1[++t1][0]=type;
		else query2[++t2]=type;
		if(type==1||type==3) scanf("%d",&query1[t1][1]);
	}
	int ans=0;
	st[0]=0;t=1;
	for(int i=1;i<=t2;i++)
	{
		if(query2[i]==4) st[t++]=0;
		if(query2[i]==6) st[t++]=1;
		if(query2[i]==2) 
		{
			while(st[t-1]==1)
			{
				ans++;
				t--;
			}
		}
	}
	int speed=query1[1][1],limit=301;
	st[0]=301;t=1;
	for(int i=2;i<=t1;i++)
	{
		if(query1[i][0]==1) speed=query1[i][1];
		else if(query1[i][0]==3) st[t++]=query1[i][1];
		else st[t++]=301;
		while(speed>st[t-1])
		{
			ans++;
			t--;
		}
	}
	printf("%d\n",ans);
	return 0;
}