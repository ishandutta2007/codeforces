#include<bits/stdc++.h>
#define MAXN 100005
#define F first
#define S second
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
ll p,k,a[MAXN];
ll get()
{
	ll x=p%k;
	if(x<0) x+=k;
	return x%k;
}
int main()
{
	scanf("%I64d%I64d",&p,&k);
	int cnt=0;
	while(p!=0)
	{
		a[cnt++]=get();
		p-=get();
		p/=(-k);
	}
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++)
		printf("%I64d ",a[i]);
	return 0;
}