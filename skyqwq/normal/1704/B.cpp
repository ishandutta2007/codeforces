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

int n, x, a[N];

int main() {
 	int T; read(T);
 	while (T--) {
 		read(n), read(x);
        for (int i = 1; i <= n; i++) read(a[i]);
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            int j = i;
            int mx = a[i], mn = a[i];
            while (j < n) {
                if (max(mx, a[j + 1]) - min(mn, a[j + 1]) <= 2 * x) {
                    chkMax(mx, a[j + 1]);
                    chkMin(mn, a[j + 1]);
                    j++;
                } else break;
            }
            ans++;
            i = j;
        }
        printf("%d\n", ans);
 	}   
    return 0;
}