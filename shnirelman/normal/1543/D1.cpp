#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 200000 + 13;
const int M = 998244353;
const int B = 600;
const ld e = 1e-9;
/*
1
0.2 0.2 0.6 0.2

1
0.4998 0.4998 0.0004 0.1666
*/


void solve() {
    int n, k;
    cin >> n >> k;

    int x = 0;
    for(int i = 0; i < n; i++) {
        int y = (x ^ i);

        cout << y << endl;

        int r;
        cin >> r;

        if(r == 1)
            return;

        x ^= y;
    }
}


signed main() {

    int t = 1;
    cin >> t;

    while(t--)
        solve();


}