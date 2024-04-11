#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 998244353;
const int N = 3e5 + 13;
const int LOGN = 20;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> p1(n + 1, 0), p2(n + 1, 0);
    for(int i = 0; i < n; i++) {
        p1[i + 1] = p1[i] + (s[i] == 'D');
        p2[i + 1] = p2[i] + (s[i] == 'K');
    }

    vector<int> ans(n, 0);
    set<pii> used;

    for(int i = 1; i <= n; i++) {
        int x = p1[i], y = p2[i];
        int g = __gcd(x, y);
        if(g != 0) {
            x /= g;
            y /= g;
        }

        if(used.count({x, y}))
            continue;
        used.insert({x, y});

        int lst = 0;
        int cur = 0;
        for(int j = i; j <= n; j += x + y) {
            if((p1[j] - p1[lst]) * 1ll * y == x * 1ll * (p2[j] - p2[lst])) {
                ans[j - 1] = max(ans[j - 1], ++cur);
            }
        }
    }

    for(auto x : ans)
        cout << x << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while(t--)
        solve();
}