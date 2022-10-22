//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 20000 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;

mt19937 rnd(time(0));

/*
1
8 5
2 1 7 4
4 2

*/

void solve() {
    int W, H, x1, y1, x2, y2, w, h;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;

    int ans = INF;

    if(H >= h + y2 - y1) {
        ans = min(ans, max(0, y2 - H + h));
//        cout << ans << endl;
        ans = min(ans, max(0, h - y1));
    }

    if(W >= w + x2 - x1) {
        ans = min(ans, max(0, x2 - W + w));
        ans = min(ans, max(0, w - x1));
    }

    cout << (ans < INF ? ans : -1) << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}