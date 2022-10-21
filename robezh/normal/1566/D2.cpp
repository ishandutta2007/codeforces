#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int K = (int)1e5 + 50, N = 305;

int n, m;

int a[K], b[K];
int res[N][N];

int count(int i, int l, int r) {
    int v = 0;
    rep(j, l, r + 1) v += (res[i][j] );
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        rep(i, 0, n * m) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n * m);
        map<int, int> fir, la;
        rep(i, 0, n * m) la[b[i]] = i;
        for (int i = n * m - 1; i >= 0; i--) fir[b[i]] = i;
        rep(i, 0, n) fill(res[i], res[i] + m, 0);
        int fres = 0;
        rep(i, 0, n * m) {
            int r1 = fir[a[i]], r2 = la[a[i]];
            if(r1 / m == r2 / m) {
                res[r2 / m][r2 % m]++;
            } else {
                res[r1 / m][m - 1]++;
            }
            fres += count(r1 / m, 0, r1 % m - 1);
            fir[a[i]]++;
        }
//        rep(i, 0, n) {
//            rep(j, 0, m) cout << res[i][j] << " ";
//            cout << endl;
//        }
        cout << fres << '\n';

    }

}