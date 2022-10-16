#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,x,i,j,k,ans=0;
int main()
{
	cin>>n>>m;
	for (i=1; i<n; i++)
	{
		cin>>x;
		if (j+x>=m) ans+=(x+j)/m,j=(x+j)%m;
			else if (j>0) ans++,j=0;
				 else j=x;
	}
	cin>>x;
	if ((j+x)%m==0) ans+=(x+j)/m; else ans+=(x+j)/m+1;
	cout<<ans;
	return 0;
}