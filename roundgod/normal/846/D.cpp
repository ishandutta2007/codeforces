#include<bits/stdc++.h>
#define MAXN 505
#define MAXM 505
#define MAXQ 250005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,q,x,y,t,mp[MAXN][MAXM];
bool valid[MAXN][MAXM];
bool C(int num)
{
	memset(valid,false,sizeof(valid));
	for(int i=1;i<=n;i++)
	{
		int now=1,j;
		while(now+k-1<=m)
		{
			for(j=now;j<=m;j++)
				if(mp[i][j]>num) break;
			if(j-now<k) {now=j+1; continue;}
			else
			{
				for(int p=now;p+k<=j;p++)
					valid[i][p]=true;
				now=j+1;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		int now=1,j;
		while(now+k-1<=n)
		{
			for(j=now;j<=n;j++)
				if(!valid[j][i]) break;
			if(j-now<k) {now=j+1; continue;}
			else return true;
		}
	}
	return false;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&q);
	int maxt=0;
	memset(mp,-1,sizeof(mp));
	for(int i=0;i<q;i++)
	{
		scanf("%d%d%d",&x,&y,&t);
		mp[x][y]=t;
		maxt=max(maxt,t);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mp[i][j]==-1) mp[i][j]=maxt+1;
	int l=-1,r=maxt+1;
	while(r-l>1)
	{
		int mid=(l+r)/2;
		if(C(mid)) r=mid; else l=mid;
	}
	printf("%d\n",r==maxt+1?-1:r);
	return 0;
}