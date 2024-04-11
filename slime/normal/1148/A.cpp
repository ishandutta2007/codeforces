#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 2000005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
int main()
{
	ll a, b, c;
	cin>>a>>b>>c;
	ll ans = c * 2 + min(a, b) * 2;
	if(max(a, b) > min(a, b)) ans++;
	cout<<ans<<endl;
	return 0;
}