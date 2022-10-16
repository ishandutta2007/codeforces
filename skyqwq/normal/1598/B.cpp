// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1005;

int a[6][N], n;

bool inline chk(int x, int y) {
    int A = 0, B = 0, C = 0;
    for (int i = 1; i <= n; i++) {
        if (!a[x][i] && !a[y][i]) return 0;
        if (a[x][i] && a[y][i]) C++;
        else if (a[x][i]) A++;
        else B++;
    }
    if (A > n / 2 || B > n / 2) return 0;
    return 1;
}

int main() {
    int T; read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 5; j++) scanf("%d", &a[j][i]);
        bool o = 0;
        for (int i = 1; i <= 5; i++)
            for (int j = 1; j < i; j++)
                if (chk(i, j)) o = 1;
        puts(o ? "YES" : "NO");
    }
    return 0;
}