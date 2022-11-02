#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 2010;
int n;
int a[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

const int MAXD = 10010;

ld p[MAXD / 2];
ld p2[MAXD];

ld ans = 0;

void run() {
    ld add = 2.0 / n / (n - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            if (a[i] <= a[j]) continue;
            p[a[i] - a[j]] += add;           
        }
    }

    for (int i = 0; i < MAXD / 2; i++) {
        for (int j = 0; j < MAXD / 2; j++) {
            p2[i + j] += p[i] * p[j];
        }
    }
    for (int i = 1; i < MAXD; i++) {
        p2[i] += p2[i - 1];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            if (a[j] <= a[i]) continue;
            ans += add * p2[a[j] - a[i] - 1];
        }
    }
}

void write() {
    cout.precision(20);
    cout.setf(ios::fixed);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}