#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int a[2][2][N];
int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n>>m;
		for (int i=1;i<=n;i++)
			cin>>a[0][0][i]>>a[0][1][i]>>a[1][0][i]>>a[1][1][i];
		if (m%2==1) 
		{
			cout<<"NO"<<endl;
			continue;
		}
		bool flag=1;
		for (int i=1;i<=n;i++)
		{
			if (a[1][0][i]==a[0][1][i])
			{
				cout<<"YES"<<endl;
				flag=0;
				break;
			}
		}
		if (flag) cout<<"NO"<<endl;
	}
}