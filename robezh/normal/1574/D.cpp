#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)2e5 + 50;

map<vi, int> ban;

int n;
vi x[N];


ll getsum(vi &xs) {
    ll res = 0;
    rep(i, 0, n) res += x[i][xs[i]];
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) {
        int k;
        cin >> k;
        x[i].resize(k, 0);
        for(int &y : x[i]) cin >> y;
    }
    int q;
    cin >> q;
    while(q--) {
        vi xs(n, 0);
        rep(i, 0, n) cin >> xs[i], xs[i]--;
        ban[xs] = 1;
    }
    vi st(n);
    rep(i, 0, n) st[i] = sz(x[i]) - 1;
    if(!ban[st]) {
//        cout << getsum(st) << endl;
        rep(i, 0, n) cout << st[i] + 1 << " ";
        cout << endl;
        return 0;
    } else {
        ll mxres = -1;
        vi mxbuild;
        for(auto p : ban) {
            auto xs = p.first;
            rep(i, 0, n) {
                if(xs[i] == 0) continue;
                xs[i]--;
                if(!ban[xs]) {
                    ll csum = getsum(xs);
                    if(csum > mxres) {
                        mxres = csum;
                        mxbuild = xs;
                    }
//                    mxres = max(getsum(xs), mxres);
                }
                xs[i]++;
            }
        }
        rep(i, 0, n) cout << mxbuild[i] + 1 << " ";
        cout << endl;
    }



}