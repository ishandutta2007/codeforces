#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50;

int n, m;
vi S[N];
int bel[N];
int f[N];
int find(int x) {return f[x] == x ? x : f[x] = find(f[x]);}
int unite(int x, int y) {
    f[find(x)] = find(y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, n) {
        cin >> bel[i]; bel[i]--;
        S[bel[i]].push_back(i);
    }
    rep(i, 0, m) f[i] = i;
    int res = n - 1;
    rep(i, 0, n - 1) {
        if(bel[i + 1] == bel[i]) res--;
    }
    cout << res << '\n';

    rep(i, 0, m - 1) {
        int a, b; cin >> a >> b; a--; b--;
        int u = find(a), v = find(b);
        if(sz(S[u]) > sz(S[v])) swap(u, v);
        for(int x : S[u]) {
            if(x + 1 < n && bel[x + 1] == v) res--;
            if(x - 1 >= 0 && bel[x - 1] == v) res--;
            S[v].push_back(x);
        }
        for(int x : S[u]) bel[x] = v;
        S[u].clear();
        f[u] = v;
        cout << res << '\n';
    }


}