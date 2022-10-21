#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef array<ll, 2> pii;
typedef vector<int> vi;
const ll INF = (ll)1e18;

ll getdif(ll l, ll r, int x) {
    if(l <= x && x <= r) return 0;
    return x < l ? 2 * (l - x) : 2 * (x - r);
}

ll solve(vector<pii> &ps, int val) {
     ll res = 0;
     res += abs(ps[0][0] - ps[2][0]) + abs(ps[1][0] - ps[3][0]);
     res += abs(ps[0][1] - ps[1][1]) + abs(ps[2][1] - ps[3][1]);
     res += getdif(min(ps[1][0], ps[3][0]) - max(ps[0][0], ps[2][0]),
                   max(ps[1][0], ps[3][0]) - min(ps[0][0], ps[2][0]),
                    val);
    res += getdif(min(ps[0][1], ps[1][1]) - max(ps[2][1], ps[3][1]),
                  max(ps[0][1], ps[1][1]) - min(ps[2][1], ps[3][1]),
                  val);
     return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        vector<pii> ps;
        rep(i, 0, 4) {
            int x, y; cin >> x >> y; ps.push_back({x, y});
        }
        sort(all(ps));
        vi xs = {0};
        rep(i, 0, 4) {
            rep(j, i + 1, 4) {
                xs.push_back(abs(ps[i][0] - ps[j][0]));
                xs.push_back(abs(ps[i][1] - ps[j][1]));
            }
        }
        ll res = INF;
        do {
            for(int x : xs) res = min(res, solve(ps, x));
        } while(next_permutation(all(ps)));
        cout << res << '\n';
    }

}