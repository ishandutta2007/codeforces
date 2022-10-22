#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<string> b(n, ""), c(n, "");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            b[i] += (((i + j) % 2 == 0) ? "R" : "W");
            c[i] += (((i + j) % 2 == 1) ? 'R' : 'W');
        }
    }

    bool isc = true, isb = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] != '.') {
                if(a[i][j] != b[i][j])
                    isb = false;
                else
                    isc = false;
            }
        }
    }

    if(!isc && !isb) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << (isb ? b[i][j] : c[i][j]);
            }
            cout << endl;
        }
    }
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}