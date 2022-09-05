#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))
 
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
 
typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 100007;
const int MOD = 1000000007;

VI G[MAX];

int up[MAX][20];

int tin[MAX];
int tout[MAX];
int d[MAX];
int timer = 0;

void dfs(int v, int p) {
    tin[v] = timer ++;
    up[v][0] = p;
    FOR(i,1,20)
        up[v][i] = up[up[v][i - 1]][i - 1];
    for(int to: G[v]) {
        if (to == p)
            continue;
        d[to] = d[v] + 1;
        dfs(to, v);
    }
    tout[v] = timer ++;
}

bool upper(int a, int b) {
    return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}

int lca(int a, int b) {
    if (upper(a, b)) return a;
    if (upper(b, a)) return b;
    RFOR(i,20,0) {
        if (!upper(up[a][i], b))
            a = up[a][i];
    }
    return up[a][0];
}

int dist(int a, int b) {
    int c = lca(a, b);
    return d[a] + d[b] - 2 * d[c];
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n;
    FOR(i, 0, n - 1) {
        int a , b;
        cin >> a >> b;
        --a;--b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(0, 0);

    int q;
    cin >> q;

    FOR(i,0,q) {
        int x, y, a ,b, k;
        cin >> x >> y >> a >> b >> k;
        -- x; --y; --a; --b;
        bool res = false;
        int l = dist(a, b);
        if (l <= k && l % 2 == k % 2)
            res = true;
        l = dist(a, x) + 1 + dist(b, y);
        if (l <= k && l % 2 == k % 2)
            res = true;
        l = dist(a, y) + 1 + dist(b, x);
        if (l <= k && l % 2 == k % 2)
            res = true;
        if (res)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }


	return 0;
}