#include<bits/stdc++.h>
using namespace std;
int t,n,k;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		if(n&1)
		{
			if(k&1)
			{
				if(n>=k)
				{
					puts("YES");
					for(int i=1;i<k;i++)
						cout<<1<<" ";
					cout<<n-k+1<<endl;
				}
				else
					puts("NO");
			}
			else
				puts("NO");
		}
		else
		{
			if(k&1)
			{
				if(n>=2*k)
				{
					puts("YES");
					for(int i=1;i<k;i++)
						cout<<2<<" ";
					cout<<n-2*k+2<<endl;
				}
				else
					puts("NO");
			}
			else
			{
				if(n>=k)
				{
					puts("YES");
					for(int i=1;i<k;i++)
						cout<<1<<" ";
					cout<<n-k+1<<endl;
				}
				else
					puts("NO");
			}
		}
	}
	return 0;
}