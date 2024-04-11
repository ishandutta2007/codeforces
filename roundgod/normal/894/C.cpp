#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int now=a[0];
	for(int i=1;i<n;i++)
		now=gcd(now,a[i]);
	if(now!=a[0])
	{
		puts("-1");
		return 0;
	}
	printf("%d\n",2*n-1);
	printf("%d ",a[0]);
	for(int i=1;i<n;i++)
		printf("%d %d ",a[i],a[0]);
	puts("");
	return 0;
}