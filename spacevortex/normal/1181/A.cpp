#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll x,y,z,ans;
	cin>>x>>y>>z;
	ans=(x+y)/z;
	if(ans==(x/z)+(y/z)) cout<<ans<<" "<<0;
	else cout<<ans<<" "<<z-max(x%z,y%z);
}