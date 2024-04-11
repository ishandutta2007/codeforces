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
    int n;
    cin >> n;

    int d = 2;
    cout << d << endl;

    vector<bool> used(n + 1, false);

    for(int i = 1; i <= n; i++) {
        if(!used[i]) {
            int x = i;
            while(x <= n) {
                cout << x << ' ';
                used[x] = true;
                x *= 2;
            }
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}