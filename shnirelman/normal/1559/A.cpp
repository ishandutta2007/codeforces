//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const li INF = 1e18 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 8;

mt19937 rnd(0);

void solve() {
    int n;
    cin >> n;

    int res = (1 << 30) - 1;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        res &= x;
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}