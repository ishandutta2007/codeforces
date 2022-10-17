#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto c=a; c!=b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE(cout << #V" = "; WATCHR(V.begin(), V.end()))

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef array<int, 3> worker;

template<typename T, typename U> struct seg_tree_lazy {
    int S, H;
 
    T zero;
    vector<T> value;
 
    U noop;
    vector<bool> dirty;
    vector<U> prop;
 
    seg_tree_lazy<T, U>(int _S, T _zero = T(), U _noop = U()) {
        zero = _zero, noop = _noop;
        for (S = 1, H = 1; S < _S; ) S *= 2, H++;
 
        value.resize(2*S, zero);
        dirty.resize(2*S, false);
        prop.resize(2*S, noop);
    }
 
    void set_leaves(vector<T> &leaves) {
        copy(leaves.begin(), leaves.end(), value.begin() + S);
 
        for (int i = S - 1; i > 0; i--)
            value[i] = value[2 * i] + value[2 * i + 1];
    }
 
    void apply(int i, U &update) {
        value[i] = update(value[i]);
        if(i < S) {
            prop[i] = prop[i] + update;
            dirty[i] = true;
        }
    }
 
    void rebuild(int i) {
        for (int l = i/2; l; l /= 2) {
            T combined = value[2*l] + value[2*l+1];
            value[l] = prop[l](combined);
        }
    }
 
    void propagate(int i) {
        for (int h = H; h > 0; h--) {
            int l = i >> h;
 
            if (dirty[l]) {
                apply(2*l, prop[l]);
                apply(2*l+1, prop[l]);
 
                prop[l] = noop;
                dirty[l] = false;
            }
        }
    }
 
    void upd(int i, int j, U update) {
        i += S, j += S;
        propagate(i), propagate(j);
 
        for (int l = i, r = j; l <= r; l /= 2, r /= 2) {
            if((l&1) == 1) apply(l++, update);
            if((r&1) == 0) apply(r--, update);
        }
 
        rebuild(i), rebuild(j);
    }
 
    T query(int i, int j){
        i += S, j += S;
        propagate(i), propagate(j);
 
        T res_left = zero, res_right = zero;
        for(; i <= j; i /= 2, j /= 2){
            if((i&1) == 1) res_left = res_left + value[i++];
            if((j&1) == 0) res_right = value[j--] + res_right;
        }
        return res_left + res_right;
    }
};

const ll INF = LLONG_MAX / 2;

vvi adj, fin;
vector<vector<worker>> wrk;
vi beg, stp, ord, inx;
vll f, g;

void preorder(int loc, int par) {
    beg[loc] = ord.size();

    for (auto w : wrk[loc]) {
        inx[w[0]] = ord.size();
        ord.push_back(w[0]);
    }

    for (int nbr : adj[loc])
        if (nbr != par)
            preorder(nbr, loc);

    stp[loc] = ord.size();
}

struct node {
    ll low;
    node(ll _val = INF) {
        low = min(INF, _val);
    }
    node operator+(const node &n) {
        return node(min(low, n.low));
    }
};

struct update {
    ll add;
    update(ll _add = 0) {
        add = min(INF, _add);
    }
    update operator+(const update &u) {
        return update(add + u.add);
    }
    node operator()(const node &n) {
        return node(n.low + add);
    }
};

// f: solve subtree, g: solve with an edge up
void solve(seg_tree_lazy<node, update> &st, int loc, int par) {
    f[loc] = 0;
    for (int nbr : adj[loc]) {
        if (nbr == par) continue;
        solve(st, nbr, loc);

        if (g[nbr] == INF) {
            cout << -1 << "\n";
            exit(0);
        }

        f[loc] += g[nbr];
    }

    for (auto w : wrk[loc]) {
        int i = inx[w[0]];
        st.value[st.S + i] = node(w[2] + f[loc]);
        st.rebuild(st.S + i);
        //ll cur = st.query(i, i).low;
        //st.upd(i, i, update(-cur + w[2] + f[loc]));
        fin[w[1]].push_back(i);
    }

    for (int nbr : adj[loc]) {
        if (nbr == par) continue;
        st.upd(beg[nbr], stp[nbr] - 1, update(f[loc] - g[nbr]));
    }

    for (int i : fin[loc])
        st.upd(i, i, update(INF));

    g[loc] = st.query(beg[loc], stp[loc]-1).low;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N, M;
    cin >> N >> M;

    adj.resize(N);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    wrk.resize(N);

    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        wrk[u-1].push_back({ i, v - 1, c });
    }

    beg.resize(N), stp.resize(N), inx.resize(M);
    preorder(0, 0);

    seg_tree_lazy<node, update> st(M);
    f.resize(N, INF), g.resize(N, INF), fin.resize(N);
    solve(st, 0, 0);

    if (f[0] >= INF) cout << -1 << "\n";
    else cout << f[0] << "\n";
    return 0;
}