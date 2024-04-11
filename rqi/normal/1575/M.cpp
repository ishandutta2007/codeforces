#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;

using pi = pair<int, int>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vpi = V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define ins insert
#define lb lower_bound

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for(int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for(auto& a: x)

const int MOD = 1e9+7;
const ll BIG = 1e18;
const db PI = acos((db)-1);
mt19937 rng(0);

tcT> bool ckmin(T& a, const T& b){
    return b < a ? a = b, 1 : 0;
}

tcT> bool ckmax(T& a, const T& b){
    return a < b ? a = b, 1 : 0;
}

tcT, class U> T fstTrue(T lo, T hi, U f){
    ++hi; assert(lo <= hi);
    while(lo < hi){
        T mid = lo+(hi-lo)/2;
        f(mid) ? hi = mid : lo = mid+1;
    }
    return lo;
}

/**
 * Description: Add lines of the form $ax+b$, 
     * query maximum $y$-coordinate for any $x$.
 * Time: O(\log N)
 * Source: KACTL
   * https://github.com/kth-competitive-programming/kactl/commit/165807e28402c9be906f6e6a09452431787bb70d?diff=unified
 * Verification: https://judge.yosupo.jp/problem/line_add_get_min
 */

using T = ll; const T INF = LLONG_MAX; // a/b rounded down
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); }

bool _Q = 0;
struct Line {
    T a, b; mutable T lst;
    /// friend str ts(const Line& L) { return ts(vl{L.a,L.b,L.lst}); }
    T eval(T x) const { return a*x+b; }
    bool operator<(const Line&o)const{return _Q?lst<o.lst:a<o.a;}
    T last_gre(const Line& o) const { assert(a <= o.a); 
        // greatest x s.t. a*x+b >= o.a*x+o.b
        return lst=(a==o.a?(b>=o.b?INF:-INF):fdiv(b-o.b,o.a-a));}
};

struct LineContainer: multiset<Line> {
    bool isect(iterator it) { auto n_it = next(it);
        if (n_it == end()) return it->lst = INF, 0;
        return it->last_gre(*n_it) >= n_it->lst; }
    void add(T a, T b) { // remove lines after
        auto it = ins({a,b,0}); while (isect(it)) erase(next(it));
        if (it == begin()) return;
        if (isect(--it)) erase(next(it)), isect(it);
        while (it != begin()) { // remove lines before
            --it; if (it->lst < next(it)->lst) break;
            erase(next(it)); isect(it); }
    }
    T qmax(T x) { assert(!empty()); 
        _Q = 1; T res = lb({0,0,x})->eval(x); _Q = 0;
        return res; }
};

/**
 * Description: LineContainer assuming both slopes and queries monotonic.
 * Time: O(1)
 * Source: Own
 * Verification: http://acm.hdu.edu.cn/diy/contest_showproblem.php?cid=36005&pid=1009
     * http://www.usaco.org/index.php?page=viewproblem2&cpid=626
 */

struct LCdeque : deque<Line> { 
    void addBack(Line L) { // assume nonempty
        while (1) {
            auto a = bk; pop_back(); a.lst = a.last_gre(L);
            if (size() && bk.lst >= a.lst) continue;
            pb(a); break;
        }
        L.lst = INF; pb(L);
    }
    void addFront(Line L) {
        while (1) {
            if (!size()) { L.lst = INF; break; }
            if ((L.lst = L.last_gre(ft)) >= ft.lst) pop_front();
            else break;
        }
        push_front(L);
    }
    void add(T a, T b) { // line goes to one end of deque
        a = -a; b = -b;
        if (!size() || a <= ft.a) addFront({a,b,0});
        else assert(a >= bk.a), addBack({a,b,0});
    }
    int ord = 1; // 1 = x's come in increasing order, -1 = decreasing order
    T query(T x) { 
        assert(ord);
        if (ord == 1) { 
            while (ft.lst < x) pop_front();
            return -ft.eval(x);
        } else {
            while(size()>1&&prev(prev(end()))->lst>=x)pop_back();
            return -bk.eval(x);
        }
    }
};

const int mx = 2005;
struct Eff{

int n, m;
bool a[mx][mx];
ll S_res[mx][mx];
int right_most[mx]; //rightmost x for each y

void genSRes(){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            S_res[i][j] = BIG;
        }
    }

    for(int j = 0; j <= m; j++){
        right_most[j] = -1;
    }

    for(int i = 0; i <= n; i++){
        // cout << "i: " << i << "\n";
        for(int j = 0; j <= m; j++){
            if(a[i][j]){
                right_most[j] = i;
            }
        }

        //(x_pole-i)^2+(y_pole-j)^2 -> (i^2+j^2)+(y_pole^2+x_pole^2-2x_pole*i) + (-2*y_pole)*(j)
        LCdeque lc;
        for(int j = 0; j <= m; j++){ 
            if(right_most[j] == -1) continue;
            ll x_pole = right_most[j];
            ll y_pole = j;
            ll slop = y_pole*ll(-2);
            ll b = y_pole*y_pole+x_pole*x_pole-ll(2)*x_pole*ll(i);

            // cout << "slop, b: " << slop << " " << b << "\n";
            lc.add(slop, b);
        }

        if(sz(lc)){
            for(int j = 0; j <= m; j++){
                ll val = lc.query(j)+ll(i)*ll(i)+ll(j)*ll(j);
                // cout << i << " " << j << " " << val << "\n";
                ckmin(S_res[i][j], val);
            }
        }
        
    }



}

ll S[mx][mx];

void solve(){
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        string s; cin >> s;
        for(int j = 0; j <= m; j++){
            a[i][j] = bool(s[j]-'0');
        }
    }
    genSRes();
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            S[i][j] = S_res[i][j];
            // cout << "i, j, S[i][j]: " << i << " " << j << " " << S[i][j] << "\n";
        }
    }

    for(int i = 0; i <= n/2; i++){
        for(int j = 0; j <= m; j++){
            swap(a[i][j], a[n-i][j]);
        }
    }

    genSRes();
    for(int i = 0; i <= n/2; i++){
        for(int j = 0; j <= m; j++){
            swap(S_res[i][j], S_res[n-i][j]);
        }
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            ckmin(S[i][j], S_res[i][j]);
            // cout << "i, j, S_res[i][j]: " << i << " " << j << " " << S_res[i][j] << "\n";
        }
    }

    ll ans = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            ans+=S[i][j];
        }
    }
    cout << ans << "\n";
}

};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    Eff e; e.solve();
}