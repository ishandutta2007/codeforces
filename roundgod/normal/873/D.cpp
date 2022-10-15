#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
void solve(int x,int y,int z)
{
	if(y==1)
	{
		for(int i=1;i<=x;i++)
			printf("%d ",i+z);
		return;
	}
	else 
	{
		int l=x/2,r=x-l,mid=(y-1)/2;
		if(mid&1)
		{
			solve(l,mid,z+r);
			solve(r,mid,z);
		}
		else
		{
			solve(l,mid-1,z+r);
			solve(r,mid+1,z);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	if(k%2==0||k>n*2-1)
	{
		puts("-1");
		return 0;
	}
	solve(n,k,0);
	return 0;
}