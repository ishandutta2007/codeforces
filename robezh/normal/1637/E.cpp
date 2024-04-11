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

const int N = (int)3e5 + 50;

int n, m;
int a[N];
map<int, vi> G;
int cnt[N];
vector<pii> S[N];
int bad[N];

void solve() {
    cin >> n >> m;


    fill(cnt, cnt + n + 1, 0);
    rep(i, 0, n + 1) S[i].clear();

    vi vs;
    rep(i, 0, n) {
        cin >> a[i];
        vs.push_back(a[i]);
    }
    sort(all(vs));
    vs.resize(unique(all(vs)) - vs.begin());
    rep(i, 0, n) {
        a[i] = lower_bound(all(vs), a[i]) - vs.begin();
        cnt[a[i]]++;
    }


    G.clear();
    rep(i, 0, m) {
        int x, y; cin >> x >> y;
        x = lower_bound(all(vs), x) - vs.begin();
        y = lower_bound(all(vs), y) - vs.begin();
        G[x].push_back(y);
        G[y].push_back(x);
    }
    vi freq;
    rep(i, 0, n + 1) {
        if(cnt[i]) {
            S[cnt[i]].push_back({vs[i], i});
            freq.push_back(cnt[i]);
        }
    }
    sort(all(freq));
    freq.resize(unique(all(freq)) - freq.begin());
    for (int f : freq) sort(all(S[f]));

    ll res = 0;
    rep(i, 0, sz(freq)) {
        rep(idx, 0, sz(S[freq[i]])){
            auto &e = S[freq[i]][idx];
            for (int nxt : G[e.second]) bad[nxt] = 1;
            for (int pt = idx - 1; pt >= 0; pt--) {
                if(!bad[S[freq[i]][pt].second]) {
                    res = max(res, 1LL * (freq[i] + freq[i]) * (e.first + S[freq[i]][pt].first));
                    break;
                }
            }
            rep(j, i + 1, sz(freq)) {
                int pt = sz(S[freq[j]]) - 1;
                while(pt >= 0 && bad[S[freq[j]][pt].second]) pt--;
                if(pt >= 0) res = max(res, 1LL * (freq[i] + freq[j]) * (e.first + S[freq[j]][pt].first));
            }
            for (int nxt : G[e.second]) bad[nxt] = 0;
        }
    }
    cout << res << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }

}