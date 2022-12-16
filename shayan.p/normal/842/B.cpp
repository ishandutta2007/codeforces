#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int r,d,n;
double f(ll x,ll y)
{
	return sqrt((x*x)+(y*y));
}
int main()
{
	int ans=0;
	cin>>r>>d>>n;
	int x,y,ri;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y>>ri;
		double t=f(x,y);
		if(t-ri>=r-d&&t+ri<=r)
		ans++;
	}
	cout<<ans;
}