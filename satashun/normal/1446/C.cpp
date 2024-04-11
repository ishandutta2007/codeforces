//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

template <class T>
V<T> make_vec(size_t a) {
    return V<T>(a);
}

template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return V<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define ALL(c) (c).begin(), (c).end()
#define SZ(x) ((int)(x).size())

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T>
void mkuni(vector<T>& v) {
    sort(ALL(v));
    v.erase(unique(ALL(v)), end(v));
}

template <class T>
vector<int> sort_by(const vector<T>& v) {
    vector<int> res(v.size());
    iota(res.begin(), res.end(), 0);
    sort(res.begin(), res.end(), [&](int i, int j) { return v[i] < v[j]; });
    return res;
}

template <class T, class U>
istream& operator>>(istream& is, pair<T, U>& p) {
    is >> p.first >> p.second;
    return is;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) {
        is >> x;
    }
    return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

template <class T>
void scan(vector<T>& v, T offset = T(0)) {
    for (auto& x : v) {
        cin >> x;
        x += offset;
    }
}

template <class T>
void print(T x, int suc = 1) {
    cout << x;
    if (suc == 1)
        cout << "\n";
    else if (suc == 2)
        cout << " ";
}

template <class T>
void print(const vector<T>& v, int suc = 1) {
    for (int i = 0; i < v.size(); ++i)
        print(v[i], i == int(v.size()) - 1 ? suc : 2);
}

struct prepare_io {
    prepare_io() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    }
} prep_io;

template <typename T, int MAX_LOG, typename D = int>
struct BinaryTrie {
   public:
    struct Node {
        Node* nxt[2];
        D sum;
        vector<int> accept;

        Node() : nxt{nullptr, nullptr}, sum(0) {}
    };

    Node* root;

    explicit BinaryTrie() : root(new Node()) {}
    explicit BinaryTrie(Node* root) : root(root) {}

    void add(const T& bit, int idx = -1, D delta = 1, T xor_val = 0) {
        root = add(root, bit, idx, MAX_LOG, delta, xor_val);
    }

    void erase(const T& bit, T xor_val = 0) { add(bit, -1, -1, xor_val); }

    Node* find(const T& bit, T xor_val = 0) {
        return find(root, bit, MAX_LOG, xor_val);
    }

    D count(const T& bit, T xor_val = 0) {
        auto node = find(bit, xor_val);
        return node ? node->sum : 0;
    }

    pair<T, Node*> min_element(T xor_val = 0) {
        assert(root->sum > 0);
        return kth_element(0, xor_val);
    }

    pair<T, Node*> max_element(T xor_val = 0) {
        assert(root->sum > 0);
        return kth_element(root->sum - 1, xor_val);
    }

    pair<T, Node*> kth_element(D k, T xor_val = 0) {  // 0-indexed
        assert(0 <= k && k < root->sum);
        return kth_element(root, k, MAX_LOG, xor_val);
    }

    D count_less(const T& bit, T xor_val = 0) {  // < bit
        return count_less(root, bit, MAX_LOG, xor_val);
    }

    int calc(Node* t) {
        int c0 = t->nxt[0] ? min(1, t->nxt[0]->sum) : 0;
        int c1 = t->nxt[1] ? min(1, t->nxt[1]->sum) : 0;
        // debug(t->sum, c0, c1);
        if (t->nxt[1]) c0 += calc(t->nxt[1]);
        if (t->nxt[0]) c1 += calc(t->nxt[0]);
        return max({1, c0, c1});
    }

   private:
    virtual Node* clone(Node* t) { return t; }

    Node* add(Node* t, T bit, int idx, int depth, D x, T xor_val,
              bool need = true) {
        if (need) t = clone(t);
        if (depth == -1) {
            t->sum += x;
            if (idx >= 0) t->accept.emplace_back(idx);
        } else {
            bool f = (xor_val >> depth) & 1;
            auto& to = t->nxt[f ^ ((bit >> depth) & 1)];
            if (!to) to = new Node(), need = false;
            to = add(to, bit, idx, depth - 1, x, xor_val, need);
            t->sum += x;
        }
        return t;
    }

    Node* find(Node* t, T bit, int depth, T xor_val) {
        if (depth == -1) {
            return t;
        } else {
            bool f = (xor_val >> depth) & 1;
            auto& to = t->nxt[f ^ ((bit >> depth) & 1)];
            return to ? find(to, bit, depth - 1, xor_val) : nullptr;
        }
    }

    pair<T, Node*> kth_element(Node* t, D k, int bit_index,
                               T xor_val) {  // 0-indexed
        if (bit_index == -1) {
            return {0, t};
        } else {
            bool f = (xor_val >> bit_index) & 1;
            if ((t->nxt[f] ? t->nxt[f]->sum : 0) <= k) {
                auto ret = kth_element(t->nxt[f ^ 1],
                                       k - (t->nxt[f] ? t->nxt[f]->sum : 0),
                                       bit_index - 1, xor_val);
                ret.first |= T(1) << bit_index;
                return ret;
            } else {
                return kth_element(t->nxt[f], k, bit_index - 1, xor_val);
            }
        }
    }

    D count_less(Node* t, const T& bit, int bit_index, T xor_val) {
        if (bit_index == -1) return 0;
        D ret = 0;
        bool f = (xor_val >> bit_index) & 1;
        if ((bit >> bit_index & 1) and t->nxt[f]) ret += t->nxt[f]->sum;
        if (t->nxt[f ^ (bit >> bit_index & 1)])
            ret += count_less(t->nxt[f ^ (bit >> bit_index & 1)], bit,
                              bit_index - 1, xor_val);
        return ret;
    }
};

void slv() {
    int n;
    cin >> n;
    V<int> a(n);
    cin >> a;
    BinaryTrie<int, 30, int> T;
    for (auto x : a) T.add(x);
    int mx = T.calc(T.root);
    debug(mx);
    print(n - mx);
}

int main() {
    int cases = 1;
    // cin >> cases;
    rep(i, cases) slv();

    return 0;
}