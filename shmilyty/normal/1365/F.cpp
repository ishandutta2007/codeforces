#include<bits/stdc++.h>
using namespace std;
int t,n,a[501],b[501];
map<pair<int,int>,int> p;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		p.clear();
		bool flag=1;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;2*i<=n;i++)
		{
			p[make_pair(a[i],a[n-i+1])]++;
			p[make_pair(a[n-i+1],a[i])]++;
		}	
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		for(int i=1;2*i<=n;i++)
			if(!p[make_pair(b[i],b[n-i+1])])
			{
				puts("No");
				flag=0;
				break;
			}
			else
			{
				p[make_pair(b[i],b[n-i+1])]--;
				p[make_pair(b[n-i+1],b[i])]--;
			}
		if(!flag)
			continue;
		if(n&1)
			if(a[n/2+1]!=b[n/2+1])
			{
				puts("No");
				continue;
			}	
		puts("Yes");
	}
	return 0;
}