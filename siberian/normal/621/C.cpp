#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 1e5 + 10;
int n, p;
int l[MAXN], r[MAXN];

void read() {
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }
}

int get(int x) {
    return x / p;
}

ld calc(int a, int b) {
    int cnt_a = get(r[a]) - get(l[a] - 1);
    int len_a = r[a] - l[a] + 1;
    int cnt_b = get(r[b]) - get(l[b] - 1);
    int len_b = r[b] - l[b] + 1;
    ld pa = (ld) cnt_a / len_a;
    ld pb = (ld) cnt_b / len_b;
    return pa + pb - pa * pb;
}

ld ans;

void run() {
    ans = 0;
    for (int i = 0; i < n; i++) {
        ans += calc(i, (i + 1) % n);
    }
    ans *= 2000;
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