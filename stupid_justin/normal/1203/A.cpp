#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[N];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		bool flag1=1,flag2=1;;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=2;i<=n;i++) 
		{
			if (a[i]!=a[i-1]+1 && a[i]!=a[i-1]+1-n) flag1=0;
		}
		for (int i=2;i<=n;i++) 
		{
			if (a[i]!=a[i-1]-1 && a[i]!=a[i-1]-1+n) flag2=0;
		}
		if (flag1 || flag2) cout<<"YES"<<endl;else cout<<"NO"<<endl;
	}
}