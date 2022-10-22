//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;
//using matr

const li INF = 2e18 + 13;
const int N = 2e5 + 13;
const int M = 10;//998244353;
const int B = 300;
//const int A = 26;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

/*
1
4 11
2 6 14 18
0 3
4 5
11 15
3 5
10 13
16 16
1 4
8 12
17 19
7 13
14 19

1
4 12
-9 -16 12 3
-20 -18
-14 -13
-10 -7
-3 -1
0 4
6 11
7 9
8 10
13 15
14 18
16 17
18 19
*/

li dp[N][M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < M; j++)
            dp[i][j] = -INF;
    }

    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;

        vector<vector<int>> a(3);
        for(int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;

            a[x - 1].push_back(y);
        }

        for(int i = 0; i < 3; i++)
            sort(a[i].rbegin(), a[i].rend());

        for(int j = 0; j < M; j++) if(dp[i][j] >= 0) {

//            cout << i << ' ' << j << ' ' << dp[i][j] << endl;
            for(int x = 0; x <= 3 && x <= a[0].size(); x++) {
//                cout << "x " << x << endl;
                for(int y = 0; y * 2 + x <= 3 && y <= a[1].size(); y++) {
//                    cout << "y " << y << endl;
                    for(int z = 0; z * 3 + y * 2 + x <= 3 && z <= a[2].size(); z++) {
//                        cout << "xyz" << x << ' ' << y << ' ' << z << endl;
                        int mx = 0;
                        li sum = 0;
                        for(int l = 0; l < x; l++)
                            mx = max(mx, a[0][l]), sum += a[0][l];
                        for(int l = 0; l < y; l++)
                            mx = max(mx, a[1][l]), sum += a[1][l];
                        for(int l = 0; l < z; l++)
                            mx = max(mx, a[2][l]), sum += a[2][l];

                        int nj = j + x + y + z;

                        if(nj >= M)
                            dp[i + 1][nj % M] = max(dp[i + 1][nj % M], dp[i][j] + sum + mx);
                        else
                            dp[i + 1][nj] = max(dp[i + 1][nj], dp[i][j] + sum);
                    }
                }
            }
        }
    }

    li mx = 0;
    for(int i = 0; i < M; i++)
        mx = max(mx, dp[n][i]);

    cout << mx << endl;
}