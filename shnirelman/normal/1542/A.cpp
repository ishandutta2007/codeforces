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
    int n;
    cin >> n;

    int cnt = 0;
    for(int i = 0; i < n * 2; i++) {
        int x;
        cin >> x;

        cnt += (x % 2);
    }

    cout << (cnt == n ? "Yes" : "No") << endl;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}