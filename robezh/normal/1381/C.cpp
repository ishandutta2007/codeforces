#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e5 + 50;

int n, x, y;
int b[N];
set<int> ocu[N];
int res[N];

int getnxt(int v) {
    if(ocu[v].empty()) return -1;
    int c = *ocu[v].begin();
    ocu[v].erase(ocu[v].begin());
    return c;
}

void solve() {
    cin >> n >> x >> y;
    rep(i, 0, n + 2) {
        ocu[i].clear();
    }
    int rem = n;
    priority_queue<pii> pque;
    map<int, int> mp;
    rep(i, 0, n) {
        cin >> b[i];
        mp[b[i]]++;
        ocu[b[i]].insert(i);
    }
    int mex = 1;
    for(auto &p : mp) {
        if(p.first == mex) mex++;
    }
    fill(res, res + n, mex);

    for(auto &p : mp) pque.push({p.second, p.first});
    while(x > 0) {
        pii p = pque.top(); pque.pop();
        res[getnxt(p.second)] = p.second;
        p.first--;
        if(p.first) pque.push(p);
        x--, y--;
        rem--;
    }

    int mxcnt = (pque.empty() ? 0 : pque.top().first);
    vi ct;
    int mxfreq = min(rem - mxcnt, mxcnt);
    while(!pque.empty()) {
        pii p = pque.top(); pque.pop();
        for(int i = 0; i < mxfreq && i < p.first; i++) ct.push_back(p.second);
    }
    if(sz(ct) < y) {
        cout << "NO\n";
        return ;
    }
    for(int i = 0; i < y; i++) {
        res[getnxt(ct[i])] = ct[(i + mxfreq) % sz(ct)];
    }

    cout << "YES\n";
    rep(i, 0, n) cout << res[i] << " ";
    cout << '\n';





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