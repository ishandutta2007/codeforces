#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
int x[N];
int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	int ans=inf;
	for (int i=1;i<=n;i++) //i
	{
		int tmp=0;
		for (int j=1;j<=n;j++)
		{
			tmp+=abs(x[i]-x[j])%2;
		}
		ans=min(ans,tmp);
	} 
	cout<<ans<<endl;
}