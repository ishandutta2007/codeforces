#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


const int MAXN = 1e5+1;
vector<int> gr[MAXN];
bool cat[MAXN], used[MAXN];
int cnt = 0, m;
void dfs(int v, int mx, int cur) {
	used[v] = true;
	int c = cur + 1;
	if (!cat[v])
		c = 0;
	int det = 0;
	for (auto i : gr[v]) {
		if (!used[i]) {
			++det;
			dfs(i, max(mx, c), c);
		}
	}
	if (!det) {
		if (max(mx, c) <= m)
			++cnt;
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cout << fixed;
    cout.precision(10);
    cerr << fixed;
    cerr.precision(10);
    
    int n;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    	cin >> cat[i];

    for (int i = 1; i <= n; ++i)
    	used[i] = 0;

    for (int i = 0; i < n - 1; ++i) {
    	int x, y;
    	cin >> x >> y;
    	gr[x].pb(y);
    	gr[y].pb(x);
    }

    dfs(1, 0, 0);

    cout << cnt << '\n';

    return 0;
}