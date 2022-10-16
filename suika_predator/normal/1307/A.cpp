#include<bits/stdc++.h>
using namespace std;
int n,d,T;
int a[233];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int cur=0;
		for(int i=2;i<=n;i++)
		{
			while(a[i]&&cur+i-1<=d)
			{
				a[1]+=1;
				a[i]-=1;
				cur+=i-1;
			}
		}
		cout<<a[1]<<endl;
	}
	
	return 0;
}