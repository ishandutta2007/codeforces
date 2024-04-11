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
const int M = 1e9 + 7;
const int B = 600;

/*
*/

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    bool res = false;
    if(a == 1) {
        res = (n - 1) % b == 0;
    } else {
        for(li i = 1; i <= n; i *= a)
            if((n - i) % b == 0) {
                res = true;
                break;
            }
    }

    cout << (res ? "Yes" : "No") << endl;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}