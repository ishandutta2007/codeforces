#include <bits/stdc++.h>
using namespace std;

#define f ;for (i = -1; ++i <
#define p(v) ; v.push_back({*t, i})) scanf("%d", t) f
#define u(s, w) for (j = s j - 1) w = min w;

main () {
	int N = 6e5, n, m, g[N], t[N], a[N], i, j;
	vector<array<int, 2> > q, r[N];
	
	cin >> n >> m
	f n p(q)
	m && cin >> j p(r[j - 1])
	N; g[i] = t[i] = a[i] = N);
	sort(q.begin(), q.end())
	f n; q[i - 1][0] == q[i][0] ? g[q[i - 1][1]] = q[i][1] : 0);
	for (; i--; ) {
		u(g[i]; ++j < N; j |=, (g[i] - i, t[j]))
		for (auto w: r[i])
			u(w[0]; j; j &=, (t[j] + 1, a[w[1]]))
	}
	f m; )
		cout << a[i] % N - 1 << endl;
}