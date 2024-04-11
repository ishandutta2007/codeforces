#include<bits/stdc++.h>

using namespace std;

const int maxn=200020;

int n,maxx;

int a[maxn];

long long ans;

long long solve(int x)
{
	long long tmp=0;
	int tp=0,tp2;
	for(int i=0;i<=maxx/a[x];i++)
	{
		tp2=lower_bound(a+1,a+n+1,a[x]*(i+1))-a-1;
		tmp+=1ll*a[x]*i*(tp2-tp);
		//printf("%d %d\n",x,tmp);
		tp=tp2;
	}
	return tmp;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	maxx=a[n];
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
			ans=max(ans,solve(i));
	}
	cout<<ans;
	return 0;
}