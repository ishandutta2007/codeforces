#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50;

struct Query {
    int k, idx;
};

vector<Query> qrs;
int n, q;

int a[N];
ll psum[N];

set<pii> S, nxtmerge;
multiset<int> lens;
int res[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    rep(i, 1, n + 1) {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }
    rep(i, 0, q) {
        int k; cin >> k;
        qrs.push_back({k, i});
    }
    sort(all(qrs), [](const Query &q1, const Query &q2) {
        return q1.k > q2.k;
    });


    rep(i, 1, n) {
        S.insert({i, i});
        nxtmerge.insert({a[i] - 1, i});
        lens.insert(1);
    }
    for(auto &qr : qrs) {
        while(!nxtmerge.empty() && nxtmerge.rbegin()->first >= qr.k) {
            auto it = S.lower_bound({nxtmerge.rbegin()->second, -1});
            nxtmerge.erase(--nxtmerge.end());
            pii p = *it;
            it = S.erase(it);
            lens.erase(lens.find(p.second - p.first + 1));
            while(it != S.end() && psum[p.second] - psum[p.first - 1] - 1LL * qr.k * (p.second - p.first + 1) > 0) {
                p.second = it->second;
                lens.erase(lens.find(it->second - it->first + 1));
                nxtmerge.erase({(psum[it->second] - psum[it->first - 1] - 1 ) / (it->second - it->first + 1), it->first});
                it = S.erase(it);
            }
            if(psum[p.second] - psum[p.first - 1] - 1LL * qr.k * (p.second - p.first + 1) <= 0) {
                int nxtk = (psum[p.second] - psum[p.first - 1] - 1) / (p.second - p.first + 1);
                nxtmerge.insert({nxtk, p.first});
                lens.insert(p.second - p.first + 1);
                S.insert(p);
            }
        }
        res[qr.idx] = (lens.empty() ? n : max(*lens.rbegin(), n - S.rbegin()->second)) - 1;
    }

    rep(i, 0, q) cout << res[i] << " ";




}