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

char s[1010][12][12];
int n, m, k, w;
int a[1000010], b[1000010], c[1000010], ke, id[1000010];
vector<int> g[1010];
bool used[1010];

bool cmp(int i, int j) {
	return c[i] < c[j];
}

class SNM {
private:
	vector<int> p;

public:
	SNM(int n) {
		p.resize(n);
		for (int i = 0; i < n; i++)
			p[i] = i;
	}

	int findset(int x) {
		return x == p[x] ? x : p[x] = findset(p[x]);
	}

	void link(int a, int b) {
		a = findset(a);
		b = findset(b);

		if (b & 1) p[a] = b;
		else p[b] = a;
	}
};

void dfs(int i, int p) {
	printf("%d %d\n", i + 1, p + 1);
	used[i] = true;
	forn(j, g[i].size())
		if (!used[ g[i][j] ])
			dfs(g[i][j], i);
}

int main() {
	scanf("%d %d %d %d", &n, &m, &k, &w);
	forn(q, k) {
		forn(i, n) scanf("%s", s[q][i]);
	}

	forn(q1, k)
		forn(q2, q1) {
			int kd = 0;
			forn(i, n) forn(j, m) kd += s[q1][i][j] != s[q2][i][j];
			if (kd * w <= n * m) {
				a[ke] = q1;
				b[ke] = q2;
				c[ke] = kd * w;
				ke++;
			}
		}

	forn(i, ke) id[i] = i;
	sort(id, id+ke, cmp);

	SNM snm(k);

	int ans = 0, eu = 0;
	forn(ii, ke) {
		int i = id[ii];
		if (snm.findset(a[i]) != snm.findset(b[i])) {
			snm.link(a[i], b[i]);
			ans += c[i];
			eu++;
			g[ a[i] ].pb(b[i]);
			g[ b[i] ].pb(a[i]);
		}
	}

	ans += (k - eu) * (n * m);

	printf("%d\n", ans);

	forn(i, k)
		if (!used[i])
			dfs(i, -1);

	return 0;
}