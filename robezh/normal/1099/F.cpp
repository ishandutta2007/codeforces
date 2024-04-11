#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2
typedef long long ll;

typedef long long ll;
const int N = (int)1e5 + 500;
typedef pair<ll, int> P;

struct edge{int to, cost;};

int n;
ll T;
ll f[N];
ll num[N], t[N], x[N];
P y[N];
ll dp[N];
vector<edge> G[N];

struct segtree{
    ll dat[N * 4];

    void update(int pos, int x, int l, int r, ll val){
        int mid = (l + r) / 2;
        if(l == r) {
            dat[x] += val;
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid, val);
        else update(pos, rson(x), mid+1, r, val);

        dat[x] = dat[lson(x)] + dat[rson(x)];
    }

    ll query(int a, int b, int x = 0, int l = 0, int r = n-1) {
        if(r < a || b < l) return 0;

        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];

        ll LHS = query(a, b, lson(x), l, mid);
        ll RHS = query(a, b, rson(x), mid+1, r);

        return LHS + RHS;
    }

    pair<int, ll> search(int x, int l, int r, ll T){
        int mid = (l + r) / 2;
        if(l == r) return {l, T};
        if(dat[lson(x)] > T) return search(lson(x), l, mid, T);
        else return search(rson(x), mid + 1, r, T - dat[lson(x)]);
    }

    void add(int i, ll x) {
        update(i, 0, 0, n-1, x);
    }
}tree[3];

void dfs(int v, int p) {
    int idx = lower_bound(x, x + n, t[v]) - x;
    if(T <= 0) return ;
    tree[0].add(idx, num[v] * t[v]);
    tree[1].add(idx, num[v]);

    if(tree[0].dat[0] <= T) {
        f[v] = tree[1].query(0, n-1);
    }
    else {
        pair<int, ll> pr = tree[0].search(0, 0, n-1, T);
        int i = pr.first;
        f[v] = tree[1].query(0, i - 1) + pr.second / x[i];
    }

    for(auto e : G[v]) {
        if(e.to == p) continue;
        T -= 2 * e.cost;
        dfs(e.to, v);
        T += 2 * e.cost;
    }
    tree[0].add(idx, -num[v] * t[v]);
    tree[1].add(idx, -num[v]);
}

ll get(int v, int p) {
    dp[v] = f[v];
    ll mx1 = 0, mx2 = 0;
    for(auto e : G[v]) {
        if(e.to == p) continue;
        ll cur = get(e.to, v);
        if(cur > mx1) mx2 = mx1, mx1 = cur;
        else if(cur > mx2) mx2 = cur;
    }
    return dp[v] = max(f[v], p == -1 ? mx1 : mx2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> T;
    for(int i = 0; i < n; i++) cin >> num[i];
    for(int i = 0; i < n; i++){
        cin >> t[i]; x[i] = t[i];
        y[i].first = t[i]; y[i].second = i;
    }
    sort(x, x + n);
    sort(y, y + n);
    for(int i = 1; i < n; i++) {
        int a, len; cin >> a >> len; a--;
        G[a].push_back({i, len});
        G[i].push_back({a, len});
    }
    dfs(0, -1);
    cout << get(0, -1) << endl;

}