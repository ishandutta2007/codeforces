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
const int N = (int)2e5 + 50, INF = (int)1e9;

int n, q, s, a[N], d;
set<pii> S;
int dis[N];
bool vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q >> s >> d; s--;
    rep(i, 0, n) {
        cin >> a[i];
    }


    priority_queue<pii, vector<pii>, greater<pii>> pque;
    rep(i, 0, n) S.insert({a[i], i});
    fill(dis, dis + n, INF);

    auto add = [&](int v, int d) {
        if(d < dis[v]) {
            dis[v] = d;
            pque.push({d, v});
        }
    };

    auto update = [&](int x, int k) {
        auto it = S.lower_bound({x - k, -1});
        while(it != S.end() && it->first <= x + k) {
            add(it->second, k);
            it = S.erase(it);
        }
        it = S.lower_bound({x + k, -1});
        if(it != S.end()) {
            add(it -> second, it->first - x);
        }
        if(it != S.begin()) {
            it--;
            add(it -> second, x - it->first);
        }
    };

    update(a[s] + d, 0);
    update(a[s] - d, 0);
    while(!pque.empty()) {
        auto p = pque.top(); pque.pop();
        int v = p.second, len = p.first;
        if(vis[v]) continue;
        vis[v] = true;
        auto it = S.lower_bound({a[v], -1});
        if(it != S.end() && it -> first == a[v]) S.erase(it);
        update(a[v] + d, len);
        update(a[v] - d, len);

        it = S.lower_bound({a[v], -1});
        if(it != S.end()) {
            add(it -> second, len + (it->first - a[v]));
        }
        if(it != S.begin()) {
            it--;
            add(it -> second, len + (a[v] - it->first));
        }
    }
//    rep(i, 0, n) cout << dis[i] << " ";
//    cout << endl;

    while(q--) {
        int i, k; cin >> i >> k; i--;
        cout << (i == s || dis[i] <= k ? "Yes" : "No") << '\n';
    }


}