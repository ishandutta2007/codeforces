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

const int N = 2e5 + 5;

int n, k, a[N], X, Y, b[N];
 
bool inline chk(int x) {
    int c = 0;
    for (int L = 1, i = 0, j = 0; L <= n; L++) {
        while (j < n && a[j + 1] <= L + x) j++;
        while (i < n && a[i + 1] < L) i++;
        c = j - i;
        if (c - (n - c) >= k) {
            X = L, Y = L + x;
            return 1;
        }
    }
    return 0;
}

int main() {
    int T; read(T);
    while (T--) {
        read(n), read(k);
        for (int i = 1; i <= n; i++) read(a[i]), b[i] = a[i];
        sort(a + 1, a + 1 + n);
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (chk(mid)) r = mid;
            else l = mid + 1;
        }
        chk(r);
        printf("%d %d\n", X, Y);
        int la = 0, c = 0, o = 0;
        for (int i = 1; i <= n; i++) {
            if (o == k - 1) break;
            if (b[i] <= Y && b[i] >= X) c++;
            else c--;
            if (c == 1) {
                printf("%d %d\n", la + 1, i);
                la = i;
                c = 0;
                o++;
                if (o == k - 1) break;
            }
        }
        printf("%d %d\n", la + 1, n);
    }
    return 0;
}