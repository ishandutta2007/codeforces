#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;

void read() {
    cin >> n;
    if (n & 1) {
        cout << -1 << endl;
        exit(0);
    }
}

const int MAXN = 110;
int ans[MAXN][MAXN];
vector<char> c = {'b', 'w'};
void run() {
    for (int x = 0; x < n / 2; x++) {
        for (int y = x; y < n - x; y++) {
            ans[x][y] = x % 2;
            ans[n - 1 - x][y] = x % 2;
            ans[y][x] = x % 2;
            ans[y][n - 1 - x] = x % 2;
        }
    }
}

void write() {
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                cout << c[(i + ans[x][y]) % 2];
            }
            cout << "\n";
        }
        cout << "\n";
    }
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