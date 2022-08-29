#include<cstdio>
#include<set>
#include<algorithm>
#include<iostream>
using namespace std;
set<long long> s;
long long sumb[100010],suma;
int l,r,x,n,m,q,b[100010];
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		suma+=(i%2?1:-1)*x;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		if(i<=n)
		{
			sumb[1]+=(i%2?-1:1)*b[i];
		}
		else
		{
			sumb[i-n+1]=(n%2?-1:1)*b[i]-(sumb[i-n]+b[i-n]);
		}
	}
	for(int i=1;i<=m-n+1;i++)
	{
		s.insert(sumb[i]);
	}
	set<long long>::iterator it,it2;
	it=s.upper_bound(-suma);
	if(it==s.end())
	{
		it--;
	}
	it2=it;
	if(it2!=s.begin())
	{
		it2--;
	}
	printf("%I64d\n",min(abs(*it+suma),abs(*it2+suma)));
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&l,&r,&x);
		if((r-l+1)%2)
		{
			suma+=(l%2?1:-1)*x;
		}
		it=s.upper_bound(-suma);
		if(it==s.end())
		{
			it--;
		}
		it2=it;
		if(it2!=s.begin())
		{
			it2--;
		}
		printf("%I64d\n",min(abs(*it+suma),abs(*it2+suma)));
	}
	return 0;
}