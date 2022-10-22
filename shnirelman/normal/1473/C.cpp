#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using pii = pair<int, int>;
using ld = long double;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

void solve() {
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < k - (n - k) - 1; i++) {
        cout << i + 1 << ' ';
    }

    for(int i = k - (n - k) - 1; i < k; i++) {
        cout << k - i + k - (n - k) - 1  << ' ';
    }

    cout << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}