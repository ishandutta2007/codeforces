#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#define maxn 100005
#define ld double
#define ll long long
#define mod 998244353
using namespace std;
ll gcd(ll a, ll b)
{
	if(!b) return a;
	return gcd(b, a % b);
}
int n, m;
int l[maxn], e[maxn];
int v;
int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		ll a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		ll ns = gcd(a, b);
		a /= ns, b /= ns;
		ll n1 = gcd(b, c);
		while(1)
		{
			b /= n1;
			n1 = gcd(n1, b);
			if(n1 == 1) break;
		}
		if(b == 1) printf("Finite\n");
		else printf("Infinite\n");
	}
	return 0;
}