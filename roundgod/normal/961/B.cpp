#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int main()
{
	int ans=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x==1) {ans+=a[i]; a[i]=0;}
	}
	int s=0,res=0;
	for(int i=1;i<=min(n,k);i++)
		s+=a[i];
	res=max(res,s);
	for(int i=k+1;i<=n;i++)
	{
		s+=a[i];
		s-=a[i-k];
		res=max(res,s);
	}
	printf("%d\n",ans+res);
	return 0;
}