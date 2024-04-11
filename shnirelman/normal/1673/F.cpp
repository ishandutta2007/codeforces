#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 32 + 13;
const int K = 513;
const int M = 1e9 + 7;
const int LOGN = 20;
const int A = 26;

int d[] = {1, 4, 1, 16, 1, 4, 1, 64, 1, 4, 1, 16, 1, 4, 1, 256, 1, 4, 1, 16, 1, 4, 1, 64, 1, 4, 1, 16, 1, 4, 1};

int y[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1; j++)
            cout << d[j] << ' ';
        cout << endl;
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n; j++)
            cout << d[i] * 2 << ' ';
        cout << endl;
    }

//    y[0][0] = 0;
    map<int, pii> mp;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0) {
                if(j == 0)
                    y[i][j] = 0;
                else
                    y[i][j] = y[i][j - 1] ^ d[j - 1];
            } else {
                y[i][j] = y[i - 1][j] ^ (2 * d[i - 1]);
            }

//            if(mp.count(y[i][j])) {
//                cout << "zgdsfhg" << endl;
//            }

            mp[y[i][j]] = pii(i, j);
        }
    }

    int cur = 0;
    for(int ind = 0; ind < k; ind++) {
        int x;
        cin >> x;

        cur ^= x;

        pii p = mp[cur];
        cout << p.f + 1 << ' ' << p.s + 1 << endl;
    }

//    int t;
//    cin >> t;
//
//    while(t--)
//        solve();
}