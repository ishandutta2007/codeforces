#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

#define FAST_ALLOCATOR_MEMORY 150 * 1024 * 1024
#ifdef FAST_ALLOCATOR_MEMORY
int ptr = 0;
char memory[(int) FAST_ALLOCATOR_MEMORY];
 
inline void *operator new(size_t n) {
    char *res = memory + ptr;
    ptr += n;
    return (void *)  res; 
}  
  
inline void operator delete(void *) noexcept {}
inline void operator delete(void *, size_t) {}
#endif

int MOD;

int add(int a, int b) {
    a += b;
    if (a >= MOD) return a - MOD;
    return a;
}

int mul(int a, int b) {
    return (ll) a * b % MOD;
}

int gcd(int x, int y, int &k, int &l) {
    if (!y) {
        k = 1;
        l = 0;
        return x;
    }
    int g = gcd(y, x % y, l, k);
    l -= k * (x / y);
    return g;
}

int getInv(int x) {
    int k, l;
    gcd(x, MOD, k, l);
    k = k % MOD;
    if (k < 0) k += MOD;
    //assert(mul(k, x) == 1);
    return k;
}

int n;
vector<int> a;

const int C = 9;
const int N = 1e5 * 18;

void read() {
    cin >> n >> MOD;
    a.resize(n);
    for (auto &i : a) {
        cin >> i;
    }
}

vector<int> p;

int pows[C][N];

void initPrimes() {
    int x = MOD;
    for (int i = 2; i * i <= x; i++) {
        if (x % i) continue;
        p.push_back(i);
        while (x % i == 0) {
            x /= i;
        }
    }
    if (x > 1) {
        p.push_back(x);
    }
    for (int i = 0; i < (int)p.size(); i++) {
        pows[i][0] = 1;
        for (int j = 1; j < N; j++) {
            pows[i][j] = mul(pows[i][j - 1], p[i]);
        }
    }
}

struct Node{
    int sum;
    int mod;
    int fmod[C];
    Node() {
        sum = 0;
        mod = 1;
        fill(fmod, fmod + C, 0);
    }
    Node(int x) {
        sum = x;
        mod = 1;
        fill(fmod, fmod + C, 0);
        for (int i = 0; i < (int)p.size(); i++) {
            while (sum % p[i] == 0) {
                fmod[i]++;
                sum /= p[i];
            }
        }
    }
    void push(int myMod, int * myFmod) {
        mod = mul(mod, myMod);
        for (int i = 0; i < (int)p.size(); i++) {
            fmod[i] += myFmod[i];
        }
    }
    void Mul(int x) {
        for (int i = 0; i < (int)p.size(); i++) {
            while (x % p[i] == 0) {
                fmod[i]++;
                x /= p[i];
            }
        }
        mod = mul(mod, x);
    }
    void Div(int x) {
        for (int i = 0; i < (int)p.size(); i++) {
            while (x % p[i] == 0) {
                fmod[i]--;
                assert(fmod[i] >= 0);
                x /= p[i];
            }
        }
        mod = mul(mod, getInv(x));
    }
    int get() const {
        int ans = sum;
        for (int i = 0; i < (int)p.size(); i++) {
            ans = mul(ans, pows[i][fmod[i]]);
        }
        ans = mul(ans, mod);
        return ans;
    }
};

Node merge(const Node & a, const Node & b) {
    Node ans;
    ans.sum = add(a.get(), b.get());
    return ans;
}

struct SegmentTree{
    int n;
    vector<Node> tree;
    SegmentTree() {}
    void build(int v, int tl, int tr, const vector<int> & a) {
        if (tl >= tr) return;
        if (tl == tr - 1) {
            tree[v] = Node(a[tl]);
            return;
        }
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm, a);
        build(v * 2 + 1, tm, tr, a);
        tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }
    SegmentTree(const vector<int> & a) {
        n = a.size();
        tree.assign(n * 4, {});
        build(1, 0, n, a);
    }
    void push(int v) {
        tree[v * 2].push(tree[v].mod, tree[v].fmod);
        tree[v * 2 + 1].push(tree[v].mod, tree[v].fmod);
    }
    void segMul(int v, int tl, int tr, int l, int r, int x) {
        if (tl >= r || tr <= l) return;
        if (tl >= l && tr <= r) {
            tree[v].Mul(x);
            return;
        }
        push(v);
        int tm = (tl + tr) / 2;
        segMul(v * 2, tl, tm, l, r, x);
        segMul(v * 2 + 1, tm, tr, l, r, x);
        tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }
    void segMul(int l, int r, int x) {
        segMul(1, 0, n, l, r + 1, x);
    }
    void pointDiv(int v, int tl, int tr, int pos, int x) {
        if (tl >= pos + 1 || tr <= pos) return;
        if (tl == tr - 1) {
            tree[v].Div(x);
            return;
        }
        push(v);
        int tm = (tl + tr) / 2;
        pointDiv(v * 2, tl, tm, pos, x);
        pointDiv(v * 2 + 1, tm, tr, pos, x);
        tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }
    void pointDiv(int pos, int x) {
        pointDiv(1, 0, n, pos, x);
    }
    Node get(int v, int tl, int tr, int l, int r) {
        if (tl >= r || tr <= l) return Node();
        if (tl >= l && tr <= r) return tree[v];
        push(v);
        int tm = (tl + tr) / 2;
        Node ans = merge(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm, tr, l, r));
        tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);    
        return ans;
    } 
    int get(int l, int r) {
        auto ans = get(1, 0, n, l, r + 1);
        return ans.get();
    }
};

SegmentTree tree;

void build() {
    initPrimes();
    tree = SegmentTree(a);
}

void run() {
    build();
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            r--;
            tree.segMul(l, r, x);
        } else if (t == 2) {
            int pos, x;
            cin >> pos >> x;
            pos--;
            tree.pointDiv(pos, x);
        } else if (t == 3) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << tree.get(l, r) << "\n";
        } else {
            assert(false);
        }
    }
}

void write() {

}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
	read();
	run();
	write();
	return 0;
}