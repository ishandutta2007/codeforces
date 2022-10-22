#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 3e5 + 13;
const int LOGN = 20;
const int A = 27;

int p[N][A];

void solve() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < A; j++)
            p[i + 1][j] = p[i][j] + (s[i] == char('a' + j));
    }

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        l--;

        int res = 0;
        for(int j = 0; j < A; j++) {
            res += (p[r][j] - p[l][j]) * (j + 1);
//            cout << j << ' ' << p[r][j] << ' ' << p[l][j] << endl;
        }

        cout << res << endl;
    }
}

int main() {
    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}