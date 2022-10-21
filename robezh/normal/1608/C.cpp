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

const int N = (int)1e5 + 50, INF = (int)1e9 + 50;

int n, a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        vector<pii> ap, bp;
        rep(i, 0, n) {
            cin >> a[i];
            ap.push_back({a[i], i});
        }
        rep(i, 0, n) {
            cin >> b[i];
            bp.push_back({b[i], i});
        }
        sort(all(ap));
        sort(all(bp));
        vector<vi> G(n);
        rep(i, 1, n) {
            G[ap[i - 1].second].push_back(ap[i].second);
            G[bp[i - 1].second].push_back(bp[i].second);
        }
        vi vis(n, 0);
        queue<int> que;
        auto add = [&](int v) {
            if(!vis[v]) {
                vis[v] = 1;
                que.push(v);
            }
        };
        add(ap.back().second);
        add(bp.back().second);
        while(!que.empty()) {
            auto v = que.front(); que.pop();
            for (int nxt : G[v]) add(nxt);
        }
        rep(i, 0, n) cout << vis[i];
        cout << '\n';

    }


}