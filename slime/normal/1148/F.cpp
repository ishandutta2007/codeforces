#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define vt vector<int>
#define maxn 300005
#define ll long long
#define ld double
using namespace std;
int n;
ll a[maxn], b[maxn];
int main()
{
	cin>>n;
	ll s = 0;
	for(int i = 1; i <= n; i++)
		scanf("%lld%lld", &a[i], &b[i]), 
		s += a[i];
	if(s > 0)
		for(int i = 1; i <= n; i++)
			a[i] = -a[i];
	ll ans = 0;
	for(int i = 61; i >= 0; i--)
	{
		ll ns = 1ll << i;
		ll s = 0;
		for(int j = 1; j <= n; j++)
			if(b[j] == ns)
				s += a[j];
		int fl = 0;
		if(s < 0) 
		{
			fl = 1, 
			ans ^= ns;
		}
		for(int j = 1; j <= n; j++)
			if(b[j] & ns)
			{
				if(fl) a[j] *= -1;
				b[j] ^= ns;
			}
	}
	cout<<ans<<endl;
	return 0;
}