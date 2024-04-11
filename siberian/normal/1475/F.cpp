#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

void row(vector<string>& a, int i) {
    for (int j = 0; j < a.size(); ++j) {
        a[i][j] = ((a[i][j] - '0') ^ 1) + '0';
    }
}

void col(vector<string>& a, int j) {
    for (int i = 0; i < a.size(); ++i) {
        a[i][j] = ((a[i][j] - '0') ^ 1) + '0';
    }
}

bool check1(vector<string> a, vector<string> b) {
    for (int j = 0; j < a.size(); ++j) {
        if (a[0][j] != b[0][j]) {
            col(a, j);
        }
    }
    for (int i = 0; i < a.size(); ++i) {
        int cnt = 0;
        for (int j = 0; j < b.size(); ++j) {
            cnt += a[i][j] != b[i][j];
        }
        if (cnt != 0 && cnt != a.size()) return false;
    }
    return true;
}

bool check2(vector<string> a, vector<string> b) {
    row(a, 0);
    return check1(a, b);
}

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    vector<string> b(n);
    for (auto& i : b) {
        cin >> i;
    }
    if (check1(a, b) || check2(a, b)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}