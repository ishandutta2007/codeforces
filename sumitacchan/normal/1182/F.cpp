#include <bits/stdc++.h>
using namespace std;
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
#define Add(x, y) x = (x + (y)) % mod
#define Mult(x, y) x = (x * (y)) % mod

int extgcd(int a, int b, int &x, int &y){
    int d = a;
    if(b != 0){
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }else{
        x = 1;
        y = 0;
    }
    return d;
}

int modpow(int x, int n, int m){
    int a = 1;
    IREP(i, 64){
        a = (a * a) % m;
        if(((n >> i) & 1) == 1) a = (a * x) % m;
    }
    return a;
}

int calcans(int a, int b, int p, int q){
    int c = q / 2, d = q - c;
    if(b - a <= 100000){
        int M = INF;
        int ans = -1;
        FOR(x, a, b + 1){
            int tmp = (p * x) % q;
            int val = min(llabs(c - tmp), llabs(d - tmp));
            if(val < M){
                M = val;
                ans = x;
            }
        }
        return ans;
    }else{
        int x, y;
        int g = extgcd(p, q, x, y);
        int inv = (x % q + q) % q;
        REP(i, q){
            int c1 = c - i, d1 = d + i;
            c1 = (c1 * inv) % q;
            if(c1 < a) c1 += ((a - c1 - 1) / q + 1) * q;
            d1 = (d1 * inv) % q;
            if(d1 < a) d1 += ((a - d1 - 1) / q + 1) * q;

            int ans = INF;
            if(a <= c1 && c1 <= b) Min(ans, c1);
            if(a <= d1 && d1 <= b) Min(ans, d1);
            if(ans < INF) return ans;
        }
        return 0;
    }
}

signed main(){

    int t; cin >> t;
    vec ans(t);
    int x, y;
    REP(i, t){
        int a, b, p, q; cin >> a >> b >> p >> q;
        int g = extgcd(p, q, x, y);
        p /= g; q /= g;
        ans[i] = calcans(a, b, p, q);
    }
    REP(i, t) cout << ans[i] << '\n';

    return 0;
}