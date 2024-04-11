#include <bits/stdc++.h>
#define maxn 100005
#define ll long long
#define mod 1000000007
using namespace std;
int n, k;
ll gcd(ll a, ll b)
{
	if(!b) return a;
	return gcd(b, a % b);
}
int main()
{
	int n, k, a, b;
	cin>>n>>k>>a>>b;
	int pl = a + 1;	
	ll t = 1ll * n * k;
	ll mxs = 1, mns = t;
	for(int i = 1; i <= n; i++)
	{
		ll ns = 1ll * (i - 1) * k + 1 + b;
		mxs = max(mxs, gcd(t, t + (ns - pl) % t));
		mns = min(mns, gcd(t, t + (ns - pl) % t));
		ns = 1ll * (i - 1) * k + 1 - b;
		mxs = max(mxs, gcd(t, t + (ns - pl) % t));
		mns = min(mns, gcd(t, t + (ns - pl) % t));
	}
	cout<<t / mxs<<" "<<t / mns<<endl;
	return 0;
}