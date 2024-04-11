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
int cnt[2][maxn];
int a[maxn]; 
int main()
{
	ll ans = 0;
	int n;
	cin>>n;
	cnt[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i], 
		a[i] ^= a[i - 1];
		ans += cnt[i & 1][a[i]];
		cnt[i & 1][a[i]]++;
	}
	cout<<ans<<endl;
	return 0;
}