#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5e4+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[N],dir[N];
int main()
{
	int n,ans=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if (a[1]!=1) a[1]--;
	for (int i=2;i<=n;i++) 
	{
		if (a[i-1]==0)
		{
			int m=dir[i-1];
			if (a[i]-a[m]>=2) a[i]--;
			if (a[i]==a[m]) a[i]++;
			if (a[i]<a[m])
			{
				a[i]=0;
				dir[i]=m;
			}
		}
		else
		{
			if (a[i]-a[i-1]>=2) a[i]--;
			if (a[i]==a[i-1]) a[i]++;
			if (a[i]<a[i-1]) 
			{
				a[i]=0;dir[i]=i-1;
			}
		}	
	}
	for (int i=1;i<=n;i++) if (a[i]!=0) ans++;
	cout<<ans<<endl;
}