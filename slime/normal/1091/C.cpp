#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1000005
#define ll long long
#define ld double
#define mod 1000000007
using namespace std;
int n;
int cnt = 0;
ll f[maxn];
void work(int x)
{
	ll s = (1 + n + 1) * (ll)(n / x + 1) / 2 - (n + 1);
	f[cnt++] = s;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i * i <= n; i++)
		if(n % i) continue;
		else work(i), work(n / i);
	sort(f, f + cnt);
	for(int i = 0; i < cnt; i++)
		if(i == 0 || f[i] != f[i - 1])
			printf("%lld ", f[i]);
	return 0;
}