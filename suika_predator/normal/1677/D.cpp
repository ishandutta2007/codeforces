#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int main()
{
	ios_base::sync_with_stdio(false);
	int T,n,k;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		vector<int> a(n+1);
		long long ans=1;
		for(int i=1;i<=k+1;i++)ans=(ans*i)%MOD;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(i==1 and a[i]>0)
			{
				ans=0;
				continue;
			}
			else if(i==1)continue;
			if(i>n-k and a[i]>0)
			{
//				cerr<<"bad2 "<<i<<endl;
				ans=0;
				continue;
			}
			else if(i>n-k)continue;
			if(a[i]>i-1)
			{
//				cerr<<"bad1 "<<i<<endl;
				ans=0;
			}
			else if(a[i]==-1)
			{
				ans=ans*(k+i)%MOD;
			}
			else if(a[i]==0)
			{
//				cerr<<"mul "<<i<<endl;
				ans=ans*(k+1)%MOD;
			}
			else
			{
				//?
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}