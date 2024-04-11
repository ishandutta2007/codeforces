#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,k,cnt;
vector<int> a,x;
void work()
{
	int maxx=-114514114514114514;
	for(int i=0;i<x.size();i++)
		maxx=max(maxx,x[i]);
	for(int i=0;i<x.size();i++)
		x[i]=maxx-x[i];
}
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		x.clear();
		a.clear();
		for(int i=1;i<=n;i++)
		{
			int b;
			scanf("%lld",&b);
			x.push_back(b); 
		}
		k--;
		work();
		for(int i=0;i<x.size();i++)
			a.push_back(x[i]);
		work();
		if(n==1)
			puts("0");
		else
		{
			if(k&1)
				for(int i=0;i<x.size();i++)
					cout<<x[i]<<" ";
			else
				for(int i=0;i<a.size();i++)
					cout<<a[i]<<" ";
			cout<<endl;
		}
	}
	return 0;
}