#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;
int rep[MAXN], a[MAXN], n;
ll p;

int find(int u) {
    return rep[u] ? rep[u] = find(rep[u]) : u;
}

void solve() {
    cin >> n >> p;
    map<int, vector<int>> poss;
    for(int i = 1; i <= n; i++) {
        rep[i] = 0;
        cin >> a[i];
        poss[a[i]].push_back(i);
    }
    ll ans = 0;
    for(auto &[c, vc] : poss) {
        if(c > p)
            break;
        for(auto &u : vc) {
            int rr = find(u);
            for(int i = u + 1; i <= n; i++) {
                if(a[i] % c)
                    break;
                int b = find(i);
                if(rr == b)
                    break;
                rep[b] = rr;
                ans += c;
            }
            for(int i = u - 1; i >= 1; i--) {
                if(a[i] % c)
                    break;
                int b = find(i);
                if(rr == b)
                    break;
                rep[b] = rr;
                ans += c;
            }
        }
    }
    for(int i = 1; i + 1 <= n; i++) {
        int r = find(i), s = find(i + 1);
        if(r != s) {
            rep[s] = r;
            ans += p;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();    
}