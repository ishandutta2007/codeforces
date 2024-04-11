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

const int N = 1e6 + 5;

int n, c, a[N], s[N], cnt[N];

int main() {
    int T; read(T);
    while (T--) {
    	read(n), read(c);
        for (int i = 1; i <= n; i++) read(a[i]), s[a[i]]++;
        for (int i = 1; i <= c; i++) s[i] += s[i - 1];
        bool ok = 1;
        for (int i = 1; i <= c; i++) {
            if (s[i] - s[i - 1] > 0) {
                for (int j = i; j <= c; j += i) {
                    int v = s[min(j + i - 1, c)] - s[j - 1];
                    int o = j / i;
                    if (v && s[o] - s[o - 1] == 0) ok = 0;
                }
            }
        }
        puts(ok ? "Yes" : "No");
        for (int i = 1; i <= c; i++) s[i] = 0;
    }
    return 0;
}