#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)2e5 + 50;

int n;
vi G[N];
int in[N];

void solve() {
    set<int> cur;
    int rs = 0, cnt = 0;
    rep(i, 0, n) if(in[i] == 0) {
        cur.insert(i);
        cnt++;
    }
    while(!cur.empty()) {
        rs++;
        set<int> nxt;
        auto it = cur.begin();
        while(it != cur.end()) {
            int v = *it;
            for (int u : G[v]) {
                in[u]--;
                if(in[u] == 0) {
                    if(u > v) cur.insert(u);
                    else nxt.insert(u);
                    cnt++;
                }
            }
            it++;
        }
        cur = nxt;
    }
    cout << (cnt == n ? rs : -1) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) G[i].clear();
        fill(all(in), 0);
        rep(i, 0, n) {
            int k; cin >> k;
            while(k--) {
                int v; cin >> v; v--;
                G[v].push_back(i);
                in[i]++;
            }
        }
        solve();
    }

}