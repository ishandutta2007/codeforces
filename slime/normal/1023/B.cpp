#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define mod 1000000007
#define maxn 105
#define ll long long
using namespace std;
int main()
{
	ll n, k;
	scanf("%lld%lld", &n, &k);
	ll mns = max((ll)1, k - n);
	ll mxs = min(n, k / 2);
	ll ans = mxs - mns + 1;
	//cout<<ans<<endl;
	if(n * 2 >= k && (!(k & 1))) ans--;
	printf("%lld\n", max(ans, (ll)0));
	return 0;
}
/*
5 4 4 4 4 16
*/