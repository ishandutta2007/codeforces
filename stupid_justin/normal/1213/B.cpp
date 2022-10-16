#include<bits/stdc++.h>
using namespace std;
const int N=105;
const int M=1e6+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
int dis[N][N];
int l[N][N];
int p[M];
int a[N];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		int ans=0;
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int minx=a[n];
		for (int i=n-1;i>=1;i--)
		{
			if (a[i]>minx) ans++;
			minx=min(a[i],minx);
		}
		cout<<ans<<endl;
	}
}