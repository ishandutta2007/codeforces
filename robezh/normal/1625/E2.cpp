#include <bits/stdc++.h>
#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;
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

const int N = (int)3e5 + 50;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;

int n, q;
string str;
int pos[N];
stack<int> S;
int cnt = 0;
Tree<int> G[N];
int par[N];
int in[N], out[N], tcnt = 0;

ll bit[N];

void add(int x, ll val) {
    for(int i = x; i < n; i |= i + 1) bit[i] += val;
}

ll get(int x) {
    ll res = 0;
    for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
    return res;
}


void dfs(int v, int p) {
    in[v] = tcnt++;
    for (int nxt : G[v]) {
        if(nxt != p) dfs(nxt, v);
    }
    out[v] = tcnt - 1;
}

ll C2(ll x) {
    return x * (x - 1) / 2;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    cin >> str;
    fill(pos, pos + n, -1);
    int rt = cnt++;
    par[rt] = -1;
    rep(i, 0, n) {
        if (str[i] == '(') {
            pos[i] = cnt++;
            int p = S.empty() ? rt : S.top();
            G[p].insert(pos[i]);
            par[pos[i]] = p;
            S.push(pos[i]);
        } else {
            if (S.empty()) continue;
            pos[i] = S.top();
            S.pop();
        }
    }

    dfs(rt, -1);
    rep(i, 0, cnt) add(in[i], 1 + C2(sz(G[i])));

    rep(qi, 0, q) {
        int tp, l, r; cin >> tp >> l >> r; l--, r--;
        int v = pos[l];
        if(tp == 1) {
            add(in[v], -1);
            add(in[par[v]], -C2(sz(G[par[v]])));
            G[par[v]].erase(v);
            add(in[par[v]], C2(sz(G[par[v]])));

        } else {
            ll sum = get(out[pos[r]]) - get(in[v] - 1);
            ll nei = (int)G[par[v]].order_of_key(pos[r] + 1) - (int)G[par[v]].order_of_key(v);
            cout << sum + (nei * (nei - 1)) / 2 << '\n';
        }
    }

}