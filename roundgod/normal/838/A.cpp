#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
string str[MAXN];
int prime[MAXN];
bool is_prime[MAXN];
int sum[MAXN][MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            prime[p++]=i;
            for(int j=2*i;j<=n;j+=i) is_prime[j]=false;
        }
    }
    return p;
}
int find_res(int x,int y,int len)
{
	if(x>=n||y>=m) return 0;
	int area=min(len,n-x)*min(len,m-y);
	if(area==len*len)
	{
		int cnt=sum[x+len][y+len]-sum[x+len][y]-sum[x][y+len]+sum[x][y];
		return min(cnt,len*len-cnt);
	}
	else 
	{
		int cnt=len*len-area;
		cnt+=sum[min(x+len,n)][min(y+len,m)]-sum[min(x+len,n)][y]-sum[x][min(y+len,m)]+sum[x][y];
		return min(cnt,len*len-cnt);
	}
}
int solve(int x)
{
	int tn=((n-1)/x+1)*x,tm=((m-1)/x+1)*x;
	int res=0;
	for(int i=0;i<tn/x;i++)
		for(int j=0;j<tm/x;j++)
			res+=find_res(i*x,j*x,x);
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	int p=sieve(max(n,m));
	for(int i=1;i<=n;i++)
		cin>>str[i];
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			sum[i][j]=sum[i][j-1]+(str[i][j-1]=='0'?1:0);
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++)
			sum[i][j]+=sum[i-1][j];
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d",sum[i][j]);
		puts("");
	}*/
	int ans=INF;
	for(int i=0;i<p;i++)
	{
		//printf("%d %d\n",prime[i],ans);
		ans=min(ans,solve(prime[i]));
	}
	printf("%d\n",ans);
	return 0;
}