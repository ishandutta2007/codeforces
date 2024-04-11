#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 1e9 + 7;
const int N = 5000 + 13;
const int LOGN = 30;
const int L = 2001;

void solve() {
    int n = 2;

    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    }

    if(a[0][0] == 0 && a[0][1] == 0 && a[1][0] == 0 && a[1][1] == 0)
        cout << 0 << endl;
    else if(a[0][0] == 0 || a[0][1] == 0 || a[1][0] == 0 || a[1][1] == 0)
        cout << 1 << endl;
    else
        cout << 2 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}