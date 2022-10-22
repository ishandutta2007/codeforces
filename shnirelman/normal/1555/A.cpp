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

*/

void solve() {
    li n;
    cin >> n;

    if(n % 2 == 1)
        n++;

    li m = max((n - 100) / 10, 0ll);
    li ans = m * 25;
    n -= m * 10;

    int res = INF;
    for(int a = 0; a * 6 <= n + 6; a++) {
        for(int b = 0; b * 8 + a * 6 <= n + 8; b++) {
            int c = (n - a * 6 - b * 8 + 9) / 10;
            res = min(res, a * 15 + b * 20 + c * 25);
        }
    }

    cout << ans + res << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}