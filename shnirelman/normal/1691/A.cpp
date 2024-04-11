#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2013;
const int K = 9;

void solve() {
    int n;
    cin >> n;

    int odd = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        odd += x % 2;
    }

    cout << min(odd, n - odd) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}