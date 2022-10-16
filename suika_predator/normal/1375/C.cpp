#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int a[333333];
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
		if(a[1]<a[n])cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}