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

const int N = (int)2e5 + 50;

int n, m, ka, kb;
vi a, b;
int cnt[N], vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> ka >> kb;
    a.resize(ka);
    b.resize(kb);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    if(ka >= m || kb >= n) {
        cout << "No\n";
        return 0;
    }
    while(sz(a) < m - 1) a.push_back(1);
    while(sz(b) < n - 1) b.push_back(n + 1);
    for (int &x : a) cnt[x]++;
    for (int &x : b) cnt[x]++;

    priority_queue<int, vi, greater<>> pque;
    rep(i, 1, n + m + 1) {
        if(cnt[i] == 0) {
            pque.push(i);
        }
    }
    vector<pii> res;
    int pa = 0, pb = 0;
    rep(it, 0, n + m - 2) {
        int v = pque.top(); pque.pop();
        if(v <= n) {
            assert(pb < sz(b));
            res.push_back({v, b[pb]});
            if(--cnt[b[pb]] == 0) {
                pque.push(b[pb]);
            }
            pb++;
        } else {
            assert(pa < sz(a));
            res.push_back({v, a[pa]});
            if(--cnt[a[pa]] == 0) {
                pque.push(a[pa]);
            }
            pa++;
        }
    }
    int u = pque.top(); pque.pop();
    int v = pque.top(); pque.pop();
    res.push_back({u, v});
    cout << "Yes\n";
    for (auto &p : res) cout << p.first << " " << p.second << '\n';
}