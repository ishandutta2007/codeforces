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

int n;
vi G[N];
vi s;
int vis[N];
vi sma[N];

void solve(){
    cin >> n;
    rep(i, 0, n) G[i].clear();
    s.clear();
    rep(i, 0, n) {
        int k, x; cin >> k;
        while(k--) {
            cin >> x;
            G[i].push_back(x);
            s.push_back(x);
        }
    }
    sort(all(s));
    int S = int(sqrt(sz(s)) + 0.5) + 1;

    s.resize(unique(all(s)) - s.begin());
    rep(i, 0, sz(s)) sma[i].clear();
    rep(i, 0, n) {
        for(auto &x : G[i]) x = (int)(lower_bound(all(s), x) - s.begin());
        sort(all(G[i]));
    }


    fill(vis, vis + sz(s), 0);
    rep(i, 0, n) {
        if(sz(G[i]) >= S) {
            for(auto &x : G[i]) vis[x]++;
            rep(j, 0, n) {
                if(i == j || (sz(G[j]) >= S && i > j)) continue;
                int cnt = 0;
                for(auto &x : G[j]) cnt += vis[x];
                if(cnt >= 2) {
                    cout << i + 1 << " " << j + 1 << '\n';
                    return ;
                }
            }
            for(auto &x : G[i]) vis[x]--;
        } else {
            sma[G[i].back()].push_back(i);
        }
    }
    fill(vis, vis + sz(s), -1);
    for(int x = sz(s) - 1; x >= 0; x--) {
        for (int i : sma[x]) {
//            cout << i << " has " << s[x] << endl;
            G[i].pop_back();
            if (!G[i].empty()) sma[G[i].back()].push_back(i);
            for (auto &y : G[i]) {
                if (vis[y] != -1) {
                    cout << vis[y] + 1 << " " << i + 1 << '\n';
                    return;
                }
                vis[y] = i;
            }
        }
        for (int i : sma[x]) {
            for (auto &y : G[i]) vis[y] = -1;
        }
    }
    cout << "-1" << '\n';
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