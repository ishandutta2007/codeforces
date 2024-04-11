#include<bits/stdc++.h>
using namespace std;
int t,n,k;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		int s=0,m=0;
		for(int i=1;i<=n;i++)
		{
			int a;
			scanf("%d",&a);
			if(a&1)
				s++;
			else
				m++;
		}
		if(s==0)
		{
			puts("no");
			continue;
		}
		bool flag=1;
		for(int i=1;i<=s&&i<=k;i+=2)
			if(k-i<=m)
			{
				cout<<"yes"<<endl;
				flag=0;
				break;
			}
		if(flag)
			cout<<"no"<<endl;
	}
	return 0;
}