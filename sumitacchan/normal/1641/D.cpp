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
//#define int long long
//#define INF 1000000000000000000
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

struct TimeManager{
    int TIME_LIMIT;
    chrono::high_resolution_clock::time_point clock_begin, clock_prev, clock_now;
    bool loop_initialized = false;

    TimeManager(const int TIME_LIMIT) : TIME_LIMIT(TIME_LIMIT) {
        clock_begin = chrono::high_resolution_clock::now();
    }
    // Elapsed time from the beginning
    int elapsed_time(){
        clock_now = chrono::high_resolution_clock::now();
        return chrono::duration_cast<chrono::milliseconds>(clock_now - clock_begin).count();
    }
    // Ratio of elapsed time out of TL
    double elapsed_rate(){
        return min(1.0, (double)elapsed_time() / TIME_LIMIT);
    }
    // Check whether next loop is available
    bool continue_loop(){
        assert(loop_initialized);
        clock_now = chrono::high_resolution_clock::now();
        const int duration_prev_loop = chrono::duration_cast<chrono::milliseconds>(clock_now - clock_prev).count();
        const int time_next_loop = duration_prev_loop + chrono::duration_cast<chrono::milliseconds>(clock_now - clock_begin).count();
        clock_prev = clock_now;
        return time_next_loop <= TIME_LIMIT;
    }
    void initialize_loop(){
        clock_prev = chrono::high_resolution_clock::now();
        loop_initialized = true;
    }
};

//const int mod = 1000000007;
const int mod = 998244353;

struct fast_random
{
    uint32_t x;

    fast_random(int seed = 2463534242): x(seed){}

    uint32_t xorshift(){
        x ^= (x << 13);
        x ^= (x >> 17);
        x ^= (x << 5);
        return x;
    }

    //random integer in [a, b]
    uint32_t randint(uint32_t a, uint32_t b){
        return a + xorshift() % (b - a + 1);
    }

    double uniform(){
        return (double)xorshift() / UINT32_MAX;
    }

    double uniform(double a, double b){
        return a + uniform() * (b - a);
    }

};

signed main(){

    TimeManager TM(2850);

    int n, m; cin >> n >> m;
    mat a(n, vec(m));
    vec w(n);
    REP(i, n){
        cin >> a[i];
        cin >> w[i];
    }

    map<int, int> idx;
    int num = 0;
    REP(i, n) REP(j, m){
        if(idx.count(a[i][j])) a[i][j] = idx[a[i][j]];
        else{
            idx[a[i][j]] = num;
            a[i][j] = num;
            num++;
        }
    }

    fast_random rng;
    const int sz = 20;
    const int INF = 1000000001;
    int ans = 2 * INF;
    vec hash(num), used(n);
    vec dp(bit(sz));
    const int mask = bit(sz) - 1;

    TM.initialize_loop();
    do{
        REP(i, num) hash[i] = rng.randint(0, sz - 1);
        fill(all(dp), INF);
        fill(all(used), 0);

        REP(i, n){
            REP(j, m) used[i] |= bit(hash[a[i][j]]);
            if(__builtin_popcount(used[i]) == m){
                chmin(dp[used[i]], w[i]);
            }
        }
        REP(k, sz){
            REP(i, bit(sz)) if((i >> k) & 1){
                chmin(dp[i], dp[i ^ bit(k)]);
            }
        }
        REP(i, n){
            if(__builtin_popcount(used[i]) == m){
                int tmp = dp[mask ^ used[i]];
                if(tmp < INF) chmin(ans, w[i] + tmp);
            }
        }
    }while(TM.continue_loop());

    chOut(ans < 2 * INF, ans, -1);

    return 0;
}