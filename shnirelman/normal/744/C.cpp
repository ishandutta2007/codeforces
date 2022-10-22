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

const int INF = 1e9 + 13;
const int N = 16;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 16 * 16;

mt19937 rnd(0);

int n;

int dp[1 << N][K];
int r[1 << N], b[1 << N];
int sr[1 << N], sb[1 << N];
bool c[N];
int x[N], y[N];

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        char ch;
        cin >> ch >> x[i] >> y[i];

        c[i] = (ch == 'B');
    }

    for(int mask = 0; mask < (1 << n); mask++) {
        for(int i = 0; i < n; i++)
            if((mask >> i) & 1) {
                if(c[i])
                    b[mask]++;
                else
                    r[mask]++;
                sr[mask] += x[i];
                sb[mask] += y[i];
            }
    }


    for(int mask = 0; mask < (1 << n); mask++) {
        for(int i = 0; i < K; i++)
            dp[mask][i] = INF;
    }

    int zero = K / 2;

    dp[0][zero] = 0;

    for(int mask = 0; mask < (1 << n); mask++) {
        for(int i = 0; i < n; i++) {
            if(((mask >> i) & 1) == 0) {
                int nmask = (mask | (1 << i));

                int x1 = max(0, x[i] - r[mask]);
                int y1 = max(0, y[i] - b[mask]);

                for(int d = 0; d < K; d++) if(dp[mask][d] < INF) {
                    int d1 = d - zero;

                    int x2;// = dp[mask][d] - sr[mask];
                    int y2;// = dp[mask][d] - sb[mask] + d1;

                    if(dp[mask][d] + d1 - sr[mask] < dp[mask][d] - sb[mask]) {
                        x2 = 0;
                        y2 = sr[mask] - d1 - sb[mask];
                    } else {
                        y2 = 0;
                        x2 = sb[mask] + d1 - sr[mask];
                    }

                    int x3 = x1 - x2;
                    int y3 = y1 - y2;

                    int d3 = d + (x[i] - x1) + (y1 - y[i]);

//                    if(mask == 5) {
//                        cout << "mask " << 6 << " i " << i << " d " << d <<  " d3 " << d3 << " new " << dp[mask][d] + max(x3, y3) << endl;
//                        cout << x[i] << ' ' << y[i] << endl;
//                        cout << x1 << ' ' << y1 << endl;
//                        cout << x2 << ' ' << y2 << endl;
//                    }

                    dp[nmask][d3] = min(dp[nmask][d3], dp[mask][d] + max(x3, y3));
                }
            }
        }
    }

//    for(int mask = 0; mask < (1 << n); mask++) {
//        for(int d = 0; d < K; d++) if(dp[mask][d] < INF) {
//            for(int i = 0; i < n; i++)
//                cout << ((mask >> i) & 1);
//            cout << ' ' << d - zero << ' ' << dp[mask][d] << endl;
//        }
//    }


    int mn = INF;
    for(int i = 0; i < K; i++) {
        mn = min(mn, dp[(1 << n) - 1][i]);
//        cout << mn << ' ' << dp[(1 << n) - 1][i] << endl;
    }


    cout << mn + n << endl;
}