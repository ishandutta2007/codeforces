#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

string a;

void read() {
    cin >> a;
}

ull ans;

void run() {
    ans = 1;
    for (int i = 0; i < (int)a.size() + 1; i++) {
        int j = i;
        while (j < (int)a.size() - 1 && a[j] - '0' + a[j + 1] - '0' == 9) {
            j++;
        }
        if (j == i) continue;

        if ((j - i) % 2 == 0) {
            ans *= (j - i) / 2 + 1;
        }

        i = j;
    }
}

void write() {
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