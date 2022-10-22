#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const int M = 1e9 + 7;
const int N = 3e5 + 13;
const ld eps = 1e-4;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int x = a[0] - 1; x <= a[0] + 1; x++) {
        bool res = true;
        int lst = x;
        for(int i = 1; i < n; i++) {
            if(abs(lst - a[i]) > 2) {
                res = false;
                break;
            }
            lst++;
        }

        if(res) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}