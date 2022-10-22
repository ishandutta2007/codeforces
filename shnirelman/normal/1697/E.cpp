#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 100 + 13;
const int K = 513;
const int M = 998244353;
const int LOGN = 20;
const int A = 26;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int C[N][N];
int f[N];

int p[N], sz[N];

int getp(int x) {
    return (p[x] == x ? x : p[x] = getp(p[x]));
}

void unite(int x, int y) {
    x = getp(x);
    y = getp(y);

    if(x == y)
        return;

    if(sz[x] < sz[y])
        swap(x, y);

    sz[x] += sz[y];
    p[y] = x;
}

pii a[N];
int d[N][N];
int b[N];
int mn[N], cnt[N];

int dp[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i < N; i++) {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++)
            C[i][j] = sum(C[i - 1][j - 1], C[i - 1][j]);
    }

    f[0] = 1;
    for(int i = 1; i < N; i++) {
        f[i] = mul(f[i - 1], i);
    }

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        p[i] = i;
        sz[i] = 1;
        b[i] = INF;
    }

    for(int i = 0; i < n; i++) {
        cin >> a[i].f >> a[i].s;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) if(i != j) {
            d[i][j] = abs(a[i].f - a[j].f) + abs(a[i].s - a[j].s);
            b[i] = min(b[i], d[i][j]);
//            cout << d[i][j] << ' ';
        }
//        cout << endl;
    }


//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < n; j++) if(i != j) {
//            for(int k = 0; k < n; k++) if(i != k && j != k) {
//                if(d[i][j] == d[i][k] && d[i][j] == d[j][k] && d[i][j] == b[i] && d[i][j] == b[j] && d[i][j] == b[k]) {
//                    unite(i, j);
//                    unite(j, k);
////                    b[i] = b[j] = b[k] = d[i][j];
////                    cout << "triangle " << i << ' ' << j << ' ' << k << endl;
//                }
//            }
//        }
//    }

    for(int i = 0; i < n; i++) {
        mn[i] = -1;
        for(int j = 0; j < n; j++) if(i != j) {
            if(mn[i] == -1 || d[i][mn[i]] > d[i][j]) {
                mn[i] = j;
                cnt[i] = 1;
            } else if(d[i][mn[i]] == d[i][j])
                cnt[i]++;
        }

//        if(cnt != 1 || p[i] != i && sz[i] != 1) {
//            mn[i] = -1;
//        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                for(int l = k + 1; l < n; l++)
                if(d[i][j] == d[i][k] && d[i][j] == d[j][k] && d[i][j] == d[i][l] && d[i][j] == d[j][l] && d[i][j] == d[k][l]
                   && d[i][j] == b[i] && d[i][j] == b[j] && d[i][j] == b[k] && d[i][j] == b[l] &&
                   cnt[i] == 3 && cnt[j] == 3 && cnt[k] == 3 && cnt[l] == 3) {
                    unite(i, j);
                    unite(j, k);
                    unite(k, l);
//                    b[i] = b[j] = b[k] = d[i][j];
//                    cout << "triangle " << i << ' ' << j << ' ' << k << endl;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) if(i != j) {
            for(int k = 0; k < n; k++) if(i != k && j != k) {
                if(d[i][j] == d[i][k] && d[i][j] == d[j][k] && d[i][j] == b[i] && d[i][j] == b[j] &&
                   d[i][j] == b[k] && cnt[i] == 2 && cnt[j] == 2 && cnt[k] == 2) {
                    unite(i, j);
                    unite(j, k);
//                    b[i] = b[j] = b[k] = d[i][j];
//                    cout << "triangle " << i << ' ' << j << ' ' << k << endl;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) if(i != j) {
            if(d[i][j] == b[i] && d[i][j] == b[j] &&
                cnt[i] == 1 && cnt[j] == 1) {
                unite(i, j);
//                cout << "pair " << i << ' ' << j << endl;
            }
        }
    }


//    for(int i = 0; i < n; i++) {
//        if(mn[i] != -1 && mn[mn[i]] == i) {
//            unite(i, mn[i]);
//            b[i] = b[mn[i]] = d[i][mn[i]];
//        }
//    }
//
//    for(int i = 0; i < n; i++) {
//        cout << "b " << i << ' ' << b[i] << endl;
//    }

//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < n; j++) if(i != j) {
//            bool fl = (getp(i) == getp(j));
//            bool intr = (sz[getp(i)] > 1);
//            if(fl && d[i][j] != b[i] || !fl && d[i][j] <= b[i]) {
//                cout << 0 << endl;
//                return 0;
//            }
//        }
//    }

    vector<int> x;
    for(int i = 0; i < n; i++) {
        if(i == p[i])
            x.push_back(sz[i]);
    }
//
//    cout << "x : ";
//    for(int y : x)
//        cout << y << ' ';
//    cout << endl;

//    cout << "sagsf" << endl;

//    for(int i = 0; i < n; i++) {
//        cout << i << " : " << p[i] << ' ' << sz[i] << endl;
//    }

    dp[0][n] = 1;
    for(int i = 0; i < x.size(); i++) {
        for(int j = 0; j <= n; j++) {
            if(j >= 1)
                dp[i + 1][j - 1] = sum(dp[i + 1][j - 1], mul(dp[i][j], j));
            if(x[i] > 1 && j >= x[i])
                dp[i + 1][j - x[i]] = sum(dp[i + 1][j - x[i]], mul(dp[i][j], mul(C[j][x[i]], f[x[i]])));
        }
    }

    int ans = 0;
    for(int i = 0; i <= n; i++)
        ans = sum(ans, dp[x.size()][i]);

    cout << ans << endl;

//    for(int i : pos) {
//        cout << ans[i] << ' ' << i << endl;
//    }
//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();
}