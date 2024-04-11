#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		ll n,a,b;
		cin>>n>>a>>b;
		if (a==1) a=n+1;
		for (ll i=1;i<=n;i*=a) if ((n-i)%b==0){ cout<<"Yes\n";goto aa;}
		cout<<"No\n";aa:;
	}
}