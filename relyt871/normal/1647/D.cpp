#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 205;
const int MAXN = 1000006;

template <typename T> inline void read(T &WOW) {
    T x = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '0') flag = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    WOW = flag * x;
}

inline bool isPrime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

void solve() {
    int x, d;
    read(x); read(d);
    int pw = 0;
    while (x % d == 0) {
        x /= d;
        ++pw;
    }
    if (pw == 1) {
        puts("NO");
        return;
    }
    if (!isPrime(x)) { //xd,d...  or ad,bd...
        puts("YES");
        return;
    }
    if (pw == 2) {
        puts("NO");
        return;
    }
    if (isPrime(d)) {
        puts("NO");
        return;
    }
    if (pw == 3) { //xd, d, d  or xda, db
        for (int i = 2; i * i <= d; ++i) {
            if (d % i) continue;
            if ((x * i) % d != 0) {
                puts("YES");
                return;
            }
            if ((x * (d / i)) % d != 0) {
                puts("YES");
                return;
            }
        }
        puts("NO");
     } else if (pw >= 4) { //xd, d, d, d  or  xd, da, db
        puts("YES");
    }
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}