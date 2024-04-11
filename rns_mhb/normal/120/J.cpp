#include <bits/stdc++.h>
using namespace std;
#define abs(x) (x < 0 ? -x : x)
#define ll long long
#define f1(i, a, b) for (int i = a; i <= b; i ++)

#define N 100005

int n, id[N], d[N];

struct pnt {
    int x, y, k;
    void input() {
		scanf("%d %d", &x, &y);
        if (x == abs(x)) k = 1;
        else k = 2;
        if (y != abs(y)) k += 2;
        x = abs(x), y = abs(y);
    }
    pnt (int x = 0, int y = 0) : x(x), y(y) {}
    pnt operator - (const pnt &a) const {return pnt(x - a.x, y - a.y);}
    int dist() {return x * x + y * y;}
} p[N];

bool cmp(int x, int y) {
	return d[x] < d[y];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    int ans = 1e9, a, b;
	f1(i, 1, n) p[i].input();
    f1(i, 1, n) id[i] = i, d[i] = (p[i] - p[1]).dist();
    sort(id + 1, id + n + 1, cmp);
    f1(i, 1, n) {
        int up = min(n - i, 200);
        f1(j, 1, up) {
            if (ans > (p[id[i]] - p[id[i+j]]).dist()) {
				ans = (p[id[i]] - p[id[i+j]]).dist();
				a = id[i], b = id[i+j];
            }
        }
    }
    printf("%d %d %d %d\n", a, p[a].k, b, 5 - p[b].k);
}