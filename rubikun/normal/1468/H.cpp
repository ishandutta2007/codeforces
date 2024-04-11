#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    ll N, K, M;
    cin >> N >> K >> M;
    vector<ll> a(N, 0);
    vector<ll> b(M);
    for(int i = 0; i < M; i++) {
        cin >> b[i];
        b[i]--;
        a[b[i]] = 1;
    }
    vector<vector<ll>> v;
    for(int i = 0; i < N; i++) {
        if(a[i] == 1) continue;
        if(v.empty() or v.back().size() == K / 2) v.push_back({});
        v.back().push_back(i);
    }
    /*
    for(auto tmp : v) {
        for(auto u : tmp) cerr << u << " ";
        cerr << endl;
    }
    */
    if(v.size() % 2 == 1) {
        cout << "NO" << endl;
        return;
    }
    if(v.back().size() != K / 2) {
        cout << "NO" << endl;
        return;
    }
    for(int i = 0; i < v.size() / 2; i++) {
        ll j = i + v.size() / 2;
        ll l = v[i].back();
        ll r = v[j][0];
        auto itr = lower_bound(b.begin(), b.end(), l);
        if(itr != b.end() and (*itr) <= r) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}