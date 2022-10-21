#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50;

int n, k, m;
bool vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        cin >> n >> k >> m;
        k = (k - 1) / 2;
        fill(vis, vis + n, false);
        rep(i, 0, m) {
            int x; cin >> x; x--; vis[x] = true;
        }
        vector<pii> ps;
        int s = 0;
        rep(i, 0, n) {
            if(vis[i]) continue;
            s++;
            if(ps.empty() || ps.back().second + 1 != i) ps.push_back({1, i});
            else ps.back().first++, ps.back().second++;
        }
        if(s % (2 * k) != 0) {
            cout << "NO\n";
            continue;
        }
        bool good = false;
        int sf = 0;
        for(auto &p : ps) {
            sf += p.first;
            good |= sf >= k && s - sf >= k;
        }
        cout << (good ? "YES" : "NO") << "\n";

//        if(s % (2 * k) == 0 && s - ps[0].first >= k && s - ps.back().first >= k) cout << "YES\n";
//        else cout << "NO\n";
    }


}