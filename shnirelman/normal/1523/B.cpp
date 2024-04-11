#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<li, li>;

const int INF = 1e9 + 14;
const int M = 998244353;
const int N = 2e5 + 13;

/*
1
3 2
101
*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << n * 3 << endl;
    for(int i = 0; i < n; i += 2) {
        int x = i + 1, y = i + 2;

        cout << 2 << ' ' << x << ' ' << y << endl;
        cout << 1 << ' ' << x << ' ' << y << endl;
        cout << 2 << ' ' << x << ' ' << y << endl;
        cout << 1 << ' ' << x << ' ' << y << endl;
        cout << 2 << ' ' << x << ' ' << y << endl;
        cout << 1 << ' ' << x << ' ' << y << endl;

    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}