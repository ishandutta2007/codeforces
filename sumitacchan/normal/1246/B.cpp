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

int ipow(int x, int n){
    int a = 1;
    if(n == 0) return a;
    int i0 = 64 - __builtin_clzll(n);
    for(int i = i0 - 1; i >= 0; i--){
        a = a * a;
        if((n >> i) & 1) a *= x; 
    }
    return a;
}


signed main(){

    int n, k; cin >> n >> k;
    vec a(n); cin >> a;

    vec prime = prime_list(316);
    //debug(SZ(prime));
    int ans = 0;

    vec cnt(100001, 0);
    REP(i, n){
        int d = 1;
        int a0 = 1;
        for(int p: prime){
            int c = 0;
            while(a[i] % p == 0){
                a[i] /= p;
                c++;
            }
            c %= k;
            if(c){
                a0 *= ipow(p, c);
                if(d < INF && pow((double)p, k - c) < 1.0e6){
                    d *= ipow(p, k - c);
                    if(d > 100000) d = INF;
                }else d = INF;
            }
        }

        if(a[i] > 1){
            a0 *= a[i];
            if(k == 2){
                d *= a[i];
                if(d > 100000) d = INF;
            }
            else d = INF;
        }

        if(d <= 100000) ans += cnt[d];
        cnt[a0]++;
    }
    Out(ans);

    return 0;
}