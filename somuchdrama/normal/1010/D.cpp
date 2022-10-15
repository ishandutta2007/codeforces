#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::pair;using std::set;using std::string;using std::vector;
using ll = long long;using uint = unsigned int;using pii = pair<int, int>;using pll = pair<ll, ll>;
#define ff first
#define ss second
#define pb emplace_back
template<typename T> void _dbg(const char* _s,T _h){cerr<<_s<<" = "<<_h <<"\n";}
template<typename T,typename... Ts>void _dbg(const char* _s,T _h,Ts... _t){int _b = 0;while(((_b+=*_s=='(')-=*_s==')')!=0||*_s!=',')cerr<<*_s++;cerr<<" = "<<_h<<",";_dbg(_s+1,_t...);}
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 
#endif

struct init { init() {cin.tie(0);std::iostream::sync_with_stdio(0);cout << std::fixed << std::setprecision(10);cerr << std::fixed << std::setprecision(5);}~init() {
        #ifdef LOCAL
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
        #endif
}} init;

const int MAXN = 1e6+1;
int t[MAXN], a[MAXN], b[MAXN]; // in -- -2, not -- -1, x -- 0, and -- 1, xor -- 2, or -- 3
bool val[MAXN];
int q[MAXN];
vector<int> vs[MAXN*2];
int x[MAXN], y[MAXN]; //x--1, y--0
int c = 0;
void merge(int& v1, int& v2) {
    if (vs[v1].size() < vs[v2].size())
        swap(v1, v2);
    copy(vs[v2].begin(), vs[v2].end(), std::back_inserter(vs[v1]));
    vs[v2].clear();
}
void dfs(int v) {
    x[v] = c++;
    y[v] = c++;
    if (t[v] == -2) {
        val[v] = a[v];
        if (a[v])
            vs[y[v]].pb(v); // change 1 to 0
        else
            vs[x[v]].pb(v);
    } else if (t[v] == -1) {
        dfs(a[v]);
        val[v] = !val[a[v]];
        x[v] = y[a[v]];
        y[v] = x[a[v]];
    } else if (t[v] == 0) {
        dfs(a[v]);
        val[v] = val[a[v]];
        x[v] = x[a[v]];
        y[v] = y[a[v]];
    } else if (t[v] == 1) {
        dfs(a[v]);
        dfs(b[v]);
        val[v] = val[a[v]] & val[b[v]];
        if (val[b[v]]) {
            merge(x[v], x[a[v]]);
        } else {
            merge(y[v], x[a[v]]);
        }
        if (val[a[v]]) {
            merge(x[v], x[b[v]]);
        } else {
            merge(y[v], x[b[v]]);
        }
        merge(y[v], y[a[v]]);
        merge(y[v], y[b[v]]);
    } else if (t[v] == 2) {
        dfs(a[v]);
        dfs(b[v]);
        val[v] = val[a[v]] ^ val[b[v]];
        if (val[b[v]]) {
            merge(x[v], y[a[v]]);
            merge(y[v], x[a[v]]);            
        } else {
            merge(x[v], x[a[v]]);                        
            merge(y[v], y[a[v]]);
        }
        if (val[a[v]]) {
            merge(x[v], y[b[v]]);
            merge(y[v], x[b[v]]);            
        } else {
            merge(x[v], x[b[v]]);                        
            merge(y[v], y[b[v]]);
        }
    } else if (t[v] == 3) {
        dfs(a[v]);
        dfs(b[v]);
        val[v] = val[a[v]] | val[b[v]];
        merge(x[v], x[a[v]]);
        merge(x[v], x[b[v]]);
        if (val[b[v]]) {
            merge(x[v], y[a[v]]);
        } else {
            merge(y[v], y[a[v]]);
        }
        if (val[a[v]]) {
            merge(x[v], y[b[v]]);
        } else {
            merge(y[v], y[b[v]]);
        }
    }
    // dbg(v, "x");
    // for (int i : x[v])
    //     dbg(i);
    // dbg(v, "y");
    // for (int i : y[v])
    //     dbg(i);
}
int yo[MAXN];
int32_t main() {

    int n;
    cin >> n;
    int ptr = 0;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s >> a[i];
        if (s != "IN" && s != "NOT") 
            cin >> b[i];
        if (s == "IN") {
            t[i] = -2;
            yo[i] = ptr++;
        }
        if (s == "NOT") t[i] = -1;
        if (s == "AND") t[i] = 1;
        if (s == "XOR") t[i] = 2;
        if (s == "OR") t[i] = 3;
    }

    int l = 0, r = 0;
    q[r++] = 1;
    while (l < r) {
        int v = q[l++];
        if (t[v] == -1) {
            int cv = v;
            vector<int> path;
            while (t[cv] == -1) {
                path.pb(cv);
                cv = a[cv];
            }
            t[v] = -((int)path.size() % 2);
            a[v] = cv;
            dbg(v, t[v], a[v]);
        } else if (t[v] > 0) {
            q[r++] = a[v];
            q[r++] = b[v];
        }
    }

    dfs(1);

    string ans(ptr, '0');
    for (int i : vs[x[1]]) {
        ans[yo[i]] = '1';
    }

    cout << ans << '\n';

    return 0;
}