#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e5 + 5;

int a[N], d[N], s[N];
int n, k;

int main() {
    read(n); read(k);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= n; i++) read(d[i]);
    if (k >= 2) {
        ll ans = 0, sum = a[1]; int minn = d[1];
        for (int i = 2; i < n; i++) minn = min(minn, d[i]);
        for (int i = 2; i <= n; i++) sum += a[i];
        ans = max(ans, sum - minn);
        ans = max(ans, (ll)(a[n] - d[n]));
        print(ans, '\n');
        return 0;
    }
    if (k == 0) {
        ll ans = 0, suma = 0;
        for (int i = n; i >= 1; i--) {
            suma += a[i];
            ans = max(ans, suma - d[i]);
        }
        print(ans, '\n');
        return 0;
    }
    s[1] = d[1];
    for (int i = 2; i <= n; i++) s[i] = min(s[i - 1], d[i]);
    ll ans = 0, maxn = 0, sum = 0, suma = 0;
    for (int i = 1; i <= n; i++) sum += a[i];
    for (int i = n; i >= 1; i--) {
        if (i != n) {
            ans = max(ans, max(0ll, sum - s[i]) + maxn);
        }
        suma += a[i]; sum -= a[i];
        maxn = max(maxn, suma - d[i]);
    }
    for (int i = n; i >= 2; i--) {
        sum += a[i];
        ans = max(ans, max(0ll, sum - d[i]) + max(0, a[1] - d[1]));
    }
    int minn = 10000000;
    for (int i = 2; i <= n; i++) minn = min(minn, d[i]);
    for (int i = 2; i <= n; i++) minn = min(minn, a[i]);
    ans = max(ans, sum + a[1] - d[1] - minn);
    print(ans, '\n');
    return 0;
}