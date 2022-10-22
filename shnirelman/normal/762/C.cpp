#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();

    vector<int> p(n + 1, 0), s(n + 1, 0);
    for(int i = 0; i < n; i++) {
        p[i + 1] = p[i] + (p[i] < m && a[i] == b[p[i]]);
    }

    for(int i = n - 1; i >= 0; i--) {
        s[i] = s[i + 1] + (s[i + 1] < m && a[i] == b[m - s[i + 1] - 1]);
    }

    int res = m, ans = 0;
    for(int i = -1; i < n; i++) {
        int r = max(0, m - p[i + 1] - s[i + 1]);
        if(r < res) {
            res = r;
            ans = p[i + 1];
        }
    }

//    cout << ans << ' '<< res << endl;

    if(res == m) {
        cout << "-" << endl;
    } else {
        for(int i = 0; i < ans; i++)
            cout << b[i];
        for(int i = ans + res; i < m; i++)
            cout << b[i];
        cout << endl;
    }
}