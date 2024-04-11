#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)5e5 + 50;

int n, m;
vi G[N];
pii p[N];
int res[N];

int find_mex(vi &vs) {
//    for(int v : vs) cout << v << " ";
//    cout << endl;
    for(int i = 0; i < sz(vs); i++) {
        if(vs[i] != i + 1) return i + 1;
    }
    if(vs.empty()) return 1;
    return vs.back() + 1;
}

int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, m) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 0; i < n; i++) {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p, p + n);
    for(int i = 0; i < n; i++) {
        int v = p[i].second;
        vi vs;
        for(int nxt : G[v]) {
            if(res[nxt]) vs.push_back(res[nxt]);
        }
        sort(vs.begin(), vs.end());
        vs.resize((unique(all(vs)) - vs.begin()));
        int expect = find_mex(vs);
        if(expect != p[i].first) {
            return cout << -1 << endl, 0;
        }
        res[v] = p[i].first;
    }
    for(int i = 0; i < n; i++) cout << p[i].second + 1 << " ";


}