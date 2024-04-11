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

//ax+by=gx,y
long long extgcd(long long a, long long b, long long &x, long long &y){
    long long d = a;
    if(b != 0){
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }else{
        x = 1;
        y = 0;
    }
    return d;
}

//(-1,-1)
#define CRT_NO_SOLUTION pair<long long, long long>(-1, -1)
pair<long long, long long> crt(vector<long long> r, vector<long long> m){
    int n = r.size();
    REP(i, n){
        r[i] %= m[i];
        if(r[i] < 0) r[i] += m[i];
    }

    long long r0 = 0, m0 = 1;
    REP(i, n){
        long long r1 = r[i], m1 = m[i];
        if(m0 < m1){
            swap(m0, m1);
            swap(r0, r1);
        }

        if(m0 % m1 == 0){
            if(r0 % m1 != r1) return CRT_NO_SOLUTION;
            else continue;
        }

        long long g, x, y;
        g = extgcd(m0, m1, x, y);
        if((r1 - r0) % g) return CRT_NO_SOLUTION;
        
        //k*m0=g mod m1 <=> k=x mod T 
        long long T = m1 / g;
        x %= T;
        if(x < 0) x += T;
        //k*m0=r1-r0 mod m1 <=> k=x mod T 
        x *= ((r1 - r0) / g) % T;
        x %= T;
        if(x < 0) x += T;

        r0 += x * m0;
        m0 *= T;
    }
    return pair<long long, long long>(r0, m0);
}

signed main(){

    int n, m, k; cin >> n >> m >> k;
    vec a(n), b(m);
    cin >> a; 
    cin >> b;
    REP(i, n) a[i]--;
    REP(i, m) b[i]--;

    if(n < m){
        swap(n, m);
        a.swap(b);
    }

    vec inva(2 * max(n, m), -1);
    REP(i, n) inva[a[i]] = i;
    vec k0(m, -1);
    REP(i, m){
        if(inva[b[i]] != -1){
            auto res = crt(vec({inva[b[i]], i}), vec({n, m}));
            if(res != CRT_NO_SOLUTION){
                k0[i] = (res.fi - i) / m;
            }
        }
    }
    int T = n / gcd(n, m);

    int x0 = 0, x1 = 3000000000000000000;
    while(x1 - x0 > 1){
        int x = (x0 + x1) / 2;
        int cnt = 0;
        REP(i, m){
            int t = x / m;
            if(m * t + i + 1 <= x) t++;

            if(inva[b[i]] != -1 && k0[i] != -1){
                cnt += (t - k0[i] + T - 1) / T;
            }
        }
        if(x - cnt >= k) x1 = x;
        else x0 = x;
    }
    Out(x1);

    return 0;
}