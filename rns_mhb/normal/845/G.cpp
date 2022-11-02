#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define x first
#define y second
#define bitctz __builtin_ctz
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define f3(i, a, b) for (int i = a; i >= b; i --)
template <class T> void chkmin(T &a, T b) {if (a > b) a = b;}

typedef pair <int, int> pii;
typedef vector <int> vi;

#define N 100005
#define M 35

int n, m;

vi A;
vector <pii> v[N];
bool vis[N];
int d[N], a[M], as, id[M];

void dfs(int k) {
    vis[k] = 1;
    for (auto x : v[k]) {
        if (vis[x.x]) A.pb(x.y ^ d[k] ^ d[x.x]);
        else {
            d[x.x] = d[k] ^ x.y;
            dfs(x.x);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    int x, y, w;
    f1(i, 1, m) {
		scanf("%d %d %d", &x, &y, &w);
        v[x].pb(pii(y, w));
        v[y].pb(pii(x, w));
    }
    dfs(1);
    sort(A.begin(), A.end());
    unique(A.begin(), A.end());
    for (auto x : A) {
        y = x;
		f0(i, 0, as) chkmin(y, y ^ a[id[i]]);
		if (y) {
            id[as] = as; a[as] = y;
			f3(i, as-1, 0) if (a[id[i]] < a[id[i+1]]) swap(id[i], id[i+1]);
			as ++;
		}
    }
    x = d[n];
    f0(i, 0, as) chkmin(x, x ^ a[id[i]]);
    printf("%d\n", x);
	return 0;
}