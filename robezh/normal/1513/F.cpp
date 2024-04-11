#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50, INF = (int)1e9;

int n;
int a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    ll maxsave = 0;
    rep(swapped, 0, 2) {
        rep(negated, 0, 2) {
            if(swapped) rep(i, 0, n) swap(a[i], b[i]);
            if(negated) rep(i, 0, n) a[i] = -a[i], b[i] = -b[i];

            vector<pii> ab, ba;
            rep(i, 0, n) {
                if(a[i] >= b[i]) ba.push_back({a[i], b[i]});
                else ab.push_back({a[i], b[i]});
            }
            set<pii> S;
            sort(all(ba), [](const pii &p1, const pii &p2) {
                return p1.second < p2.second;
            });
            int pos = 0;
            int mx = -INF;
            sort(all(ab));
            for(auto &p : ab) {
                while(pos < sz(ba) && ba[pos].second <= p.first) {
                    mx = max(ba[pos].first, mx);
                    pos++;
                }
                maxsave = max(maxsave, 2LL * (min(mx, p.second) - p.first));
            }


            if(negated) rep(i, 0, n) a[i] = -a[i], b[i] = -b[i];
            if(swapped) rep(i, 0, n) swap(a[i], b[i]);
        }
    }
    ll rsum = 0;
    rep(i, 0, n) rsum += abs(a[i] - b[i]);
    cout << rsum - maxsave << '\n';
}