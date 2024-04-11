#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x;
int a[2333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>x;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		int s=0,fl=1;
		for(int i=1;i<=n;i++)
		{
			s+=a[i];
			if(s==x)
			{
				if(a[i]!=a[n])
					swap(a[i],a[n]);
				else fl=0;
				break;
			}
		}
		if(fl)
		{
			cout<<"YES"<<endl;
			for(int i=1;i<=n;i++)
				cout<<a[i]<<' ';
			cout<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}