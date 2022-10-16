// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e5 + 5;

int n, t;

PII e[N];

void inline add(int x, int y) {
    e[++t] = mp(x, y);
}

int main() {
    read(n);
    if (n == 1) {
        puts("1\n1 1");
        return 0;
    }
    t = 0;
    int k = (2 * n - 1 + 2) / 3;
    while (n % 3 != 2) {
        add(n, n);
        --n; 
    }
    k = (2 * n - 1 + 2) / 3;
    int z = (k + 1) / 2;
    for (int i = 1; i <= z; i++) add(i, z - i + 1);
    for (int i = 1; i <= k - z; i++) add(n - i + 1, n - (k - z - i + 1) + 1);
    //assert(k == t);
    printf("%d\n", t);
    for (int i = 1; i <= t; i++) printf("%d %d\n", e[i].fi, e[i].se);
    return 0;
}