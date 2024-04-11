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
const int N = 5005;

int n;
struct P {
    int x, y, idx;
} p[N];

vector<P> res;

ll h_len(P p1, P p2) {
    return 1LL * (p1.x - p2.x) * (p1.x - p2.x) + 1LL * (p1.y - p2.y) * (p1.y - p2.y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) {
        cin >> p[i].x >> p[i].y;
        p[i].idx = i;
    }
    res.push_back(p[0]);
    res.push_back(p[1]);
    rep(i, 2, n) {
        vector<P> op;
        while(sz(res) >= 2) {
            P p2 = p[i];
            P p1 = res[sz(res) - 1];
            P p0 = res[sz(res) - 2];
            ll l01 = h_len(p0, p1), l02 = h_len(p0, p2), l12 = h_len(p1, p2);
            if(l02 - l01 >= l12) {
                op.push_back(p1);
                res.pop_back();
            } else {
                break;
            }
        }
        res.push_back(p[i]);
        reverse(all(op));
        res.insert(res.end(), all(op));
    }
    rep(i, 0, n) {
        cout << res[i].idx + 1 << " ";
    }
    cout << '\n';

}