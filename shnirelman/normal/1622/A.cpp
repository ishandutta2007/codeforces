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
const int N = 2e5 + 113;
const int K = 1e5 + 113;
const int M = 998244353;//1e9 + 7;
const int A = 26;

mt19937 rnd(3432);


/*
*/

bool is(int a, int b, int c) {
    if(b == c) {
        return a % 2 == 0;
    } else {
        return (a == b + c);
    }
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << (is(a, b, c) || is(b, a, c) || is(c, a, b) ? "YES" : "NO") << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}