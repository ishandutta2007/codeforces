#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main()
{
	int t,n,i,j,tot,sum,p,A,B;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
			cin>>a[i];
		tot=A=B=p=0;
		for(i=1,j=n;i<=j;)
		{
			sum=0;
			for(;i<=j&&sum<=p;i++)
				sum+=a[i];
			if(i<=j)
				tot+=2;
			else
				tot++;
			A+=sum;
			p=sum;
			sum=0;
			for(;i<=j&&sum<=p;j--)
				sum+=a[j];
			B+=sum;
			p=sum; 
		}
		cout<<tot<<' '<<A<<' '<<B<<endl;
	}
	return 0;
}