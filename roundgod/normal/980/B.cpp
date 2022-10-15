#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
char mp[4][MAXN];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<4;i++)
		for(int j=0;j<n;j++)
			mp[i][j]='.';
	puts("YES");
	if(k&1)
	{
		mp[1][n/2]='#';
		int t=(k-1)/2;
		if(k<=(n-2))
		{
			for(int i=n/2-1;i>=n/2-t;i--)
				mp[1][i]=mp[1][n-1-i]='#';
		}
		else
		{
			for(int i=1;i<=n-2;i++)
				mp[1][i]='#';
			mp[2][1]=mp[2][n-2]='#';
			k-=n;
			for(int i=2;i<2+k;i++)
				mp[2][i]='#';
		}
	}
	else
	{
		for(int i=1;i<=k/2;i++)
			mp[1][i]=mp[2][i]='#';
	}
	for(int i=0;i<4;i++)
		printf("%s\n",mp[i]);
	return 0;
}