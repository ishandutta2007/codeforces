#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 100005;

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

void solve() {
    int n, k;
    read(n); read(k);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int a; read(a);
        ans |= a;
    }
    puts(ans? "YES" : "NO");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}