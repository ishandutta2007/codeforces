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

int n;
int p[100010];
vi g[100010];
double ret[100010];
int sz[100010];

void pre(int v)
{
    sz[v] = 1;

    for (int to : g[v]) {
	pre(to);
	sz[v] += sz[to];
    }
}

void dfs(int v, double cur)
{
    ret[v] = cur + 1;
    cur += 1.0;

    int all = sz[v] - 1;

    for (int to : g[v]) {
	double nx = cur + (double)(all - sz[to]) / 2.0;
	dfs(to, nx);
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i < n; ++i) {
	scanf("%d", &p[i]);
	--p[i];
	g[p[i]].pb(i);
    }

    pre(0);
    dfs(0, 0.0);

    rep(i, n) printf("%.8f%c", ret[i], i == n - 1 ? '\n' : ' ');

    return 0;
}