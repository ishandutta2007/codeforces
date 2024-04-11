#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll INF = (ll)1e18;

ll make_num(int f, int len, int d) {
    ll res = f;
    while(len--) {
        res *= 10;
        res += 9;
    }
    res = (res * 10 + d) ;
    return res;
}

ll sum_digit(ll x) {
    ll res = 0;
    while(x > 0) res += x % 10, x /= 10;
    return res;
}

ll getsum(ll x, int k) {
    ll res = 0;
    rep(i, 0, k + 1) res += sum_digit(x + i);
    return res;
}

ll res[155][10];
ll pw[18];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    rep(i, 0, 155) rep(j, 0, 10) res[i][j] = INF;
    pw[0] = 1;
    rep(i, 1, 18) pw[i] = pw[i-1] * 10;
    for(int f = 0; f <= 9; f++) {
        for(int d = 0; d <= 9; d++) {
            for(int k = 0; k <= 9; k++) {
                for(int len = 0; len <= 16; len++) {
                    for(int i = 0; i <= len; i++) {
                        ll curnum = make_num(f, len, d) - (i == 0 ? 0 : pw[i]);
//                    if(curnum < 0) {
//                        cout << f << ',' << len << "," << d << endl;
//                    }
                        ll sum = getsum(curnum, k);
                        if(sum < 155) res[sum][k] = min(res[sum][k], curnum);
                    }

                }
            }
        }
    }
    cin >> T;
    while(T--) {
        int n, k; cin >> n >> k;
        cout << (res[n][k] == INF ? -1 : res[n][k]) << '\n';
    }
}