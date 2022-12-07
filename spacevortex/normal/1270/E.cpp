#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n;
int x[N],y[N],pd[2];
int main()
{
	int i,m,nx,ny;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
	}
	while(true)
	{
		pd[0]=pd[1]=0;
		for(i=1;i<=n;i++)
		{
			if((x[i]+y[i])%2==0) pd[0]=1;
			else pd[1]=1;
		}
		if(pd[0]&&pd[1])
		{
			m=0;
			for(i=1;i<=n;i++)
			{
				if((x[i]+y[i])%2==0) m++;
			}
			printf("%d\n",m);
			for(i=1;i<=n;i++)
			{
				if((x[i]+y[i])%2==0) printf("%d ",i);
			}
			return 0;
		}
		if(pd[1])
		{
			for(i=1;i<=n;i++) x[i]++;
		}
		for(i=1;i<=n;i++) 
		{
			nx=(x[i]+y[i])/2;ny=(x[i]-y[i])/2;
			x[i]=nx;y[i]=ny;
		}
	}
	return 0;
}