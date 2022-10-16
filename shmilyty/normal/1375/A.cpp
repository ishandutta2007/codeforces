#include<bits/stdc++.h>
using namespace std;
int t,n,a;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			if(i&1)
				cout<<abs(a)<<" ";
			else
				cout<<-abs(a)<<" ";
		}
		cout<<"\n";
	}
	return 0;
}