#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#define maxn 100005
#define ll long long
#define pi pair<int, int>
using namespace std;
unordered_map<ll, ll> x;
int n, m;
ll t;
int main()
{
	scanf("%d%d", &n, &m);
	int s;
	scanf("%d%lld", &s, &t);
	ll cnt = 0;
	while(t)
	{
		int res = t % n;
		if(s > m) s -= res;
		else s += res;
		while(s > n) s -= n;
		while(s <= 0) s += n;
		t--;
		if(res <= 100)
		{
    		ll ns = s * (ll)n + res;
    		if(x[ns])
    			t %= (x[ns] - t);
    		else 
    			x[ns] = t;
		}
	}
	printf("%d\n", s);
	return 0;
}
/*
100000 7
78411 208898171737
*/