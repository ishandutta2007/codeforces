#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int a[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int ls=0,ok=1;
		for(int i=1;i<n;i++)
		{
			if(a[i]>a[i+1])
			{
				for(int l=ls+1,r=i;l<r;l++,r--)
				{
					swap(a[l],a[r]);
				}
				ls=i;
			}
		}
		if(ls<n)
			for(int l=ls+1,r=n;l<r;l++,r--)
			{
				swap(a[l],a[r]);
			}
//		for(int i=1;i<=n;i++)cerr<<i<<' '<<a[i]<<endl;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=n+1-i)
			{
				ok=0;
				break;
			}
		}
		cout<<(ok?"Yes":"No")<<endl;
	}
	
	return 0;
}