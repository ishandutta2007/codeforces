#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f3(i, a, b) for (int i = a; i >= b; i --)
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define f0(i, a, b) for (int i = a; i < b; i ++)

typedef vector <int> vi;

#define N 1000005

int n, a[N], id[N], sz[N], rt[N];
vi v[N];
bool vis[N];

ll mx, mn;

int find_rt(int x) {
	if (rt[x] == x) return x;
	return rt[x] = find_rt(rt[x]);
}

int main() {
    scanf("%d", &n);
    f1(i, 1, n) scanf("%d", &a[i]), id[i] = i;
    sort(id + 1, id + n + 1, [](int i, int j) {return a[i] < a[j];});
    int x, y;
	f0(i, 1, n) {
		scanf("%d %d", &x, &y);
        v[x].pb(y); v[y].pb(x);
	}
    int sum;
    f1(i, 1, n) sz[i] = 1, rt[i] = i;
    f1(i, 1, n) {
        x = id[i]; sum = 1; mx -= a[x];
        for (auto z : v[x]) if (vis[z]) {
			y = find_rt(z);
            rt[y] = x; sz[x] += sz[y];
            mx -= 1ll * sz[y] * sz[y] * a[x];
            sum += sz[y];
        }
        mx += 1ll * sum * sum * a[x];
        vis[x] = 1;
    }
    f1(i, 1, n) sz[i] = 1, rt[i] = i, vis[i] = 0;
    f3(i, n, 1) {
		x = id[i]; sum = 1; mn -= a[x];
        for (auto z : v[x]) if (vis[z]) {
            y = find_rt(z);
            rt[y] = x; sz[x] += sz[y];
            mn -= 1ll * sz[y] * sz[y] * a[x];
            sum += sz[y];
        }
        mn += 1ll * sum * sum * a[x];
        vis[x] = 1;
    }
    mx -= mn;
    printf("%I64d\n", mx / 2);
}