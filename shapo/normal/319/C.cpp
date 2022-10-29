#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <stack>
#include <deque>
#include <utility>

using namespace std;

#define maxn 100500

typedef long long ll;
typedef long double ld;

int n;
int a[maxn], b[maxn];

bool ok(int a, ll b, int c, ll d)
{
	ld res = (ld)a * (ld)d - (ld)b * (ld)c;
	return (res <= 0.0);
}

bool ok(ll fp, ll fq, int bp, int bq, int ai)
{
	return (fq <= fp + (ll)ai * (bp - bq));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int j = 0; j < n; ++j)
	{
		cin >> b[j];
	}
	deque < pair < int, ll > > opt;
	ll prev = 0LL;
	for (int i = 1; i < n; ++i)
	{
		while (opt.size() >= 2 && ok(opt[1].first - opt[0].first, opt[1].second - opt[0].second,
					b[i - 1] - opt[0].first, prev - opt[0].second))
		{
			opt.pop_front();
		}
		opt.push_front(make_pair(b[i - 1], prev));
		while (opt.size() >= 2 && ok(opt[opt.size() - 1].second, opt[opt.size() - 2].second,
					opt[opt.size() - 1].first, opt[opt.size() - 2].first, a[i]))
		{
			opt.pop_back();
		}
		prev = opt.back().second + (ll)opt.back().first * a[i];
	}
	cout << prev << '\n';
	return 0;
}