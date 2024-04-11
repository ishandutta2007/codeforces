#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
#define M 300101
const int mod = 1000003;
typedef pair<int, int> pii;
#define x first
#define y second

int n;
struct pnt{
    int x, y, d;
    pnt(int x = 0, int y = 0, int d = 0) : x(x), y(y), d(d) {}
};
bool operator<(pnt a, pnt b) {
    return a.d != b.d ? a.d < b.d : a.x != b.x ? a.x < b.x : a.y < b.y;
}

pii p[M];
set<pnt> pset;
int w[M];

pii ans[M];

bool solve() {
    int i = n - 1;
   // printf("size = %d\n", pset.size());
    while (i >= 0) {
        int x = w[i];
        if (pset.empty()) return 0;
        set<pnt> :: iterator it = pset.lower_bound(pnt(0, 0, x));
        if (it == pset.end()) return 0;
        pnt p = *it;
        if (p.d != x) return 0;
        ans[i] = pii(p.x, p.y);
        pset.erase(p);
        pnt p1 = pnt(p.x-1, p.y, p.d+1);
        pnt p2 = pnt(p.x, p.y-1, p.d-1);
        if (p.x && !pset.count(p1)) pset.insert(p1);
        if (p.y && !pset.count(p2)) pset.insert(p2);
        i--;
    }
    return 1;
}

int main() {
    //freopen("A1.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p[i].first, &p[i].second);
    }
    sort(p, p + n);
    reverse(p, p + n);

    pii last;
    for (int i = 0; i < n; i++) {
        if (!i || p[i].y > last.y) {
            last = p[i];
            pset.insert(pnt(p[i].x, p[i].y, p[i].y - p[i].x));
        }
    }
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);
    if (solve()) {
        puts("YES");
        for (int i = 0; i < n; i++) printf("%d %d\n", ans[i].x, ans[i].y);
    } else {
        puts("NO");
    }
    return 0;
}