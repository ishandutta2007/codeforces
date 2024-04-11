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
#define vdebug(v) { cout << #v << "=" << endl; REP(i_debug, v.size()){ cout << v[i_debug] << ","; } cout << endl; }
#define mdebug(m) { cout << #m << "=" << endl; REP(i_debug, m.size()){ REP(j_debug, m[i_debug].size()){ cout << m[i_debug][j_debug] << ","; } cout << endl;} }
#define Return(ans) { cout << (ans) << endl; return 0; }
#define pb push_back
#define f first
#define s second
#define int long long
#define INF 1000000000000000000
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for (auto &x : v) is >> x; return is; }
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){ for(int i = 0; i < v.size(); i++) { cout << v[i]; if(i != v.size() - 1) cout << endl; }; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1, T2> p){ cout << '(' << p.first << ',' << p.second << ')'; return os; }
template<typename T> void Out(T x) { cout << x << endl; }
template<typename T1, typename T2> void Ans(bool f, T1 y, T2 n) { if(f) Out(y); else Out(n); }

using vec = vector<int>;
using mat = vector<vec>;
using Pii = pair<int, int>;
using PiP = pair<int, Pii>;
using PPi = pair<Pii, int>;
using Pdi = pair<double, int>;
using bools = vector<bool>;
using pairs = vector<Pii>;

//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//char d[4] = {'D','R','U','L'};

const int mod = 1000000007;
//const int mod = 998244353;
//#define Add(x, y) x = (x + (y)) % mod
//#define Mult(x, y) x = (x * (y)) % mod

//gcd(0,x)=gcd(x,0)=x, gcd(0,0)=0
int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int gcd_multi(vec a){
    int g = a[0];
    FOR(i, 1, a.size()) g = gcd(g, a[i]);
    return g;
}

int lcm(int a, int b){
    int g = gcd(a, b);
    return (a / g) * b;
}


int lcm_multi(vec a){
    int p = a[0];
    FOR(i, 1, a.size()) p = lcm(p, a[i]);
    return p;
}

vec prime_list(int MAX_N){

    vector<bool> is_prime(MAX_N + 1, true);
    vec prime(0);
    is_prime[0] = false;
    is_prime[1] = false;

    FOR(i, 2, MAX_N + 1){
        if(is_prime[i]){
            prime.push_back(i);
            int tmp = i * 2;
            while(tmp <= MAX_N){
                is_prime[tmp] = false;
                tmp += i;
            }
        }
    }

    return prime;
}

signed main(){

    int n; cin >> n;
    vec a(n); cin >> a;

    vec primes = prime_list(500);
    mat ls(200001);
    REP(i, n){
        for(int p: primes){
            int c = 0;
            while(a[i] % p == 0){
                a[i] /= p;
                c++;
            }
            if(c) ls[p].pb(c);
        }
        if(a[i] > 1) ls[a[i]].pb(1);
    }

    int ans = 1;
    REP(i, 200001) if(SZ(ls[i]) >= n - 1){
        Sort(ls[i]);
        int t;
        if(SZ(ls[i]) == n - 1) t = ls[i][0];
        else t = ls[i][1];

        REP(q, t) ans *= i;
    }
    Out(ans);

    return 0;
}