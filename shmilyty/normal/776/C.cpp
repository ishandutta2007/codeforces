#include<bits/stdc++.h>
using namespace std;
const long long linf = 1e14 ;
set<long long> a;
map<long long,long long> x;
long long num[100010],n,k,ans;
int main()
{
	scanf("%lld%lld", &n, &k) ;
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld", &num[i]),
		num[i]+=num[i-1];
	}
	a.insert(1);
	long long tmp=k;
	for(long long i=1;i<=60;i++)
	{
		if(tmp>linf)
			break;
		a.insert(tmp);
		tmp*=k;
	}
	x[0]=1;
	for(long long i=1;i<=n;i++)
	{
		for (set<long long>::iterator it=a.begin();it!=a.end();it++)
			ans+=x[num[i]-*it];
		x[num[i]]++;
	}
	printf("%lld\n", ans) ;
	return 0;
}