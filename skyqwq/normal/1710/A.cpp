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

int n, m, k, a[N];

bool inline chk() {
    LL s = 0;
    bool hv = 0;
    for (int i = 1; i <= k; i++) {
        LL z = a[i] / m;
        if (z == 1) z--;
        if (!z) continue;
        s += z;
        if (z != 2) hv = 1;
        if (s == n) return 1;
    }
    if (s > n && !hv) return 0; 
    return s >= n;
}

int main() {
    int T; read(T);
    while (T--) {
        read(n), read(m), read(k);
        for (int i = 1; i <= k; i++) read(a[i]);
        bool ok = chk();
        swap(n, m);
        ok |= chk();
        puts(ok ? "Yes" : "No");
    }   
    return 0;
}