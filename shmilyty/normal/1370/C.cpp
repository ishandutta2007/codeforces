#include<bits/stdc++.h>
#define a {cout<<"Ashishgup"<<endl;continue;}
#define f {cout<<"FastestFinger"<<endl;continue;}
using namespace std;
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n==1)
			f
		if(n==2||(n&1))
			a
		int tot=0;
		for(int i=3;i*i<=n;i+=2)
			if(n%i==0)
				while(n%i==0)
				{
					n/=i;
					tot++;
				}
		for(int i=2;i*i<=n;i++)
			if(n%i==0)
			{
				int tmp=n/i;
				if(tmp&1)
					while(n%tmp==0)
					{
						n/=tmp;
						tot++;
					}
			}
		if(n==2)
		{
			if(tot!=1)
				a
			f
		}
		if(tot)
			a
		f
	}
	return 0;
}