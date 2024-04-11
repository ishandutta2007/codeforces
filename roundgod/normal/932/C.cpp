#include<bits/stdc++.h>
#define MAXN 3005
#define F first
#define S second
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a,b;
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	int t1=-1,t2=-1;
	for(int i=0;i*a<=n;i++)
	{
		if((n-i*a)%b==0)
		{
			t1=i;
			t2=(n-i*a)/b;
			break;
		}
	}
	if(t1==-1&&t2==-1)
	{
		puts("-1");
		return 0;
	}
	int cnt=1;
	for(int i=1;i<=t1;i++)
	{
		cnt++;
		for(int j=1;j<=a-1;j++)
		{
			printf("%d ",cnt);
			cnt++;
		}
		printf("%d ",cnt-a);
	}
	for(int i=1;i<=t2;i++)
	{
		cnt++;
		for(int j=1;j<=b-1;j++)
		{
			printf("%d ",cnt);
			cnt++;
		}
		printf("%d ",cnt-b);
	}
	return 0;
}