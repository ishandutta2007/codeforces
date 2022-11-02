#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int n, x, t[2010], h[2010], m[2010];
vector<pii> vv[2];
bool used[2][2010];

int solve(int cur) {
	int ch = x;
	int res = 0;
	forn(i, n) used[0][i] = used[1][i] = false;

	while (true) {
		int mm = -1, mq = -1;
		forn(q, vv[cur].size())
			if (!used[cur][q] && vv[cur][q].first <= ch)
				if (mm < vv[cur][q].second) {
					mm = vv[cur][q].second;
					mq = q;
				}

		if (mq == -1) break;
		res++;
		used[cur][mq] = true;
		ch += mm;

		cur ^= 1;
	}

	return res;
}

int main() {
	scanf("%d %d", &n, &x);
	forn(i, n) scanf("%d %d %d", &t[i], &h[i], &m[i]);
	forn(i, n)
		vv[t[i]].pb(pii(h[i], m[i]));
	forn(q, 2) sort(vv[q].begin(), vv[q].end());

	printf("%d\n", max(solve(0), solve(1)));
	return 0;
}