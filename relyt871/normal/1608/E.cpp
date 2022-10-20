#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100005;

int n, ans;

struct Node {
    int x, y, c;
} a[MAXN], b[MAXN];

inline bool cmpx(Node p, Node q) {
    return (p.x < q.x);
}

inline bool cmpy(Node p, Node q) {
    return (p.y < q.y);
}

inline bool Check1(int c1, int c2, int c3, int mid) {
    int i, j, k, cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (i = 1; i <= n; ++i) {
        cnt1 += (a[i].c == c1);
        if (cnt1 >= mid) break;
    }
    if (cnt1 < mid) return 0;
    for (j = i + 1; j <= n; ++j) {
        cnt2 += (a[j].c == c2 && a[j].x > a[i].x);
        if (cnt2 >= mid) break;
    }
    if (cnt2 < mid) return 0;
    for (k = j + 1; k <= n; ++k) {
        cnt3 += (a[k].c == c3 && a[k].x > a[j].x);
        if (cnt3 >= mid) return 1;
    }
    return 0;
}

inline bool Check2(int c1, int c2, int c3, int mid) {
    int i, j, k, cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (i = 1; i <= n; ++i) {
        cnt1 += (a[i].c == c1);
        if (cnt1 >= mid) break;
    }
    if (cnt1 < mid) return 0;
    for (j = 1; j <= n; ++j) {
        cnt2 += (b[j].c == c2 && b[j].x > a[i].x);
        if (cnt2 >= mid) break;
    }
    if (cnt2 < mid) return 0;
    for (int k = j + 1; k <= n; ++k) {
        cnt3 += (b[k].c == c3 && b[k].x > a[i].x && b[k].y > b[j].y);
        if (cnt3 >= mid) return 1;
    }
    return 0;
}

void Work() {
    copy(a + 1, a + n + 1, b + 1);
    sort(a + 1, a + n + 1, cmpx);
    sort(b + 1, b + n + 1, cmpy);
    int L = 1, R = n / 3;
    while (L <= R) {
        int mid = (L + R) >> 1;
        if (Check1(1, 2, 3, mid) || Check1(1, 3, 2, mid) || Check1(2, 1, 3, mid) ||
            Check2(1, 2, 3, mid) || Check2(1, 3, 2, mid) || Check2(2, 1, 3, mid) ||
            Check2(2, 3, 1, mid) || Check2(3, 1, 2, mid) || Check2(3, 2, 1, mid)) {
            ans = max(ans, mid);
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].c);
    }
    Work();
    for (int i = 1; i <= n; ++i) {
        a[i].x *= -1;
    }
    Work();
    for (int i = 1; i <= n; ++i) {
        swap(a[i].x, a[i].y);
    }
    Work();
    for (int i = 1; i <= n; ++i) {
        a[i].x *= -1;
    }
    Work();
    printf("%d\n", ans * 3);
}

int main(){
	solve();
	return 0;
}