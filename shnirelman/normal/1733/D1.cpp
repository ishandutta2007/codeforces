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

    string a, b;
    cin >> a >> b;

    vector<int> pos;
    for(int i = 0; i < n; i++)
        if(a[i] != b[i])
            pos.push_back(i);

    if(pos.size() % 2 != 0) {
        cout << -1 << endl;
        return;
    }

    li ans = 0;
    for(int i = 0; i < pos.size() / 2; i++) {
        ans += (pos[i] + 1 == pos[i + pos.size() / 2] ? min(x, y * 2) : y);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}