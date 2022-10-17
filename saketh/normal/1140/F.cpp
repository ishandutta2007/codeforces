#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

template<typename T1, typename T2>
ostream& operator << (ostream& o, const pair<T1, T2>& p) {
    return o << "(" << p.first << ", " << p.second << ")";
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct persistent_union_find {
    struct node {
        int par, rank, size, xc, yc;
        node(int id = 0) : par(id), rank(0), size(1), xc(0), yc(0) {}
        void operator +=(const node& o) {
            if (rank == o.rank) rank++;
            size += o.size;
            xc += o.xc;
            yc += o.yc;
        }

        ll contrib() { return ll(xc) * yc; };
    };
    ll total = 0;

    int N, ops;
    vector<node> dsu;
    vector<tuple<int, node, int, int>> history;

    persistent_union_find(int _N) : N(_N), ops(0) {
        for (int i = 0; i < N; i++)
            dsu.push_back(node(i));
    }

    int opcount() const { return ops; }
    int components() const { return N - sz(history); }

    int rep(int i) const {
        while (i != dsu[i].par)
            i = dsu[i].par;
        return i;
    }

    bool unio(int a, int b) {
        ops++;
        a = rep(a), b = rep(b);
        if(a == b) return false;

        if (dsu[a].rank < dsu[b].rank)
            swap(a, b);

        node av = dsu[a];
        total -= dsu[a].contrib();
        dsu[a] += dsu[b];
        total += dsu[a].contrib();
        dsu[b].par = a;
        total -= dsu[b].contrib();

        history.emplace_back(ops, av, a, b);

        return true;
    }

    void rewind(int opc) {
        for (; !history.empty(); history.pop_back()) {
            const auto &[op, av, a, b] = history.back();
            if (op <= opc) break;
            total -= dsu[a].contrib();
            dsu[a] = av;
            total += dsu[a].contrib();
            dsu[b].par = b;
            total += dsu[b].contrib();
        }
        ops = opc;
    }
};

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct sp64_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = splitmix64(((uint64_t) new char | 1)
            * chrono::steady_clock::now().time_since_epoch().count());
        return splitmix64(x ^ FIXED_RANDOM);
    }
};
template<class K> struct sp64_pair_hash {
    size_t operator()(const pair<K, K>& x) const {
        static_assert(sizeof(K) <= 4);
        static sp64_hash sp64;
        return sp64(((uint64_t) x.first << 32) ^ x.second);
    }
};

/*
 * Accepts a sequence of operations inserting and deleting
 * elements of type T in a data structure of type D, and
 * a function "eval" on type D computing a result of type V.
 *
 * Computes and returns the results obtained when applying
 * the given operations sequentially.
 *
 * Requires D to expose a function to undo the most recently
 * performed insertions. Does not require D to support deletion
 * of arbitrary elements. Breaks amortized complexity.
 */
template<typename D, typename T, typename V, typename H = hash<T>>
vector<V> query_tree(D& ds, const vector<pair<bool, T>>& ops,
        const auto& apply, const auto& eval) {
    vi match(sz(ops), sz(ops));
    unordered_map<T, int, H> inserted;
    for (int op = 0; op < sz(ops); op++) {
        const auto &[ins, t] = ops[op];
        if (ins) inserted[t] = op;
        else {
            int inx = inserted[t];
            match[op] = inx;
            match[inx] = op;
            inserted.erase(t);
        }
    }

    vector<V> results(sz(ops) + 1);
    results[0] = eval(ds);

    auto dfs = [&](auto& self, int l, int r) -> void {
        if (r - l == 1) {
            if (match[l] > l) apply(ds, ops[l].second);
            results[r] = eval(ds);
            if (match[l] > l) ds.rewind(ds.opcount() - 1);
            return;
        }

        const int mid = (l + r) / 2;
        const int before = ds.opcount();

        if (l < mid) {
            for (int i = mid; i < r; i++)
                if (match[i] < l) apply(ds, ops[i].second);
            self(self, l, mid);
            ds.rewind(before);
        }

        if (mid < r) {
            for (int i = l; i < mid; i++)
                if (match[i] >= r) apply(ds, ops[i].second);
            self(self, mid, r);
            ds.rewind(before);
        }
    };
    dfs(dfs, 0, sz(ops));

    return results;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q;
    cin >> Q;

    set<pair<int, int>> seen;
    vector<pair<bool, pair<int, int>>> ops(Q);

    for (int i = 0; i < Q; i++) {
        cin >> ops[i].second.first >> ops[i].second.second;
        if (seen.count(ops[i].second)) {
            ops[i].first = false;
            seen.erase(ops[i].second);
        } else {
            ops[i].first = true;
            seen.insert(ops[i].second);
        }
    }

    const int MAXV = 3e5;
    persistent_union_find uf(2 * MAXV);
    for (int i = 0; i < 2 * MAXV; i++) {
        uf.dsu[i].xc = i < MAXV;
        uf.dsu[i].yc = i >= MAXV;
    }

    vll res = query_tree<persistent_union_find, pair<int, int>, ll, sp64_pair_hash<int>>(uf, ops,
            [](auto& uf, auto& op) { uf.unio(op.first - 1, op.second - 1 + MAXV); },
            [](auto& uf) { return uf.total; });

    for (int i = 1; i < sz(res); i++) {
        if (i > 1) cout << " ";
        cout << res[i];
    }
    cout << endl;

    return 0;
}