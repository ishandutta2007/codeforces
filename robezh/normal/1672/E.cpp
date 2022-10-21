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
const int N = 2005;

const int INF = (int)1e9;

int ask(int w) {
    cout << "? " << w << endl;
    fflush(stdout);
    int h;
    cin >> h;
    if(h == 0) return INF;
    return h;
}

int main() {

    int n;
    cin >> n;
    int l = 0, r = N * N, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(ask(mid) == 1) r = mid;
        else l = mid;
    }
    int mxsum = r;
    int sum = r - (n - 1);
    int res = mxsum;

    rep(i, 2, n + 1) {
        int w = mxsum / i;
        if(ask(w) <= i) {
            res = min(res, w * i);
        }
    }
    cout << "! " << res << endl;
    fflush(stdout);



}