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

    vector<vector<int>> a(n, vector<int> (4));
    int s = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        int s1 = 0;
        for(int j = 0; j < 4; j++) {
            cin >> a[i][j];
            s1 += a[i][j];
        }

        if(i == 0)
            s = s1;
        else
            ans += (s < s1);
    }

    cout << ans + 1 << endl;
}

signed main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}