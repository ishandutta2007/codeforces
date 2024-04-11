#include<bits/stdc++.h>
#define MAXN 405
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
string str[405];
int solve(int id,int color)
{
	int x=id*n,cnt=0;
	for(int i=x;i<x+n;i++)
		for(int j=0;j<n;j++)
			if(str[i][j]-'0'==color) cnt+=(i-x+j)&1; else cnt+=(i-x+j+1)&1;
	return cnt; 
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<4*n;i++)		
		cin>>str[i];
	int ans=INF;
	ans=min(ans,solve(0,0)+solve(1,0)+solve(2,1)+solve(3,1));
	ans=min(ans,solve(0,0)+solve(1,1)+solve(2,0)+solve(3,1));
	ans=min(ans,solve(0,0)+solve(1,1)+solve(2,1)+solve(3,0));
	ans=min(ans,solve(0,1)+solve(1,0)+solve(2,0)+solve(3,1));
	ans=min(ans,solve(0,1)+solve(1,0)+solve(2,1)+solve(3,0));
	ans=min(ans,solve(0,1)+solve(1,1)+solve(2,0)+solve(3,0));
	printf("%d\n",ans);
	return 0;
}