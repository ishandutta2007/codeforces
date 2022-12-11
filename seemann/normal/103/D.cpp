#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <ctime>
#include <cmath>

using namespace std;

#define ll long long
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(a, b) for (int a = 0; (a) < (b); ++a)
#define iter(a) typeof(a.begin())
#define foreach(it, a) for(typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define sqr(a) (a)*(a)
#define PI 2.0*acos(0.0)

const int INF = 1000000001;
const double EPS = 1e-8;
const int MAXN = 300001;

ll w[MAXN];
struct query{
	int a, b;
	int n;
};

bool operator < (query a, query b)
{
	if (a.b != b.b) return a.b < b.b;
	return a.a < b.a;
}

query q[MAXN];
ll ans[MAXN];
ll wa[MAXN];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("", "w", stdout);
	clr(ans);
	int n, p;
	scanf("%d", &n);
	int C = ceil(sqrt(n));
	FOR(i, n)
		cin >> w[i];
	scanf("%d", &p);
	FOR(i, p)
	{
		scanf("%d%d", &q[i].a, &q[i].b);
		q[i].a--;
		q[i].n = i;
	}
	sort(q, q + p);
	int t = 0;
	int lt = -1;
	while (t < p)
	{
		if (q[t].b >= C)
		{
			for (int i = q[t].a; i < n; i += q[t].b)
				ans[q[t].n] += w[i];
            t++;
			continue;
		}
		if (q[t].b == lt)
			ans[q[t].n] = wa[q[t].a];
		else
		{
			clr(wa);
			lt = q[t].b;
			FOR(i, q[t].b)
				for (int j = n - i - 1; j >= 0; j -= q[t].b)
					if (j + q[t].b < n) wa[j] = wa[j + q[t].b] + w[j];
						else wa[j] = w[j];
            ans[q[t].n] = wa[q[t].a];
		}
		t++;
	}
	FOR(i, p)
		cout << ans[i] << '\n';

	return 0;
}