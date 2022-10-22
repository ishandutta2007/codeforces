#include <bits/stdc++.h>
using namespace std;
//using namespace atcoder;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define Sort(v) sort(v.begin(), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define all(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define bit(n) (1LL<<(n))
#define debug(x) cout << #x << "=" << x << endl;
#define vdebug(v) { cout << #v << "=" << endl; REP(i_debug, v.size()){ cout << v[i_debug] << ","; } cout << endl; }
#define mdebug(m) { cout << #m << "=" << endl; REP(i_debug, m.size()){ REP(j_debug, m[i_debug].size()){ cout << m[i_debug][j_debug] << ","; } cout << endl;} }
#define pb push_back
#define fi first
#define se second
#define int long long
#define INF 1000000000000000000
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for (auto &x : v) is >> x; return is; }
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){ for(int i = 0; i < v.size(); i++) { cout << v[i]; if(i != v.size() - 1) cout << endl; }; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1, T2> p){ cout << '(' << p.first << ',' << p.second << ')'; return os; }
template<typename T> void Out(T x) { cout << x << endl; }
template<typename T1, typename T2> void chOut(bool f, T1 y, T2 n) { if(f) Out(y); else Out(n); }

using vec = vector<int>;
using mat = vector<vec>;
using Pii = pair<int, int>;
using v_bool = vector<bool>;
using v_Pii = vector<Pii>;

//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//char d[4] = {'D','R','U','L'};

const int mod = 1000000007;
//const int mod = 998244353;

using T = int;
T id = INF;
T F(T a, T b) { return min(a, b); }
struct CompressedSegmentTree
{

    int N = 0;
    vector<int> index;
    vector<T> dat;

    CompressedSegmentTree(){}

    void init(set<int> &index_set){
        index = vector<int>(index_set.begin(), index_set.end());
        if(index.size() > 0){
            N = 1;
            while((int)index.size() > N) N = N << 1;
            dat = vector<T>(2 * N - 1, id);
        }
    }

    T get(int a, int b, int k, int l, int r){
        if(r <= a || b <= l) return id;
        if(a <= l && r <= b) return dat[k];
        else{
            T vl = get(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = get(a, b, k * 2 + 2, (l + r) / 2, r);
            return F(vl, vr);
        }
    }

    T get(int a, int b) {
        int a0 = lower_bound(index.begin(), index.end(), a) - index.begin();
        int b0 = lower_bound(index.begin(), index.end(), b) - index.begin();
        return get(a0, b0, 0, 0, N);
    }

    void update(int i, T a){
        int k = lower_bound(index.begin(), index.end(), i) - index.begin();
        k += N - 1;
        dat[k] = a;
        while(k > 0){
            k = (k - 1) / 2;
            dat[k] = F(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    T val(int i){ 
        int k = lower_bound(index.begin(), index.end(), i) - index.begin();
        if(k < (int)index.size() && index[k] == i) return dat[k + N - 1];
        else return id;
    }
};

struct Compressed2DSegmentTree
{
    int N = 0;
    vector<int> index;
    vector<CompressedSegmentTree> seg;

    Compressed2DSegmentTree(){}

    void init(map<int, set<int>> &index_set_xy){
        for(auto q: index_set_xy) index.push_back(q.first);
        if(index.size() > 0){
            N = 1;
            while((int)index.size() > N) N = N << 1;
            seg.resize(2 * N - 1);
        }
        vector<set<int>> s(2 * N - 1);
        int k = N - 1;
        for(auto q: index_set_xy){
            s[k] = q.second;
            k++;
        }
        for(int i = 2 * N - 2; i >= 0; i--){
            if(i < N - 1){
                int i1 = 2 * i + 1, i2 = 2 * i + 2;
                if(s[i1].size() < s[i2].size()) swap(i1, i2);
                s[i].swap(s[i1]);
                for(int y: s[i2]) s[i].insert(y);
            }
            seg[i].init(s[i]);
        }
    }

    void update(int x, int y, T a){
        int ix = lower_bound(index.begin(), index.end(), x) - index.begin();
        ix += N - 1;
        seg[ix].update(y, a);
        while(ix > 0){
            ix = (ix - 1) / 2;
            seg[ix].update(y, F(seg[2 * ix + 1].val(y), seg[2 * ix + 2].val(y)));
        }
    }

    T get(int ixl, int ixr, int yl, int yr, int k, int l, int r){
        if(r <= ixl || ixr <= l) return id;
        if(ixl <= l && r <= ixr) return seg[k].get(yl, yr);
        else{
            T vl = get(ixl, ixr, yl, yr, k * 2 + 1, l, (l + r) / 2);
            T vr = get(ixl, ixr, yl, yr, k * 2 + 2, (l + r) / 2, r);
            return F(vl, vr);
        }
    }

    T get(int xl, int xr, int yl, int yr) {
        int ixl = lower_bound(index.begin(), index.end(), xl) - index.begin();
        int ixr = lower_bound(index.begin(), index.end(), xr) - index.begin();
        return get(ixl, ixr, yl, yr, 0, 0, N);
    }
};

int dfs(int vl, int vr, int N, Compressed2DSegmentTree &ST, vec &l, vec &r){
    if(vl >= vr) return 0;
    int i = ST.get(vl, N, 0, vr);
    if(i == INF) return 0;
    int ans = r[i] - l[i] + 1;
    ans += dfs(vl, l[i], N, ST, l, r);
    ans += dfs(r[i] + 1, vr, N, ST, l, r);
    return ans;
}

signed main(){

    int n, m; cin >> n >> m;
    vec l(m), r(m);
    map<int, set<int>> S;
    mat query(n);
    REP(i, m){
        cin >> l[i] >> r[i];
        l[i]--; r[i]--;
        S[l[i]].insert(r[i]);
        query[r[i] - l[i]].pb(i);
    }
    Compressed2DSegmentTree ST;
    ST.init(S);

    vec ans(n + 1);
    IFOR(i, 1, n + 1){
        for(int i: query[i - 1]) ST.update(l[i], r[i], min(i, ST.get(l[i], l[i] + 1, r[i], r[i] + 1)));
        ans[i] = dfs(0, n, n, ST, l, r);
    }

    FOR(i, 1, n + 1) cout << ans[i] << '\n';


    return 0;
}