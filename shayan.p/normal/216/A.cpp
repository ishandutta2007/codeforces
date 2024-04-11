#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll inf=1e18;
using namespace std;
ll calc(ll a,ll b,ll c)
{
	if(a==0||b==0||c==0) return 0;
	else if(a==1&&b==1&&c==1) return 1;
	else if(a==1&&b==1) return c;
	else if(a==1&&c==1) return b;
	else if(b==1&&c==1) return a;
	else if(a==1) return b*c;
	else if(b==1) return a*c;
	else if(c==1) return a*b;
	else return (2*(a+b+c))-6+calc(a-1,b-1,c-1);
}
int main()
{
	ll a,b,c;cin>>a>>b>>c;cout<<calc(a,b,c);
}