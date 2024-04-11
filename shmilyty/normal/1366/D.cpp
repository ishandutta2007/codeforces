#include<bits/stdc++.h>
using namespace std;
int n,a,pri[10000001],d1[500001],d2[500001];
vector<int> p;
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=10000000;i++)
		if(pri[i]==0)
		{
			p.push_back(i);
			for(int l=i+i;l<=10000000;l+=i)
				pri[l]=1;
		}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
        if(pri[a]==0)
        {
            d1[i]=d2[i]=-1;
            continue;
        }
		for(int l:p)
			if(l*l<=a&&a%l==0)
			{
				d1[i]=l;
				while(a%l==0)
					a/=l;
				if(a==1)
				{
					d1[i]=d2[i]=-1;
					break;	
				}	
				d2[i]=a;
				break;
			} 
	}
	for(int i=1;i<=n;i++)
		cout<<d1[i]<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++)
		cout<<d2[i]<<" ";
	return 0; 
}