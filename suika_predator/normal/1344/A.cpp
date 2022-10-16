#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int a[233333],b[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=0;i<n;i++)b[i]=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			a[i]%=n;
			if(a[i]<0)a[i]+=n;
			b[(i+a[i])%n]++;
		}
		int fl=1;
		for(int i=0;i<n;i++)
		{
			if(!b[i]||b[i]>1)fl=0;
		}
		if(fl)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}