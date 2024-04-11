#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 30
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN],b[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		int ans=INF;
		for(int j=0;j<=16;j++)
		{
			int y=(x+j)%32768;
			int cnt=j;
			while(y!=0) y=y*2%32768,cnt++;
			ans=min(ans,cnt); 
		}
		printf("%d%c",ans,i==n?'\n':' ');
	}
	return 0;
}