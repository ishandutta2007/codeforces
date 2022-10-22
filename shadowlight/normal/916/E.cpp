#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;
const ll LOGN = 30;

ll n;

struct TNode {
    ll L, R;
    TNode *left, *right;
    ll sum, val;
};

vector <ll> orda;

TNode *new_node(ll L, ll R) {
    return new TNode({L, R, nullptr, nullptr, 0, 0});
}

ll safe_sum(TNode *root) {
    return (root ? root->sum : 0);
}

void relax(TNode *root) {
    if (!root) {
        return;
    }
    root->sum = safe_sum(root->left) + safe_sum(root->right);
}

void add_val(TNode *root, ll val) {
    if (!root) {
        return;
    }
    root->sum += (root->R - root->L) * val;
    root->val += val;
}

void push(TNode *root) {
    if (!root) {
        return;
    }
    add_val(root->left, root->val);
    add_val(root->right, root->val);
    root->val = 0;
}

TNode *build_tree(ll L, ll R) {
    TNode *root = new_node(L, R);
    if (R - L == 1) {
        root->sum = orda[L];
    } else {
        ll M = (L + R) / 2;
        root->left = build_tree(L, M);
        root->right = build_tree(M, R);
        relax(root);
    }
    return root;
}

ll get_sum(TNode *root, ll L, ll R) {
    if (L >= root->R || root->L >= R) {
        return 0;
    }
    if (L <= root->L && root->R <= R) {
        return root->sum;
    }
    push(root);
    ll sum = get_sum(root->left, L, R) + get_sum(root->right, L, R);
    relax(root);
    return sum;
}

void add_otr(TNode *root, ll L, ll R, ll x) {
    if (root->L >= R || L >= root->R) {
        return;
    }
    if (L <= root->L && root->R <= R) {
        add_val(root, x);
        return;
    }
    push(root);
    add_otr(root->left, L, R, x);
    add_otr(root->right, L, R, x);
    relax(root);
}

vector <ll> a;
vector <vector <ll> > gr;
vector <ll> tin, tout;
vector <vector <ll> > binup;
vector <ll> height;
ll timer = 0;
vector <ll> order;
vector <ll> lp, rp;

void dfs(ll v, ll p, ll h) {
    tin[v] = timer++;
    binup[0][v] = p;
    height[v] = h;
    order.push_back(v);
    lp[v] = order.size() - 1;
    rp[v] = order.size() - 1;
    for (ll i = 1; i < LOGN; i++) {
        if (binup[i - 1][v] == -1) continue;
        binup[i][v] = binup[i - 1][binup[i - 1][v]];
    }
    for (ll u : gr[v]) {
        if (u == p) continue;
        dfs(u, v, h + 1);
        lp[v] = min(lp[v], lp[u]);
        rp[v] = max(rp[v], rp[u]);
    }
    tout[v] = timer++;
}

bool isP(ll p, ll v) {
    return tin[p] <= tin[v] && tout[p] >= tout[v];
}

ll up(ll v, ll h) {
    for (ll i = LOGN - 1; i >= 0; i--) {
        if ((1 << i) > h) continue;
        h -= (1 << i);
        v = binup[i][v];
    }
    return v;
}

ll lca(ll v, ll u) {
    if (height[v] > height[u]) {
        swap(v, u);
    }
    u = up(u, height[u] - height[v]);
    if (v == u) {
        return v;
    }
    for (ll i = LOGN - 1; i >= 0; i--) {
        if (binup[i][v] == binup[i][u]) continue;
        v = binup[i][v];
        u = binup[i][u];
    }
    return binup[0][v];
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll q;
    cin >> n >> q;
    a.resize(n);
    gr.resize(n);
    tin.resize(n, 0);
    lp.resize(n, 0);
    rp.resize(n, 0);
    height.resize(n, 0);
    tout.resize(n);
    binup.resize(LOGN, vector <ll> (n, -1));
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 1; i < n; i++) {
        ll v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    dfs(0, -1, 0);
    for (ll x : order) {
        orda.push_back(a[x]);
    }
    TNode *root = build_tree(0, n);
    ll r = 0;
    for (ll i = 0; i < q; i++) {
        ll tp;
        cin >> tp;
        if (tp == 1) {
            cin >> r;
            r--;
        } else if (tp == 2) {
            ll v, u, x;
            cin >> v >> u >> x;
            v--, u--;
            ll w = lca(v, u);
            ll w1 = lca(u, r);
            ll w2 = lca(v, r);
            if (height[w1] > height[w]) {
                w = w1;
            }
            if (height[w2] > height[w]) {
                w = w2;
            }
            //cout << w << "\n";
            if (!isP(w, r)) {
                add_otr(root, lp[w], rp[w] + 1, x);
            } else {
                add_otr(root, 0, n, x);
                ll d = height[r] - height[w] - 1;
                if (d != -1) {
                    v = up(r, d);
                    add_otr(root, lp[v], rp[v] + 1, -x);
                }
            }
        } else {
            ll v;
            cin >> v;
            v--;
            if (!isP(v, r)) {
                cout << get_sum(root, lp[v], rp[v] + 1) << "\n";
            } else {
                ll sum = get_sum(root, 0, n);
                ll d = height[r] - height[v] - 1;
                if (d != -1) {
                    v = up(r, d);
                    sum -= get_sum(root, lp[v], rp[v] + 1);
                }
                cout << sum << "\n";
            }
        }
        //cout << i << " " << t.get(0, n) << "\n";
    }
}