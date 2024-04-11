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

const int MAXN = 1e7;
const int ALP = 2, B = 31;

struct node {
    int cnt = 0;
    node * go[ALP];
    node() {}
} trie[MAXN];
using pnode = node *;
int ffr = 1;

void insert(int s) {
    pnode v = trie;
    for (int i = B - 1; i >= 0; --i) {
        v->cnt++;
        int bit = (s >> i) & 1;
        if (!v->go[bit])
            v->go[bit] = &trie[ffr++];
        v = v->go[bit];
    }
    v->cnt++;
}


int find(int s) {
    pnode v = trie;
    int ans = 0;
    for (int i = B - 1; i >= 0; --i) {
        int bit = (s >> i) & 1;
        // dbg(i, bit, s, ans, v->cnt);
        v->cnt--;
        if (v->go[bit] && v->go[bit]->cnt) {
            // dbg(bit);
            ans |= (bit) << i;
            pnode to = v->go[bit];
            v = to;
        } else if (v->go[bit ^ 1] && v->go[bit ^ 1]->cnt){
            // dbg(bit ^ 1);
            ans |= (bit ^ 1) << i;
            pnode to = v->go[bit ^ 1];
            v = to;
        } else assert(false);
    }
    v->cnt--;
    return ans;
}
int a[MAXN], p[MAXN];
int main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        insert(p[i]);
    }

    for (int i = 0; i < n; ++i) {
        cout << (a[i] ^ find(a[i])) << ' ';
    }

    cout << '\n';

    
    return 0;
}