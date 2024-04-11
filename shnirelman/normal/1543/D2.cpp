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

    int m = 20;
    vector<vector<int>> a(m, vector<int>(k));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < k; j++)
            a[i][j] = j;
    }

    for(int i = 0; i < n; i++) {
        vector<int> dig(m);
        int x = i;
        for(int j = 0; j < m; j++) {
            dig[j] = x % k;
            x /= k;
        }

        int y = 0;
        int pw = 1;
        for(int j = 0; j < m; j++) {
            y += pw * a[j][dig[j]];
            dig[j] = a[j][dig[j]];
            pw *= k;
        }

        cout << y << endl;
        int r;

        cin >> r;

        if(r == 1)
            return;

        for(int j = 0; j < m; j++) {
            for(int c = 0; c < k; c++) {
                a[j][c] = (k + dig[j] - a[j][c]) % k;
            }
        }
    }
}


signed main() {

    int t = 1;
    cin >> t;

    while(t--)
        solve();


}