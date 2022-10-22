#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

typedef long long ll;
const ll INF = ((1ll << 62) - 1 << 1) + 1;
int S;
ll n, k, ans = INF;

int main()
{
	int i, tot; ll cnt, tt;
	cin >> n >> k;
	ll m = k; S = sqrt(k);
	for (int i = 2; i <= S; i++)
	{
		if (k % i) continue;
		cnt = 0; tot = 0;
		while (k % i == 0) tot++, k /= i;
		tt = n;
		while (tt) cnt += tt / i, tt /= i;
		ans = Min(ans, cnt / tot);
	}
	if (k > 1)
	{
		cnt = 0; tt = n;
		while (tt) cnt += tt / k, tt /= k;
		ans = Min(ans, cnt);
	}
	std::cout << ans << std::endl;
	return 0;
}