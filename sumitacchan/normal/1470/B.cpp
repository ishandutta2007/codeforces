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

vector<int> is_prime_list(int MAX_N){

    vector<int> is_prime(MAX_N + 1);
    REP(i, MAX_N + 1) is_prime[i] = i;

    FOR(i, 2, MAX_N + 1){
        if(is_prime[i] == i){
            int tmp = i * 2;
            while(tmp <= MAX_N){
                is_prime[tmp] = i;
                tmp += i;
            }
        }
    }

    return is_prime;
}

signed main(){

    int t; cin >> t;
    vec divisor = is_prime_list(1000000);
    REP(_, t){
        int n; cin >> n;
        vec a(n); cin >> a;

        map<vec, int> cnt;
        REP(i, n){
            int now = a[i];
            map<int, int> num;
            while(now > 1){
                num[divisor[now]] += 1;
                now /= divisor[now];
            }
            vec v;
            for(auto q: num) if(q.se % 2) v.pb(q.fi);
            cnt[v] += 1;
        }
        int ans0 = 0, ans1 = 0;
        for(auto q: cnt){
            chmax(ans0, q.se);
            if(q.se % 2 == 0 || SZ(q.fi) == 0) ans1 += q.se;
        }
        chmax(ans1, ans0);

        int q; cin >> q;
        REP(x, q){
            int w; cin >> w;
            if(w == 0) cout << ans0 << "\n";
            else cout << ans1 << "\n";
        }
    }

    return 0;
}