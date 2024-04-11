#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<pii, int> P;

const int N = (int)2e5 + 50, LOGN = 20;

int n, lim, a[N];
pii p[N];
int mm[N], st[LOGN][N];

int rmq(int l, int r){
    int k = mm[r - l + 1];
    return __gcd(st[k][l], st[k][r-(1<<k)+1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    mm[0]=-1;
    for(int i = 1; i < N; i++) mm[i]= (i & (i-1)) == 0 ? mm[i-1] + 1 : mm[i-1];

    while(T--) {
        cin >> n >> lim;
        rep(i, 0, n) cin >> a[i], p[i] = {a[i], i};
        for(int i = 0; i < n; i++){
            st[0][i] = a[i];
        }
        for(int lg = 1; lg < LOGN; lg++){
            for(int j = 0; j + (1 << lg) - 1 < n; j++){
                st[lg][j] = __gcd(st[lg-1][j], st[lg-1][j+(1<<(lg-1))]);
            }
        }
        sort(p, p + n);
        set<pii> S;
        rep(i, 0, n) S.insert({i, i});
        ll res = 0;
        rep(i, 0, n) {
            if(p[i].first > lim) continue;
            auto it = S.lower_bound({p[i].second, -1});
            while(it != S.begin()) {
                auto nit = it; nit--;
                if(rmq(nit->first, p[i].second) == p[i].first) {
                    res += p[i].first;
                    int l = nit->second, r = it->first;
                    S.erase(nit);
                    S.erase(it);
                    S.insert({r, l});
                    it = S.lower_bound({r, -1});
                } else {
                    break;
                }
            }
            while(true) {
                auto nit = it; nit++;
                if(nit == S.end()) break;
                if(rmq(p[i].second, nit->second) == p[i].first) {
                    res += p[i].first;
                    int l = it->second, r = nit->first;
                    S.erase(nit);
                    S.erase(it);
                    S.insert({r, l});
                    it = S.lower_bound({r, -1});
                } else {
                    break;
                }
            }
        }
//        cout << res << endl;
        res += 1LL * (sz(S) - 1) * lim;
        cout << res << '\n';
    }



}