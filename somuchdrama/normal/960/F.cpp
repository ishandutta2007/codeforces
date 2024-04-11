//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>

using std::cerr;
using std::cin;
using std::cout;

using std::abs;
using std::min;
using std::max;
using std::swap;

using std::map;
using std::pair;
using std::set;
using std::string;
using std::vector;

using ll = long long;
using uint = unsigned int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define ff first
#define ss second
#define pb emplace_back
template<typename T> 
void _dbg(const char* _s, T _h) {
    cerr << _s << " = " << _h <<"\n"; 
}
template<typename T, typename... Ts>
void _dbg(const char* _s, T _h, Ts... _t) {
    int _b = 0;
    while (((_b += *_s == '(') -= *_s == ')') != 0 || *_s != ',')
        cerr << *_s++; 
    cerr << " = " << _h << ","; 
    _dbg(_s+1, _t...);
}
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 
#endif

struct init {
    init() {
        cin.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(5);
        #ifdef LOCAL
        srand(300); 
        #else
        using namespace std::chrono;
        srand(duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count()); 
        #endif
    }
    ~init() {
        #ifdef LOCAL
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
        #endif
    }
} init;



const int MAXN = 1e5 + 15;

struct node {
    int x, y, v, mx;
    node * left = nullptr, * right = nullptr;
    node() {}
    node(int _x, int _v) : x(_x), y(rand()), v(_v) {}
} nodes[MAXN + MAXN];
int ffr = 0;
using pnode = node*;

void print(pnode v, int dd = 0) {
    if (!v) return;
    print(v->left, dd+1);
    for (int i = 0; i < dd*4;++i)cerr<<' ';
    dbg(v->x, v->mx);
    print(v->right,dd+1);
}
int getmx(pnode v) {
    return v ? v->mx : 0;
}

void update(pnode v) {
    if (!v) return;
    v->mx = max({getmx(v->left), getmx(v->right), v->v});
}

pnode merge(pnode left, pnode right) {
    if (!left) return right;
    if (!right) return left;
    if (left->y > right->y) {
        left->right = merge(left->right, right);
        update(left);
        return left;
    } else {
        right->left = merge(left, right->left);
        update(right);
        return right;
    }
}

pair<pnode, pnode> split(pnode tree, int x) {
    if (!tree) return {tree, tree};
    if (tree->x > x) {
        auto tmp = split(tree->left, x);
        tree->left = tmp.ss;
        update(tree);
        return {tmp.ff, tree};
    } else {
        auto tmp = split(tree->right, x);
        tree->right = tmp.ff;
        update(tree);
        return {tree, tmp.ss};
    }
}

pnode insert(pnode tree, int x, int mx) {
    pnode xptr = &(nodes[ffr++] = node(x, mx));
    if (!tree) return xptr;
    auto tmp1  = split(tree, x);
    auto tmp2  = split(tmp1.ff, x - 1);
    update(xptr);
    return merge(merge(tmp2.ff, xptr), tmp1.ss);
}

pair<pnode, int> get(pnode tree, int l, int r) { 
    auto tmp1  = split(tree, r);
    auto tmp2  = split(tmp1.ff, l - 1);
    // print(tmp2.ss);
    int result = getmx(tmp2.ss);
    return {merge(merge(tmp2.ff, tmp2.ss), tmp1.ss), result};
}

pnode roots[MAXN];

int main() {

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        roots[i] = insert(roots[i], -1, 0);
    }

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;

        {
            auto p = get(roots[a], -100, c - 1);
            roots[a] = p.ff;
            int cur = p.ss;
            roots[b] = insert(roots[b], c, cur + 1);
        }
        // {
        //     auto p = get(roots[b], -100, c - 1);
        //     roots[b] = p.ff;
        //     int cur = p.ss;
        //     roots[a] = insert(roots[a], c, cur + 1);
        // }

    }


    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, getmx(roots[i]));
    }

    cout << ans << '\n';

    return 0;
}