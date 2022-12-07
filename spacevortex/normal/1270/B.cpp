#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=4e5+50;
ll n;
ll a[N];
void Solve()
{
	ll i,p;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	p=1;
	for(i=2;i<=n;i++)
	{
		if(a[i]-a[p]>=i-p+1) 
		{
			cout<<"YES"<<endl;
			cout<<p<<" "<<i<<endl;
			return ;
		}
		if(a[i]-i+1<a[p]-p+1) p=i;
	}
	reverse(a+1,a+n+1);
	p=1;
	for(i=2;i<=n;i++)
	{
		if(a[i]-a[p]>=i-p+1) 
		{
			cout<<"YES"<<endl;
			cout<<n-i+1<<" "<<n-p+1<<endl;
			return ;
		}
		if(a[i]-i+1<a[p]-p+1) p=i;
	}
	cout<<"NO"<<endl;
}
int main()
{
	//freopen("a.in","r",stdin);
	ios::sync_with_stdio(false);
	ll T;
	cin>>T;
	while(T--) Solve();
}