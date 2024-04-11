#include <bits/stdc++.h>

#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

const int M = 1e9 + 7;
const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int A = 26;
const int B = 300;

void solve() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;

    cout << max(r - 1, n - r) + max(c - 1, m - c) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}