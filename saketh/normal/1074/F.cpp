#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

template<typename T, typename U> struct seg_tree_lazy {
    int S, H;

    T zero;
    vector<T> value;

    U noop;
    vb dirty;
    vector<U> prop;

    seg_tree_lazy<T, U>(int _S, T _zero = T(), U _noop = U()) {
        zero = _zero, noop = _noop;
        for (S = 1, H = 1; S < _S; ) S *= 2, H++;

        value.resize(2*S, zero);
        dirty.resize(2*S, false);
        prop.resize(2*S, noop);
    }

    void set_leaves(vector<T> leaves) {
        copy(leaves.begin(), leaves.end(), value.begin() + S);

        for (int i = S - 1; i > 0; i--)
            value[i] = value[2 * i] + value[2 * i + 1];
    }

    void apply(int i, U &update) {
        value[i] = update(value[i]);
        if (i < S) {
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
            if ((l&1) == 1) apply(l++, update);
            if ((r&1) == 0) apply(r--, update);
        }

        rebuild(i), rebuild(j);
    }

    T query(int i, int j) {
        i += S, j += S;
        propagate(i), propagate(j);

        T res_left = zero, res_right = zero;
        for (; i <= j; i /= 2, j /= 2) {
            if ((i&1) == 1) res_left = res_left + value[i++];
            if ((j&1) == 0) res_right = value[j--] + res_right;
        }
        return res_left + res_right;
    }
};

struct T {
    int v, r;
    T(int _v = 0, int _r = 0) : v(_v), r(_r) {}
    T operator+(const T &o) {
        if (v == o.v) return T(v, r + o.r);
        if (r == 0) return o;
        if (o.r == 0) return *this;
        return (v > o.v) ? *this : o;
    }
};

struct U {
    int v;
    U(int _v = 0) : v(_v) {}
    U operator+(const U &o) {
        return U(v + o.v);
    }
    T operator()(const T &t) {
        return T(t.v + v, t.r);
    }
};

void go(vvi &adj, vi &enter, vi &leave, int &inx, int loc, int par) {
    enter[loc] = inx++;
    vi ch;
    for (int nbr : adj[loc]) {
        if (nbr != par) {
            go(adj, enter, leave, inx, nbr, loc);
            ch.push_back(nbr);
        }
    }
    adj[loc] = ch;
    leave[loc] = inx - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, Q;
    cin >> N >> Q;

    vvi adj(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vi enter(N), leave(N);
    int inx = 0;
    go(adj, enter, leave, inx, 0, 0);

    seg_tree_lazy<T, U> st(N);
    st.set_leaves(vector<T>(N, T(0, 1)));
    auto update = [&](int u, int v, int e) {
        if (enter[u] > enter[v]) swap(u, v);
        if (leave[u] >= enter[v]) {
            st.upd(0, N-1, e);
            int lo = 0, hi = adj[u].size();
            while (lo <= hi) {
                int mi = (lo + hi) / 2;
                int nbr = adj[u][mi];
                if (leave[nbr] < enter[v]) {
                    lo = mi + 1;
                } else if (enter[nbr] > enter[v]) {
                    hi = mi - 1;
                } else {
                    st.upd(enter[nbr], leave[nbr], -e);
                    break;
                }
            }
            st.upd(enter[v], leave[v], e);
        } else {
            st.upd(enter[u], leave[u], e);
            st.upd(enter[v], leave[v], e);
        }
    };

    set<pair<int, int>> added;
    for (int q = 0; q < Q; q++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        auto p = make_pair(--u, --v);
        if (added.count(p)) {
            update(u, v, -1);
            added.erase(p);
        } else {
            update(u, v, 1);
            added.insert(p);
        }
        auto r = st.query(0, N-1);
        cout << (r.v == added.size() ? r.r : 0) << "\n";
    }

    return 0;
}