#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using matr = vector<vi>;

const int INF = 1e9 + 13;
const li INF64 = 4e18 + 13;
//const int M = 1e9 + 7;
//const int M = 998244353;
const int N = 2e5 + 13;
const int LOGN = 20;

int M;

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

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, n));
}

mt19937 rnd(45567);

int a[N];
int st[LOGN][N];
int max2[N];

int get(int l, int r) {
    int k = max2[r - l];
    return max(st[k][l], st[k][r - (1 << k)]);
}

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
        cin >> a[i];

    for(int i = 2; i < N; i++)
        max2[i] = max2[i / 2] + 1;

    for(int i = 0; i < m; i++)
        st[0][i] = a[i];

    for(int i = 1; i < LOGN; i++) {
        for(int j = 0; j + (1 << i) <= m; j++) {
            st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
        }
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int xs, ys, xt, yt, k;
        cin >> xs >> ys >> xt >> yt >> k;

        xs--;
        ys--;
        xt--;
        yt--;

        if((xs - xt) % k != 0 || (ys - yt) % k != 0) {
            cout << "NO\n";
            continue;
        }

        if(ys == yt) {
            cout << "YES\n";
            continue;
        }

        int mx = get(min(ys, yt), max(ys, yt) + 1);
        int res = xs + (mx - xs + k - 1) / k * k;

        cout << (res < n ? "YES\n" : "NO\n");
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}