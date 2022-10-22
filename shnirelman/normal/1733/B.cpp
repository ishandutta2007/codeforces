#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const int M = 998244353;
const int N = 2e5 + 13;


void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    if(x > y)
        swap(x, y);

    if(x != 0 || y == 0 || (n - 1) % y != 0) {
        cout << -1 << endl;
        return;
    }

//    int cur = 0;
    for(int i = 0; i < n - 1; i++) {
        cout << (i - i % y) + 2 << ' ';
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