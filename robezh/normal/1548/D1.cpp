#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = 6005;

ll C(int n, int k) {
    ll res = 1;
    for (int i = n; i > n - k; i--) res *= i;
    rep(i, 1, k + 1) res *= i;
    return res;
}

int n, x[N], y[N];
int cnt[2][2];

int is_odd(int x1, int y1, int x2, int y2) {
    return !(x1 == x2 && y1 == y2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) {
        cin >> x[i] >> y[i];
        x[i] /= 2, y[i] /= 2;
    }
    ll res = 0;
    rep(i, 0, n) {
        rep(j, i + 1, n) {
            rep(b0, 0, 2) {
                rep(b1, 0, 2) {
                    int c = is_odd(x[i] % 2, y[i] % 2, b0, b1)
                            + is_odd(x[j] % 2, y[j] % 2, b0, b1)
                            + is_odd(x[j] % 2, y[j] % 2, x[i] % 2, y[i] % 2);
                    if(c % 2 == 0) {
                        res += cnt[b0][b1];
//                        cout << i << " " << j << " " <<  cnt[b0][b1] << ", " << res << endl;
                    }
                }
            }
        }
        cnt[x[i] % 2][y[i] % 2]++;
    }
    cout << res << '\n';

}