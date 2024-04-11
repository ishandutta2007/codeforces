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
		for(int i=n;i>=1;i--)
		{
			if(a[i]%(i+1)!=0)
			{
				for(int j=i;j<n;j++)
					a[j]=a[j+1];
				n--;
				i=n+1;
			}
		}
		if(n==0)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}