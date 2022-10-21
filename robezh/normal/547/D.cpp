#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)4e5 + 50;

int n, w, b;
int x[N], y[N];
vi xs, ys;
map<pii, int> mp;
set<int> G[N];
char res[N];
stack<int> St;
int col;

void dfs(int v, int p){
    while(G[v].size()){
        int nxt = *G[v].begin();
        G[nxt].erase(G[nxt].find(v));
        G[v].erase(G[v].begin());
        dfs(nxt, v);
    }
    col = !col;
    if(p != -1 && v != w + b && p != w + b) {
//        cout << p << " to " << v << endl;

//        cout << mp[{min(v, p), max(v, p)}] << endl;
        res[mp[{min(v, p), max(v, p)}]] = (col ? 'b' : 'r');
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) {
        cin >> x[i] >> y[i];
        xs.push_back(x[i]);
        ys.push_back(y[i]);
    }
    sort(all(xs));
    xs.resize(unique(all(xs)) - xs.begin());
    w = sz(xs);
    sort(all(ys));
    ys.resize(unique(all(ys)) - ys.begin());
    b = sz(ys);

    rep(i, 0, n) {
        x[i] = lower_bound(all(xs), x[i]) - xs.begin();
        y[i] = int(lower_bound(all(ys), y[i]) - ys.begin()) + w;
//        cout << x[i] << ", " << y[i] << endl;
        mp[{x[i], y[i]}] = i;
        G[x[i]].insert(y[i]);
        G[y[i]].insert(x[i]);
    }

    rep(i, 0, w + b) {
        if(sz(G[i]) % 2 == 1) {
            G[i].insert(w + b);
            G[w + b].insert(i);
        }
    }
    for(int i = w + b; i >= 0; i--){
        if(sz(G[i])) dfs(i, -1);
    }
    rep(i, 0, n) cout << res[i];
    cout << '\n';






}