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
#define vdebug(v) { cout << #v << "=" << endl; REP(i_debug, (int)v.size()){ cout << v[i_debug] << ","; } cout << endl; }
#define mdebug(m) { cout << #m << "=" << endl; REP(i_debug, (int)m.size()){ REP(j_debug, (int)m[i_debug].size()){ cout << m[i_debug][j_debug] << ","; } cout << endl;} }
#define pb push_back
#define fi first
#define se second
#define int long long
#define INF 1000000000000000000
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for (auto &x : v) is >> x; return is; }
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){ for(int i = 0; i < (int)v.size(); i++) { cout << v[i]; if(i != (int)v.size() - 1) cout << endl; }; return os; }
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

//0-indexed BIT
class BinaryIndexedTree
{
    using T = int;
private:
    void _add(int i, T x) {
        if (i > N) return;
        data[i] += x;
        _add(i + (i & -i), x);
    }

public:
    vector<T> data;
    int N;

    BinaryIndexedTree(int N): data(vector<T>(N + 1, 0)), N(N) {}
    BinaryIndexedTree(){}

    //sum of [0,i) (0<=i<=N)
    T sum(int i) {
        if (!i) return 0;
        return data[i] + sum(i - (i & -i));
    }

    //0<=i<N
    void add(int i, T x) { _add(i + 1, x); };
    void update(int i, T x){
        T now = sum(i + 1) - sum(i);
        add(i, x - now);
    }

};

signed main(){

    int t; cin >> t;
    REP(q, t){
        int n, m; cin >> n >> m;
        int N = n * m;
        vec a(N); cin >> a;

        v_Pii p(N);
        REP(i, N) p[i] = Pii(a[i], -i);
        Sort(p);

        int ans = 0;
        BinaryIndexedTree BIT(N);
        REP(i, N){
            int x = -p[i].se;
            ans += BIT.sum(x);
            BIT.add(x, 1);
        }
        cout << ans << endl;
    }

    return 0;
}