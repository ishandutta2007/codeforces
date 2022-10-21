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
typedef pair<int, int> P;
const int N = (int)1e3 + 50;

int n, q;
int f[N];
int sz[N];
multiset<int> S;

int find(int x) {return f[x] == x ? x : f[x] = find(f[x]);}
bool unite(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return false;
    S.erase(S.find(sz[u]));
    S.erase(S.find(sz[v]));
    sz[v] += sz[u];
    S.insert(sz[v]);
    f[u] = v;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    iota(f, f + n, 0);
    fill(sz, sz + n, 1);
    rep(i, 0, n) S.insert(1);
    int rem = 0;
    while(q--) {
        int a, b; cin >> a >> b; a--, b--;
        rem += !unite(a, b);
        auto it = S.rbegin();
        int res = *S.rbegin() - 1;
        rep(i, 0, rem) {
            it++;
            res += *it;
        }
        cout << res << '\n';
    }
}