#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 2e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 3e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 1e9 + 7;
//const int M = 998244353;
const int A = 1e6 + 13;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

void NO() {
    cout << "NO" << endl;
    exit(0);
}

void solve() {
    li n;
    cin >> n;

    vector<int> d;
    while(n > 0) {
        d.push_back(n % 10);
        n /= 10;
    }

//    for(int x : d)
//        cout << x << ' ';
//    cout << endl;

    vector<vector<pii>> res(d.size() + 1, vector<pii>(5, pii(-1, -1)));
    res[0][0] = {0, 0};
    for(int i = 0; i < d.size(); i++) {
        for(int j = 0; j < 5; j++) if(res[i][j].f != -1) {
            for(int x = 0; x <= 6; x++) {
                for(int y = 0; y + x <= 6; y++) {
                    if((j + x * 4 + y * 7) % 10 == d[i]) {
                        res[i + 1][(j + x * 4 + y * 7) / 10] = {x, y};
//                        cout << "calc " << i << ' ' << j << ' ' << x << ' ' << y << ' ' << (j + x * 4 + y * 7) / 10 << endl;
                    }
                }
            }
        }
    }

//    for(int i = 0; i < 5; i++) {
        int i = 0;
        if(res[d.size()][i].f != -1) {
            vector<li> ans(6, 0);
            for(int j = d.size(); j > 0; j--) {
                int x = res[j][i].f, y = res[j][i].s;
//                cout << i << ' ' << x << ' ' << y << endl;
                for(int k = 0; k < x; k++)
                    ans[k] = ans[k] * 10 + 4;
                for(int k = x; k < x + y; k++)
                    ans[k] = ans[k] * 10 + 7;
                for(int k = x + y; k < 6; k++)
                    ans[k] *= 10;

                i = (d[j - 1] + 100 - x * 4 - y * 7) % 10;
//                cout << "new i " << i << ' ' << d[j] << endl;
            }

            for(li x : ans)
                cout << x << ' ';
            cout << endl;
            return;
        }
//    }

    cout << -1 << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}