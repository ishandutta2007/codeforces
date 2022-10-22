#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int n, m;
int st[200010];
int r[200010];
vi vl[200010];
vi sw[200010];

vi vs;

bool dfs(int v, int c)
{
	st[v] = c;
	vs.pb(v);

	for (int to : vl[v]) {
		int u = r[to] ^ 1;
		int nx = -1;

		for (int x : sw[to]) {
			if (st[x] == -1) {
				nx = x;
			} else {
				u ^= st[x];
			}
		}

		if (nx != -1) {
			dfs(nx, u);
		}

		if (nx == -1 && u != 0) {
			return false;
		}
	}

	return true;
}

int main() {
	scanf("%d%d", &n, &m);

	rep(i, n) scanf("%d", &r[i]);

	rep(i, m) {
		int k;
		scanf("%d", &k);
		rep(j, k) {
			int x;
			scanf("%d", &x); --x;
			vl[i].pb(x);
			sw[x].pb(i);
		}
	}

	memset(st, -1, sizeof(st));

	rep(i, m) {
		if (st[i] != -1) {
			continue;
		}
		vs.clear();

		if (!dfs(i, 0)) {
			for (int x : vs) {
				st[x] = -1;
			}
			if (!dfs(i, 1)) {
				puts("NO");
				return 0;
			}
		}
	}

	rep(i, m) {
		for (int to : vl[i]) {
			r[to] ^= st[i];
		}
	}

	bool ok = 1;
	rep(i, n) if (!r[i]) {
		ok = 0;
	}

	puts(ok ? "YES" : "NO");

	return 0;
}