#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int N = 2e5 + 10;
int n;
int a[N];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

void no() {
    cout << "NO\n";
    exit(0);
}

vector<vector<int>> ans;

void run() {
    if (n & 1) {
        for (int i = 1; i + 2 <= n; i += 2) {
            ans.push_back({i, i + 1, i + 2});
        }
        for (int i = n - 4; i >= 1; i -= 2) {
            ans.push_back({i, i + 1, i + 2});
        }
    } else {
        int Xor = 0;
        for (int i = 0; i < n; ++i) {
            Xor ^= a[i];
        }
        if (Xor) {
            no();
        }
        for (int i = 1; i + 2 <= n; i += 2) {
            ans.push_back({i, i + 1, i + 2});
        }
        for (int i = n - 5; i >= 1; i -= 2) {
            ans.push_back({i, i + 1, i + 2});
        }
    }
}

void write() {
    cout << "YES\n";
    assert(ans.size() <= n);
    cout << ans.size() << "\n";
    for (auto i : ans) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}