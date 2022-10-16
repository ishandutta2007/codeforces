#include<bits/stdc++.h>
using namespace std;
const int N=100005;
const int MOD1=1e9+7;
const int MOD2=998244353;
int q,n,m,ans,max1,max2,a;
//int a[N];
int main()
{
	cin>>q;
	while(q--)
	{
		cin>>n;
		if (n<=2)
		{
			for (int i=1;i<=n;i++) cin>>a;
			cout<<"0"<<endl;
		}
		else
		{
			cin>>a;
			max1=a;
			max2=0;
			for (int i=2;i<=n;i++)
			{
				cin>>a;
				if (a>max2)
				{
					if (a>max1) 
					{
						max2=max1;max1=a;
					}
					else
					max2=a;
				}
			}
			cout<<min(n-2,min(max1,max2)-1)<<endl;
		}
		
	}
	
	
}