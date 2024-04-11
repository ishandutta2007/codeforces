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
const int N = 2e5;
const int LOGN = 20;
const int K = 11;
const int M = 998244353;//1e9 + 7;
const int A = 26;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

/*

*/

void color(int b, int i, int j) {
    cout << b << ' ' << i + 1 << ' ' << j + 1 << endl;
}

void solve() {
    int n;
    cin >> n;

    int c0 = 0, c1 = 0;

    vector<vector<int>> a(n, vector<int>(n, -1));
    vector<pii> pos0, pos1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if((i + j) % 2 != 0) {
                pos1.emplace_back(i, j);
            } else {
                pos0.emplace_back(i, j);
            }
        }
    }

    for(int i = 0; i < n * n && c0 < pos0.size() && c1 < pos1.size(); i++) {
        int x;
        cin >> x;

        if(x == 1) {
            int i1 = pos1[c1].f, j1 = pos1[c1].s;
            color(2, i1, j1);
            c1++;
        } else {
            int i1 = pos0[c0].f, j1 = pos0[c0].s;
            color(1, i1, j1);
            c0++;
        }
    }

    while(c0 < pos0.size() || c1 < pos1.size()) {
        int x;
        cin >> x;

        if(c1 < pos1.size()) {
            int i1 = pos1[c1].f, j1 = pos1[c1].s;
            color(x == 2 ? 3 : 2, i1, j1);
            c1++;
        } else {
            int i1 = pos0[c0].f, j1 = pos0[c0].s;
            color(x == 1 ? 3 : 1, i1, j1);
            c0++;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();

}