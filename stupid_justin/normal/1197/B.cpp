#include<bits/stdc++.h>
using namespace std;
const int N=200005;
const int MOD1=1e9+7;
const int MOD2=998244353;
int q,n,m,ans,max1,max2;
int a[N];
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		if (a[i]==n)
		{
			max2=i;
		}
	}
	//max2
//	printf("max2=%d\n",max2);
	for (int i=1;i<=n;i++)
	{
		if (i<max2)
		{
			if (a[i]<a[i-1])
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
		if (i>max2)
		{
			if (a[i]>a[i-1])
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
	} 
	cout<<"YES"<<endl;
	return 0;
}