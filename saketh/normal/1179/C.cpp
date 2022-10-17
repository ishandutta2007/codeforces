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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

/*
 * Supports range sum queries on a mutable array of Ts.
 * Requires that T's + operator is associative and that T() is the
 * additive identity: T() + t = t = t + T() for any T t.
 */
template<typename T> struct seg_tree {
    int S;
    vector<T> table;

    seg_tree<T>(int _S) : S(_S) {
        table.resize(2 * S);
    }

    seg_tree<T>(auto begin, auto end) : seg_tree(distance(begin, end)) {
        copy(begin, end, table.begin() + S);
        for (int i = S - 1; i > 0; i--)
            table[i] = table[2 * i] + table[2 * i + 1];
    }

    // Replaces the element at index i with v
    void replace(int i, T v) {
        table[i += S] = v;
        for (i /= 2; i > 0; i /= 2) {
            table[i] = table[2 * i] + table[2 * i + 1];
        }
    }

    // Returns the value of the element at index i
    const T& operator()(int i) const { return table[S + i]; }

    // Returns the sum of the elements at indices in [i, j)
    T operator()(int i, int j) const {
        T left{}, right{};
        for (i += S, j += S; i < j; i /= 2, j /= 2) {
            if (i&1) left = left + table[i++];
            if (j&1) right = table[--j] + right;
        }
        return left + right;
    }
};

template<typename T> struct full_seg_tree : seg_tree<T> {
    // Internal size is rounded up so that all layers are full
    full_seg_tree<T>(int _S) : seg_tree<T>(1 << (32 - __builtin_clz(_S - 1))) {}

    /*
     * Returns the first i in [0, S] such that comp(this(0, i))
     * evaluates to true. Returns -1 if no such i exists.
     * Requires that comp(this(0, i)) is non-decreasing in i.
     */
    int lower_bound(const auto& comp) {
        if (!comp(this->table[1])) return -1;
        if (comp(T{})) return 0;

        int loc = 1;
        for (T cur{}; loc < this->S; ) {
            T mid = cur + this->table[2 * loc];
            if (comp(mid)) {
                loc = 2 * loc;
            } else {
                cur = mid;
                loc = 2 * loc + 1;
            }
        }
        return loc - this->S + 1;
    }
};

struct node {
    int stud, dish;
    node(int stud = 0, int dish = 0) : stud(stud), dish(dish) {
    }
    node operator+(const node& o) const {
        int comb = min(stud, o.dish);
        return { stud - comb + o.stud, dish + o.dish - comb };
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    const int MAXV = 1e6 + 1;
    vi dishes(MAXV), students(MAXV);

    full_seg_tree<node> st(MAXV);

    int N, M;
    cin >> N >> M;

    vi a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        dishes[a[i]]++;
    }

    vi b(M);
    for (int i = 0; i < M; i++) {
        cin >> b[i];
        students[b[i]]++;
    }

    auto write = [&](int v) {
        st.replace(MAXV - 1 - v, node(max(students[v] - dishes[v], 0), max(dishes[v] - students[v], 0)));
    };

    for (int v = 1; v < MAXV; v++) {
        write(v);
    }

    int Q;
    cin >> Q;
    for (int q = 0, t, i, x; q < Q; q++) {
        cin >> t >> i >> x; --i;
        if (t == 1) {
            dishes[a[i]]--;
            write(a[i]);
            dishes[a[i] = x]++;
            write(a[i]);
        } else {
            students[b[i]]--;
            write(b[i]);
            students[b[i] = x]++;
            write(b[i]);
        }

        auto search = [](const node& n) { return n.dish > 0; };
        int get = st.lower_bound(search);
        cout << (get == -1 ? -1 : MAXV - get) << "\n";
    }

    return 0;
}