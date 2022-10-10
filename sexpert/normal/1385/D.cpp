#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n;
string s;

int cost(int l, int r, int c) {
    if(l == r) {
        if(s[l] - 'a' == c)
            return 0;
        return 1;
    }
    int m = (l + r)/2;
    int res = INT_MAX, cur = 0;
    for(int i = l; i <= m; i++) {
        if(s[i] - 'a' != c)
            cur++;
    }
    res = min(res, cur + cost(m + 1, r, c + 1));
    cur = 0;
    for(int i = m + 1; i <= r; i++) {
        if(s[i] - 'a' != c)
            cur++;
    }
    res = min(res, cur + cost(l, m, c + 1));
    return res;
}

void solve() {
    cin >> n >> s;
    cout << cost(0, n - 1, 0) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}