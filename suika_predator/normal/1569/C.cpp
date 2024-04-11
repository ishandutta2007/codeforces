#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int a[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	int T,n;
	cin>>T;
	while(T--)
	{
		int fmax=0,fmaxc=0,smax=0,smaxc=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]>fmax)
			{
				smax=fmax;
				smaxc=fmaxc;
				fmax=a[i];
				fmaxc=1;
			}
			else if(a[i]==fmax)
			{
				fmaxc++;
			}
			else if(a[i]>smax)
			{
				smax=a[i];
				smaxc=1;
			}
			else if(a[i]==smax)
			{
				smaxc++;
			}
		}
		if(fmaxc>=2)
		{
			long long ans=1;
			for(int i=1;i<=n;i++)
				ans=ans*i%MOD;
			cout<<ans<<endl;
		}
		else if(fmax-smax>1)
		{
			cout<<0<<endl;
		}
		else
		{
			long long ans=1;
			for(int i=1;i<=n;i++)
			{
				if(i==smaxc+1)continue;
				ans=ans*i%MOD;
			}
			ans=ans*smaxc%MOD;
			cout<<ans<<endl;
		}
	}
	
	return 0;
}