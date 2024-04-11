#include<bits/stdc++.h>
#define MAXN 2005
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,m,k;
int a[MAXN];
char mp[MAXN][MAXN];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	int cnt=0;
	for(int i=0;i<n;i++)
		scanf("%s",mp[i]);
	if(k==1)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(mp[i][j]=='.') cnt++;
		printf("%d\n",cnt);
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		int now=0,res=0;
		while(now<m)
		{
			if(mp[i][now]=='.') res++; else res=0;
			if(res>=k) cnt++; 
			now++;
		}
	}
	for(int i=0;i<m;i++)
	{
		int now=0,res=0;
		while(now<n)
		{
			if(mp[now][i]=='.') res++; else res=0;
			if(res>=k) cnt++; 
			now++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}