#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 5000 + 113;
const int K = 1e5 + 113;
const int M = 998244353;//1e9 + 7;
const int A = 26;

mt19937 rnd(3432);

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}


/*

*/

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
//        cout << s[i] << endl;
    }

//    return;
    int ans = -1;
    vector<int> p(m, -1);
    for(int mask = 0; mask < (1 << n); mask++) {
        vector<pii> c(m);
        for(int i = 0; i < m; i++) {
            c[i] = {0, i};
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(s[j][i] == '1')
                    if(mask & (1 << j)) {
                        c[i].f++;
                    } else {
                        c[i].f--;
                    }
            }
        }

        sort(c.begin(), c.end());

        vector<int> b(n);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(s[j][c[i].s] == '1')
                    b[j] += i + 1;
            }
        }

        int res = 0;
        for(int i = 0; i < n; i++) {
            res += abs(a[i] - b[i]);
        }

        if(res > ans) {
//            cout << res << endl;
            ans = res;
            for(int i = 0; i < m; i++) {
                p[c[i].s] = i + 1;
            }
//            for(int i = 0; i < m; i++)
        }
    }

//    cout << ans << endl;
    for(auto x : p)
        cout << x << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}