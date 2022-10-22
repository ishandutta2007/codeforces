#include <bits/stdc++.h>
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using gpp_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename L> using gpp_map = tree<T, L, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using gpp_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;*/
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
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)
#define bit(n) (1LL<<(n))
#define bit_exist(x, n) ((x >> n) & 1)
#define debug(x) cout << #x << "=" << x << endl;
#define vdebug(v) cout << #v << "=" << endl; REP(i_debug, v.size()){ cout << v[i_debug] << ","; } cout << endl;
#define mdebug(m) cout << #m << "=" << endl; REP(i_debug, m.size()){ REP(j_debug, m[i_debug].size()){ cout << m[i_debug][j_debug] << ","; } cout << endl;}
#define pb push_back
#define f first
#define s second
#define int long long
#define INF 1000000000000000000
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for (auto &x : v) is >> x; return is; }
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){ for(int i = 0; i < v.size(); i++) { cout << v[i]; if(i != v.size() - 1) cout << endl; }; return os; }
template<typename T> void Out(T x) { cout << x << endl; }
template<typename T1, typename T2> void Ans(bool f, T1 y, T2 n) { if(f) Out(y); else Out(n); }

using vec = vector<int>;
using mat = vector<vec>;
using Pii = pair<int, int>;
using PiP = pair<int, Pii>;
using PPi = pair<Pii, int>;
using bools = vector<bool>;
using pairs = vector<Pii>;

//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//char d[4] = {'D','R','U','L'};

const int mod = 1000000007;
//const int mod = 998244353;
//#define Add(x, y) x = (x + (y)) % mod
//#define Mult(x, y) x = (x * (y)) % mod

struct SegmentTree
{
    using T = Pii;

    int N;
    vector<T> dat;

    T id = Pii(INF, INF);
    T F(T &a, T &b) { return min(a, b); }
    
    SegmentTree(int n){
        N = 1;
        while(n > N) N = N << 1;
        dat = vector<T>(2 * N - 1, id);
    }

    SegmentTree(int n, vector<T> &v){
        N = 1;
        while(n > N) N = N << 1;
        dat = vector<T>(2 * N - 1, id);
        for(int i = 0; i < n; i++) dat[i + N - 1] = v[i];
        for(int i = N - 2; i >= 0; i--) dat[i] = F(dat[i * 2 + 1], dat[i * 2 + 2]); 
    }

    SegmentTree(){}


    void update(int k, T a){
        k += N - 1;
        dat[k] = a;
        while(k > 0){
            k = (k - 1) / 2;
            dat[k] = F(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    void reset() { fill(dat.begin(), dat.end(), id); }

    T get(int a, int b, int k, int l, int r){
        if(r <= a || b <= l) return id;
        if(a <= l && r <= b) return dat[k];
        else{
            T vl = get(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = get(a, b, k * 2 + 2, (l + r) / 2, r);
            return F(vl, vr);
        }
    }
    T get(int a, int b) { return get(a, b, 0, 0, N); }

    T val(int k){ return dat[k + N - 1]; }
};

signed main(){

    int n, dt; cin >> n >> dt;
    vec t(n); cin >> t;
    pairs p(n);
    REP(i, n) p[i] = Pii(t[i], i);

    int now = 0;
    SegmentTree ST(n, p);
    set<int> s, s2; s.insert(n);
    queue<int> que;
    vec ans(n);
    while(true){
        if(!que.empty()){

            int m = *(s.begin());
            while(true){
                Pii tmp = ST.get(0, m);
                if(tmp.f < now + dt){
                    m = tmp.s;
                    que.push(tmp.s);
                    s.insert(tmp.s);
                    ST.update(tmp.s, Pii(INF, INF));
                }else break;
            }

            now += dt;
            ans[que.front()] = now;
            s.erase(que.front());
            que.pop();

            while(true){
                Pii tmp = ST.get(0, n);
                if(tmp.f <= now){
                    s2.insert(tmp.s);
                    ST.update(tmp.s, Pii(INF, INF));
                }else break;
            }

            m = *(s.begin());
            if(s2.size()){
                int m2 = *(s2.begin());
                if(m2 < m){
                    que.push(m2);
                    s.insert(m2);
                    s2.erase(m2);
                }
            }

        }else{
            Pii tmp = ST.get(0, n);
            if(tmp.f == INF) break;
            else{
                now = tmp.f;
                que.push(tmp.s);
                s.insert(tmp.s);
                ST.update(tmp.s, Pii(INF, INF));
            }
        }
    }
    REP(i, n) cout << ans[i] << ' ';
    cout << endl;

    return 0;
}