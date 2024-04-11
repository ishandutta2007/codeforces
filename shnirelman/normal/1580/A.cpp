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

//const li INF = 2e18 + 13;
const int INF = 1e9 + 13;
const int N = 400 + 13;
const int M = 998244353;
const int B = 300;
//const int A = 26;
//const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

int sum(int a, int b) {
    a += b;

    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

/*
*/

int s[N][N];

int get(int i1, int j1, int i2, int j2) {
    return s[i2 + 1][j2 + 1] - s[i1][j2 + 1] - s[i2 + 1][j1] + s[i1][j1];
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

//    vector<vector<int>> s(n + 1, vector<int>(m + 1, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + (a[i][j] - '0');
        }
    }

    int ans = 16;

    for(int i1 = 0; i1 < n; i1++) {
        for(int i2 = i1 + 4; i2 < n; i2++) {
            int cur = INF;
            int i = i2 - i1 + 1;
            for(int j2 = 3; j2 < m; j2++) {
                int rs = get(i1 + 1, j2 - 2, i2 - 1, j2 - 1);//s[i2][j2] - s[i2][j2 - 2] - s[i1][j2] + s[i1][j2 - 2];
                rs += i - 2 - get(i1 + 1, j2 - 3, i2 - 1, j2 - 3);
                rs += 2 - get(i1, j2 - 2, i1, j2 - 1);
                rs += 2 - get(i2, j2 - 2, i2, j2 - 1);

                cur += get(i1 + 1, j2 - 1, i2 - 1, j2 - 1) + (a[i1][j2 - 1] == '0') + (a[i2][j2 - 1] == '0');

                cur = min(cur, rs);

                ans = min(ans, cur + i - 2 - get(i1 + 1, j2, i2 - 1, j2));
            }
        }
    }

//    for(int i = 5; i <= n; i++) {
//        for(int j = 4; j <= m; j++) {
//            int res = s[i - 1][j - 1] - s[i - 1][1] - s[1][j - 1] + s[1][1];
//            res += i - 2 - s[i - 1][1] + (a[0][0] - '0');
//            res += i - 2 - s[i - 1][j] + s[i - 1][j - 1] + (a[0][j - 1] - '0');
//            res += j - 2 - s[1][j - 1] + (a[0][0] - '0');
//            res += j - 2 - s[i][j - 1] + s[i - 1][j - 1] + (a[i - 1][0] - '0');
//
//            ans = min(ans, res);
//            cout << i << ' ' << j << ' ' << res << endl;
//        }
//    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }



}