#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f1(i, a, b) for (int i = a; i <= b; i ++)

#define N 105

int n, m, a[N][N], r[N], c[N], gr[N], gc[N];
vector <int> v;

void go(int x) {
    if (x > n) {
        x -= n;
        c[x] = -c[x]; gc[x] ++;
        f1(i, 1, n) r[i] -= 2 * a[i][x], a[i][x] = -a[i][x];
    }
    else {
        r[x] = -r[x]; gr[x] ++;
        f1(i, 1, m) c[i] -= 2 * a[x][i], a[x][i] = -a[x][i];
    }
    return;
}

int main() {
    scanf("%d %d", &n, &m);
    f1(i, 1, n) f1(j, 1, m) {
		scanf("%d", &a[i][j]);
		r[i] += a[i][j], c[j] += a[i][j];
    }
    while (1) {
        int mn = 0, id;
        f1(i, 1, n) if (mn > r[i]) mn = r[i], id = i;
		f1(i, 1, m) if (mn > c[i]) mn = c[i], id = i + n;
        if (!mn) break;
        go(id);
    }
    f1(i, 1, n) if (gr[i] & 1) v.pb(i);
    printf("%d ", v.size());
    for (auto x : v) printf("%d ", x); puts("");
    v.clear();
    f1(i, 1, m) if (gc[i] & 1) v.pb(i);
    printf("%d ", v.size());
    for (auto x : v) printf("%d ", x); puts("");
	return 0;
}