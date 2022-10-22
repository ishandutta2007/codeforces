#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 5000 + 13;
const int M = 1e9 + 7;
const int B = 600;

int a[N];
int res[N][N];
int f[N][N];
//int s[N];

/*
7
8 0 3 8 9 2 7
1
1 7

16
1 3 5 5 3 6 2 7 5 7 7 3 1 5 9 5
1
1 15

13
7 1 1 5 5 5 0 7 0 0 2 4 8
1
1 13
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

//    s[0] = 0;
//    for(int i = 1; i <= n; i++)
//        s[i] = s[i - 1] ^ a[i - 1];

    for(int i = 0; i < n; i++) {
        res[i][i + 1] = a[i];
        f[i][i + 1] = a[i];
    }

//    for(int i = 0; i < n - 1; i++) {
//        res[i][i + 2] = max(max(a[i], a[i + 1]), a[i] ^ a[i + 1]);
//    }
//
//    for(int i = 0; i < n - 2; i++) {
//        res[i][i + 3] = max(max(res[i][i + 2], res[i + 1][i + 3]), a[i] ^ a[i + 2]);
//    }
//
//    for(int i = 0; i < n - 3; i++) {
//        res[i][i + 4] = max(max(res[i][i + 3], res[i + 1][i + 4]), a[i] ^ a[i + 2] ^ a[i + 1] ^ a[i + 3]);
//    }

    for(int len = 2; len <= n; len++) {
        for(int l = 0; l + len <= n; l++) {
            int r = l + len;
            res[l][r] = max(res[l][r - 1], res[l + 1][r]);
            f[l][r] = f[l][r - 1] ^ f[l + 1][r];
            res[l][r] = max(res[l][r], f[l][r]);

//            cout << len << ' ' << l << ' ' << r << ' ' << res[l][r] << endl;
        }
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        cout << res[l - 1][r] << '\n';
    }
}