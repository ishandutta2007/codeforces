#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

//s.max_load_factor(0.25);s.reserve(2048);

long long b[200001];
long long a[200001];
long long n;

int main ()
{
	long long i,maxi,mini;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;

	for(i=0;i<n;i++)
		cin>>b[i];

	maxi=b[0];
	mini=b[0];

	for(i=1;i<n;i++)
	{
		maxi=max(maxi,b[i]);
		mini=min(mini,b[i]);
	}

	if(mini==maxi)
	{
		if(mini==0)
		{
			cout<<"YES\n";

			for(i=0;i<n;i++)
				cout<<"1 ";
			cout<<"\n";

			return 0;
		}

		cout<<"NO\n";

		return 0;
	}

	bool boo=false;
	int x;

	for(i=1;i<n;i++)
		if(b[i]>b[i-1])
		{
			boo=true;
			x=i;
			a[i]=b[i];
			a[i-1]=a[i]*1e9+b[i-1];
		}

	if(!boo)
	{
		x=0;
		a[0]=b[0];
		a[n-1]=a[0]*1e9+b[n-1];
	}

	for(i=x-2;i>=0;i--)
		a[i]=b[i]+a[i+1];

	if(x!=n-1 && x!=0)
		a[n-1]=a[0]+b[n-1];

	for(i=n-2;i>x;i--)
		a[i]=b[i]+a[i+1];

	cout<<"YES\n";

	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";

	return 0;
}