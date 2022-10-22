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
const int N = 2e5 + 13;
const int LOGN = 30;
const int L = 2001;

void solve() {
    int n;
    cin >> n;

    if(n % 2 == 0) {
        cout << n / 2 << ' ' << n / 2 << ' ' << 0 << endl;
    } else {
        if(n == 1) {
            cout << -1 << endl;
        } else {
            int x = n / 2;
            for(int i = max(0, x - 5); i <= (x + 5); i++) {
                if(i + 1 + (i ^ 1) == n) {
                    cout << (i ^ 1) << ' ' << i << ' ' << 1 << endl;
                    return;
                }
            }

            cout << -1 << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}