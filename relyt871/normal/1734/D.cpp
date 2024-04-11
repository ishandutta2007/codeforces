#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1000006;

template <typename T> inline void read(T &WOW) {
    T x = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') flag = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    WOW = flag * x;
}

int n, k;
LL a[MAXN], sum[MAXN];

bool Check() {
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i];
    }
    int p = k, q = k;
    LL lsum = sum[q - 1];
    while (p < n) {
        while (q > 1 && sum[p] - sum[q - 2] >= 0) {
            --q;
            lsum = min(lsum, sum[q - 1]);
        }
        if (sum[p + 1] - lsum >= 0) {
            ++p;
        } else {
            break;
        }
    }
    return (p >= n);
}

void solve() {
    read(n); read(k);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    bool ans = Check();
    reverse(a + 1, a + n + 1);
    k = n - k + 1;
    ans |= Check();
    puts(ans? "YES" : "NO");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}