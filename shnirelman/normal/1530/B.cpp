#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;

mt19937 rnd(36547);

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> a(n, "");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            a[i] += '0';
    }

    a[0][0] = '1';
    for(int j = 1; j < m; j++) {
        if(a[0][j - 1] == '0') {
            a[0][j] = '1';
        }
    }

    for(int i = 1; i < n; i++) {
        if(a[i - 1][m - 1]  == '0' && a[i - 1][m - 2] == '0')
            a[i][m - 1] = '1';
    }

    for(int j = m - 2; j >= 0; j--) {
        if(a[n - 1][j + 1] == '0' && a[n - 2][j + 1] == '0')
            a[n - 1][j] = '1';
    }

    for(int i = n - 2; i > 0; i--) {
        if(a[i + 1][0] == '0' && a[i + 1][1] == '0' && a[i - 1][0] == '0' && a[i - 1][1] == '0')
            a[i][0] = '1';
    }

    for(auto b : a)
        cout << b << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}