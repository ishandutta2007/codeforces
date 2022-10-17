#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const int MOD = 1e9 + 7;
int sum(int a, int b) { return (a + b) % MOD; }
int diff(int a, int b) { return sum(a, MOD - b); }
int prod(int a, int b) { return a * 1ll * b % MOD; }

template<typename T> struct BIT {
    int S;
    vector<T> v;

    BIT<T>(int _S) {
        S = _S;
        v.resize(S+1);
    }
    
    void update(int i, T k) {
        for(i++; i<=S; i+=i&-i)
            v[i] = v[i] + k;
    }

    T read(int i) {
        T sum = 0;
        for(i++; i; i-=i&-i)
            sum = sum + v[i];
        return sum;
    }

    T read(int l, int r) {
        return read(r) - read(l-1);
    }
};

template<typename T> struct seg_tree {
    int S;

    T zero;
    vector<T> value;

    seg_tree<T>(int _S, T _zero = T()) {
        S = _S, zero = _zero;
        value.resize(2*S+1, zero);
    }

    void set_leaves(vector<T> &leaves) {
        copy(leaves.begin(), leaves.end(), value.begin() + S);

        for (int i = S - 1; i > 0; i--) 
            value[i] = value[2 * i] + value[2 * i + 1];
    }

    void upd(int i, T v) {
        i += S;
        value[i] = v;
        while(i>1){
            i/=2;
            value[i] = value[2*i] + value[2*i+1];
        }
    }

    T query(int i, int j) {
        T res_left = zero, res_right = zero;
        for(i += S, j += S; i <= j; i /= 2, j /= 2){
            if((i&1) == 1) res_left = res_left + value[i++];
            if((j&1) == 0) res_right = value[j--] + res_right;
        }
        return res_left + res_right;
    }
};

struct node {
    // ways[i][j] = number of ways to pick team members [i, j) here
    vector<int> ways;

    // can always just not pick
    void init() {
        ways[4 * 0 + 0] = 1;
        ways[4 * 1 + 1] = 1;
        ways[4 * 2 + 2] = 1;
        ways[4 * 3 + 3] = 1;
    }

    // default constructor, for a disabled player... no picks here
    node(bool fill = true) {
        ways.resize(16, 0);
        if (fill) init();
    }

    // constructor for enabled player... 
    node(int before, int after) {
        ways.resize(16, 0);
        init();

        ways[4 * 0 + 1] = before;
        ways[4 * 1 + 2] = 1;
        ways[4 * 2 + 3] = after;
    }

    // addition operator
    node operator+(const node &o) const {
        node res(false);
        for (int i = 0; i < 4; i++) {
            for (int j = i; j < 4; j++) {
                for (int k = j; k < 4; k++) {
                    res.ways[4 * i + k] = sum(res.ways[4 * i + k],
                        prod(ways[4 * i + j], o.ways[4 * j + k]));
                }
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    scanf("%d", &N);

    vi vals(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &vals[i]);
    }

    vi comp = vals;
    sort(all(comp));
    comp.erase(unique(all(comp)), comp.end());

    int U = comp.size();

    for (int i = 0; i < N; i++) {
        auto it = lower_bound(all(comp), vals[i]);
        vals[i] = it - comp.begin();
    }

    vi first(N), last(N);
    BIT<int> before(U), after(U);

    for (int i = 0; i < N; i++) {
        first[i] = before.read(vals[i]);
        before.update(vals[i], 1);
    }

    for (int i = N - 1; i >= 0; i--) {
        last[i] = after.read(vals[i]);
        after.update(vals[i], 1);
    }

    WATCHC(first);
    WATCHC(last);

    vvi locs(U);
    vi inx(N);

    for (int i = 0; i < N; i++) {
        inx[i] = locs[vals[i]].size();
        locs[vals[i]].push_back(i);
    }

    vector<seg_tree<node>> trees;

    int total = 0;

    for (int u = 0; u < U; u++) {
        vector<node> leaves;
        WATCHC(locs[u]);
        for (int l : locs[u]) {
            leaves.push_back(node(first[l], last[l]));
        }

        trees.push_back(seg_tree<node>(leaves.size()));
        trees.back().set_leaves(leaves);

        int ways = trees.back().query(0, leaves.size()).ways[4 * 0 + 3];
        WATCH(ways);
        total = sum(total, ways);
    }

    int M;
    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        int type, who;
        scanf("%d %d", &type, &who);

        who--;

        int t = vals[who];
        total = diff(total, trees[t].query(0, locs[t].size()).ways[4 * 0 + 3]);

        WATCH(t);
        WATCH(locs[t].size());

        if (type == 1) {
            // disable
            trees[t].upd(inx[who], node());
        } else {
            // enable
            node put = node(first[who], last[who]);
            trees[t].upd(inx[who], put);
        }

        total = sum(total, trees[t].query(0, locs[t].size()).ways[4 * 0 + 3]);
        printf("%d\n", total);
    }

    return 0;
}