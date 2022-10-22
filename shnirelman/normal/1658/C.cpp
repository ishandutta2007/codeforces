#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
//const int M = 1e9 + 7;
const int M = 998244353;
const int N = 2e5 + 13;
const int LOGN = 30;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int pos = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        if(a[i] == 1) {
            if(pos == -1)
                pos = i;
            else {
                cout << "NO" << endl;
                return;
            }
        }
    }

    if(pos == -1) {
        cout << "NO" << endl;
        return;
    }

    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        b[i] = a[(pos + i) % n];
    }

    for(int i = 1; i < n; i++) {
        if(b[i] > b[i - 1] + 1) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}