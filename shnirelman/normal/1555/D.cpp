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
const int N = 200000 + 13;
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

//void solve() {
//}

int sum[N][3][3];

int main() {
 //
//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();

    int n, m;
    cin >>n >> m;

    string s;
    cin >> s;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++)
                sum[i + 1][j][k] = sum[i][j][k];

        sum[i + 1][i % 3][s[i] - 'a']++;
    }

//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < 3; j++) {
//            cout << "i : " << i << " j : " << j << "  ";
//            for(int k = 0; k < 3; k++)
//                cout << sum[i + 1][j][k] << ' ';
//            cout << endl;
//        }
//        cout << endl;
//    }

    for(int ind = 0; ind < m; ind++) {
        int l, r;
        cin >> l >> r;

        l--;

        int ans = INF;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) if(i != j) {
                ans = min(ans, r - l - (sum[r][i][0] - sum[l][i][0] + sum[r][j][1] - sum[l][j][1] + sum[r][i ^ j ^ 3][2] - sum[l][i ^ j ^ 3][2]));
            }
        }

        cout << ans << '\n';
    }
}