#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int a[23333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		int c0=0,c1=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]%2==0)c0++;
			else c1++;
		}
		if(!c1)cout<<"No"<<endl;
		else if(c1%2==0&&k==n)cout<<"No"<<endl;
		else if(c0==0&&k%2==0)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}