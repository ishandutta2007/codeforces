#include <bits/stdc++.h>

#define x first
#define y second

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
using li = long long;
using ld = long double;

const int M = 1e9 + 7;
//const li INF = 1e18;
const int INF = 1e9;

void solve() {
    int n;
    cin >> n;

    int mn = INF, mx = -INF;

    for(int i = 0;i < n; i++) {
        int a, b;
        cin >> a >> b;
        mn = min(mn, b);
        mx = max(mx, a);
    }

    cout  << max(0, mx - mn) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>> t;
        while(t--)
            solve();
}