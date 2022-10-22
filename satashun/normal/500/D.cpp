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

int n, q;
vector<pii> g[100010];
double ret;

int sz[100010];
int dep[100010];

pii road[100010];
int cl[100010];
ll all;

void pre(int v, int par, int d)
{
	dep[v] = d;
	sz[v] = 1;

	for (pii p : g[v]) if (p.fi != par) {
		pre(p.fi, v, d + 1);
		sz[v] += sz[p.fi];
	}
}

ll nc3(ll x)
{
	return x * (x-1) * (x-2) / 6;
}

int main() {
	scanf("%d", &n);
	all = nc3(n);

	rep(i, n - 1) {
		int a, b, l;
		scanf("%d%d%d", &a, &b, &l);
		--a; --b;
		g[a].eb(b, l);
		g[b].eb(a, l);
		road[i] = mp(a, b);
		cl[i] = l;
	}

	pre(0, -1, 0);

	rep(i, n - 1) {
		int a = road[i].fi, b = road[i].se;
		if (dep[a] > dep[b]) swap(a, b);
		road[i] = mp(a, b);

		ll t = nc3(sz[b]) + nc3(n - sz[b]);
		ret += (double)(all - t) / all * 2 * cl[i];
	}

	scanf("%d", &q);

	while (q--) {
		int i, l;
		scanf("%d%d", &i, &l);
		--i;

		int a = road[i].fi, b = road[i].se;
		ll t = nc3(sz[b]) + nc3(n - sz[b]);
		ret -= (double)(all - t) / all * 2 * (cl[i] - l);
		cl[i] = l;
		printf("%.8f\n", ret);
	}

	return 0;
}