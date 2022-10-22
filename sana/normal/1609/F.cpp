#if 1
#pragma GCC target("popcnt")
#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

#include <bits/stdc++.h>
using namespace std;

#if 0
    #include <bits/extc++.h>
    using namespace __gnu_pbds;

    template<class T>
    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;
#endif

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

typedef string str;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());

#define ts to_string
str ts(char c) { return str(1,c); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
template<class A> str ts(complex<A> c) { stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) { str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) { str res = ""; F0R(i,SZ) res += char('0'+b[i]); return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { bool fst = 1; str res = "{"; for (const auto& x: v) {if (!fst) res += ", ";	fst = 0; res += ts(x);}	res += "}"; return res;}
template<class A, class B> str ts(pair<A,B> p) {return "("+ts(p.first)+", "+ts(p.second)+")"; }
 
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }
void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {cerr << ts(h); if (sizeof...(t)) cerr << ", ";	DBG(t...); }

int myrand(int l, int r) { return uniform_int_distribution(l, r)(rng); }

#endif

vector<ll> a;
int n;

struct Tree {
	typedef int T;
	static constexpr T unit = -1;
	T f(T aa, T bb) { 
        if (aa == -1) return bb;
        if (bb == -1) return aa;
        return a[aa] > a[bb] ? aa : bb; 
    }
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

Tree rmq;
vi l_norm, r_norm;
int r[1000001][20];
int l[1000001][20];
int tot_r[1000001];
int tot_l[1000001];

vector< pii > gogo;

long long go(int aa, int bb) {
    gogo.pop_back();
    if (aa > bb) return 0;
    
    int mx = rmq.query(aa, bb+1);
    long long ans = 0;

    int curL = mx;
    int curR = mx;
    long long left_ans = 0;
    long long right_ans = 0;
    int tgt_popcnt = __builtin_popcountll(a[mx]);

    while (curL >= aa && curR <= bb) {
        curL = l_norm[curL];
        curR = r_norm[curR];
    }

    if (curL < aa) {
        curL = mx;
        while (curL >= aa) {
            dbg(aa,bb,curL, curR, left_ans, right_ans);

            #define l fsddfsdfsdf
            #define curR sdffdsfsdf

            long long Lfactor = curL - max(aa-1, l_norm[curL]);

            if (__builtin_popcountll(a[curL]) == tgt_popcnt) {
                left_ans += (min(bb+1, r_norm[curL]) - mx) * Lfactor;
            }

            dbg(left_ans);

            int curI = mx;
            for (int k = 19; k >= 0; k--) {
                if (r[curI][k] < n && a[r[curI][k]] >= a[curL]) {
                    curI = r[curI][k];
                }
            }
            int leftBorder = r[curI][0];
            
            if (leftBorder <= bb) {
                left_ans += tot_r[leftBorder] * Lfactor;

                curI = leftBorder;
                for (int k = 19; k >= 0; k--) {
                    if (r[curI][k] <= bb) {
                        curI = r[curI][k];
                    }
                }

                left_ans += Lfactor * (min(bb+1, r_norm[curI]) - curI);
                left_ans -= Lfactor * tot_r[curI];
            }

            curL = l_norm[curL];
        }

        #undef l
        #undef curR
    }
    else {
        curR = mx;

        #define curL fsfsdfsdf
        #define r fasifjsaodifjd
        
        while (curR <= bb) {
            long long Rfactor = min(bb+1, r_norm[curR]) - curR;

            if (__builtin_popcountll(a[curR]) == tgt_popcnt) {
                right_ans += (mx - max(aa-1, l_norm[curR])) * Rfactor;
            }

            int curI = mx;
            for (int k = 19; k >= 0; k--) {
                if (l[curI][k] >= 0 && a[l[curI][k]] >= a[curR]) {
                    curI = l[curI][k];
                }
            }
            int rightBorder = l[curI][0];
            
            if (rightBorder >= aa) {
                right_ans += Rfactor * tot_l[rightBorder];

                curI = rightBorder;
                for (int k = 19; k >= 0; k--) {
                    if (l[curI][k] >= aa) {
                        curI = l[curI][k];
                    }
                }

                right_ans += Rfactor * (curI - max(aa-1, l_norm[curI]));
                right_ans -= Rfactor * tot_l[curI];
            }
                // dbg(ans);
            curR = r_norm[curR];
        }

        #undef curL
        #undef r
    }

    dbg(aa,bb,curL, curR, left_ans, right_ans);

    gogo.emplace_back(aa,mx-1);
    gogo.emplace_back(mx+1,bb);
    return curL < aa ? left_ans : right_ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;

    a = vector<ll>(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    rmq = Tree(n);
    for (int i = 0; i < n; i++) rmq.update(i, i);

    l_norm = vi(n);
    r_norm = vi(n);
    for (int i = 0; i < n; i++) {
        l_norm[i] = i-1;
        while (l_norm[i] > -1 && a[l_norm[i]] >= a[i]) l_norm[i] = l_norm[l_norm[i]];
    }
    for (int i = n-1; i >= 0; i--) {
        r_norm[i] = i+1;
        while (r_norm[i] < n && a[r_norm[i]] >= a[i]) r_norm[i] = r_norm[r_norm[i]];
    }

    vi la(70, -1);
    vi p(n);
    for (int i = 0; i < n; i++) {
        p[i] = la[__builtin_popcountll(a[i])];
        while (p[i] > -1 && (r_norm[p[i]] <= i || a[i]==a[p[i]]) ) p[i] = p[p[i]];
        la[__builtin_popcountll(a[i])] = i;
    }
    for (int i = 0; i < n; i++) {
        l[i][0] = p[i];
        tot_l[i] = (i - l_norm[i]) + (p[i] > -1 ? tot_l[ p[i] ] : 0);
    }

    fill(all(la), n);
    for (int i = n-1; i >= 0; i--) {
        p[i] = la[__builtin_popcountll(a[i])];
        while (p[i] < n && (l_norm[p[i]] >= i || a[i]==a[p[i]]) ) p[i] = p[p[i]];
        la[__builtin_popcountll(a[i])] = i;
    }
    for (int i = n-1; i >= 0; i--) {
        r[i][0] = p[i];
        tot_r[i] = (r_norm[i] - i) + (p[i] < n ? tot_r[ p[i] ] : 0);
    }

    for (int k = 1; k < 20; k++) {
        for (int i = 0; i < n; i++) {
            if (l[i][k-1] == -1) l[i][k] = l[i][k-1];
            else l[i][k] = l[ l[i][k-1] ][k-1];

            if (r[i][k-1] == n) r[i][k] = r[i][k-1];
            else r[i][k] = r[ r[i][k-1] ][k-1];
        }
    }

    long long ans = 0;
    gogo.emplace_back(0, n-1);
    while (!gogo.empty()) {
        ans += go(gogo.back().first, gogo.back().second);
    }
    cout << ans << endl;

    return 0;
}