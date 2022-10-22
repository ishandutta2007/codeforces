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

void solve() {
    int n, m, i, j, x, y;
    cin >> n >> m >> i >> j >> x >> y;

    i--;
    j--;
    x--;
    y--;

    int di = 1, dj = 1;

    int ans = min(i <= x ? x - i : n - i - 1 + n - x - 1, j <= y ? y - j : m - 1 - y + m - 1 - j);
//    set<pii> st;
//    while(i != x && j != y && st.count({i, j}) == 0) {
//        st.insert({i, j});
//        int i1 = i + di;
//        int j1 = j + dj;
//
//        if(i1 < 0)
//            di = -di; //i1 = i + di;
//        if(i1 >= n)
//            di = -di; //i1 = i - di;
//        if(j1 < 0)
//            dj = -dj; //j1 = j + dj;
//        if(j1 >= m)
//            dj = -dj; //j1 = j + dj;
//
//        i += di;
//        j += dj;
//
//        ans++;
//    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}