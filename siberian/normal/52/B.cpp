#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll
const int MAXN = 1010;
char table[MAXN][MAXN];
int n, m;

void read() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }
}

int ans;

int cnt[MAXN][2];

void build() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (table[i][j] == '*') {
                cnt[i][0]++;
                cnt[j][1]++;
            }
        }
    }
}

void calc() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (table[i][j] == '*') {
                ans += (cnt[i][0] - 1) * (cnt[j][1] - 1);
            }
        }
    }
}

void run() {
    ans = 0;
    build();
    calc();
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