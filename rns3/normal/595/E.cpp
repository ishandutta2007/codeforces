#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
#define M 202020
const int mod = 1000000007;
typedef pair<int, int> pii;
#define x first
#define y second

int n;
int k;

struct pnt {
    ll x, y, id;
    pnt(ll x = 0, ll y = 0, ll id = 0) : x(x), y(y), id(id){};
}p[M], q[M];
bool cmpx(pnt a, pnt b) {return a.x != b.x ? a.x < b.x : a.y != b.y ? a.y < b.y : a.id < b.id;}
bool cmpy(pnt a, pnt b) {return a.y != b.y ? a.y < b.y : a.x != b.x ? a.x < b.x : a.id < b.id;}
ll answer;

int flag[M], flagn;
bool update(int a, int b, int c, int d) {
    ll x = p[b].x - p[a].x;
    ll y = q[d].y - q[c].y;
    if (!x) x = 1;
    if (!y) y = 1;
    if (x & 1) x++;
    if (y & 1) y++;
    if (x * y >= answer) return 1;
    int gas = 0;
    ++flagn;
    for (int i = 0; i < a; i++) if (flag[p[i].id] < flagn) {
        flag[p[i].id] = flagn;
        gas++;
    }
    for (int i = b + 1; i < n; i++) if (flag[p[i].id] < flagn) {
        flag[p[i].id] = flagn;
        gas++;
    }
    for (int i = 0; i < c; i++) if (flag[q[i].id] < flagn) {
        flag[q[i].id] = flagn;
        gas++;
    }
    for (int i = d + 1; i < n; i++) if (flag[q[i].id] < flagn) {
        flag[q[i].id] = flagn;
        gas++;
    }
    if (gas > k) return 0;
    //printf("a = %d, b = %d, c = %d, d = %d, gas = %d; x = %I64d, y = %I64d\n", a, b, c, d, gas, x, y);
    answer = x * y;
    return 1;
}

int main() {
    //freopen("A4.in", "r", stdin);
    scanf("%d", &n);
    scanf("%d", &k);
    //printf("n = %d, k = %d\n", n, k);
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        scanf("%I64d %I64d %I64d %I64d", &a, &b, &c, &d);
        p[i] = q[i] = pnt(a + c, b + d, i);
    }
    sort(p, p + n, cmpx);
    sort(q, q + n, cmpy);
    answer = 1ll * (p[n-1].x - p[0].x + 2) * (q[n-1].y - q[0].y + 2);

    for (int a = 0; a <= k; a++) for (int b = n - 1; b - a >= n - k - 1; b--) {
        for (int c = 0; c <= k; c++) for (int d = n - 1; d - c >= n - k - 1; d--) {
            if (!update(a, b, c, d)) break;
        }
    }
    printf("%I64d\n", answer / 4);
    return 0;
}