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

//const int mod = 1000000007;
const int mod = 998244353;

template<long long MOD>
struct ModInt{

    using ll = long long;
    ll val;

    void setval(ll v) { val = v % MOD; };
    ModInt(): val(0) {}
    ModInt(ll v) { setval(v); };

    ModInt operator+(const ModInt &x) const { return ModInt(val + x.val); }
    ModInt operator-(const ModInt &x) const { return ModInt(val - x.val + MOD); }
    ModInt operator*(const ModInt &x) const { return ModInt(val * x.val); }
    ModInt operator/(const ModInt &x) const { return *this * x.inv(); }
    ModInt operator-() const { return ModInt(MOD - val); }
    ModInt operator+=(const ModInt &x) { return *this = *this + x; }
    ModInt operator-=(const ModInt &x) { return *this = *this - x; }
    ModInt operator*=(const ModInt &x) { return *this = *this * x; }
    ModInt operator/=(const ModInt &x) { return *this = *this / x; }
    bool operator==(const ModInt &x) const { return (*this).val == x.val; }

    friend ostream& operator<<(ostream &os, const ModInt &x) { os << x.val; return os; }
    friend istream& operator>>(istream &is, ModInt &x) { is >> x.val; x.val = (x.val % MOD + MOD) % MOD; return is; }

    ModInt pow(ll n) const {
        ModInt a = 1;
        if(n == 0) return a;
        int i0 = 64 - __builtin_clzll(n);
        for(int i = i0 - 1; i >= 0; i--){
            a = a * a;
            if((n >> i) & 1) a *= (*this); 
        }
        return a;
    }
    ModInt inv() const { return this->pow(MOD - 2); }
};

using mint = ModInt<mod>; mint pow(mint x, long long n) { return x.pow(n); }
//using mint = double; //for debug
using mvec = vector<mint>;
using mmat = vector<mvec>;

struct Combination{

    vector<mint> fact, invfact;

    Combination(int N){
        fact = vector<mint>({mint(1)});
        invfact = vector<mint>({mint(1)});
        fact_initialize(N);
    }

    void fact_initialize(int N){
        int i0 = fact.size();
        if(i0 >= N + 1) return;
        fact.resize(N + 1);
        invfact.resize(N + 1);
        for(int i = i0; i <= N; i++) fact[i] = fact[i - 1] * i;
        invfact[N] = (mint)1 / fact[N];
        for(int i = N - 1; i >= i0; i--) invfact[i] = invfact[i + 1] * (i + 1); 
    }

    mint nCr(int n, int r){
        if(n < 0 || r < 0 || r > n) return mint(0);
        if((int)fact.size() < n + 1) fact_initialize(n);
        return fact[n] * invfact[r] * invfact[n - r];
    }

    mint nPr(int n, int r){
        if(n < 0 || r < 0 || r > n) return mint(0);
        if((int)fact.size() < n + 1) fact_initialize(n);
        return fact[n] * invfact[n - r];
    }

    mint Catalan(int n){
        if(n < 0) return 0;
        else if(n == 0) return 1;
        if((int)fact.size() < 2 * n + 1) fact_initialize(2 * n);
        return fact[2 * n] * invfact[n + 1] * invfact[n];
    }

};

template<typename T> 
struct edge{ int to; T cost; int id; };

template<typename T = long long>
struct Graph
{

    int N;
    vector<vector<edge<T>>> E;
    v_Pii A;
    vec div;
    mint ans = 0;

    Graph(int N): N(N){
        E = vector<vector<edge<T>>>(N, vector<edge<T>>(0));
        A.resize(N - 1);

        div.resize(N + 1, -1);
        FOR(i, 2, N + 1){
            if(div[i] == -1){
                for(int j = i; j <= N; j += i) div[j] = i;
            }
        }
    }

    void add_Directed_edge(int from, int to, T cost = 1, int id = 0){
        E[from].push_back(edge<T>({ to, cost, id }));
    }

    void add_Undirected_edge(int v1, int v2, T cost = 1, int id = 0){
        add_Directed_edge(v1, v2, cost, id);
        add_Directed_edge(v2, v1, cost, id);
    }

    void dfs(int v, int p, int id, mint x, vec &now, vec &MM){
        ans += x;
        if(id != -1){
            int a0 = A[id].fi, a1 = A[id].se;
            if(p > v) swap(a0, a1);
            while(a1 > 1){
                int d = div[a1];
                now[d]--;
                a1 /= d;
            }
            while(a0 > 1){
                int d = div[a0];
                now[d]++;
                chmax(MM[d], now[d]);
                a0 /= d;
            }  
        }

        for(auto e: E[v]) if(e.to != p){
            int a0 = A[e.id].fi, a1 = A[e.id].se;
            if(v > e.to) swap(a0, a1);
            mint y = x * a1 / a0;
            dfs(e.to, v, e.id, y, now, MM);
        }

        if(id != -1){
            int a0 = A[id].fi, a1 = A[id].se;
            if(p > v) swap(a0, a1);
            while(a1 > 1){
                int d = div[a1];
                now[d]++;
                a1 /= d;
            }
            while(a0 > 1){
                int d = div[a0];
                now[d]--;
                a0 /= d;
            }  
        }
    }

};


signed main(){

    int t; cin >> t;
    REP(_, t){
        int n; cin >> n;
        Graph G(n);
        REP(i, n - 1){
            int a, b, x, y; cin >> a >> b >> x >> y;
            a--; b--;
            if(a > b){
                swap(a, b);
                swap(x, y);
            }
            G.add_Undirected_edge(a, b, 0, i);
            G.A[i] = Pii(x, y);
        }

        vec MM(n + 1, 0), now(n + 1, 0);
        G.dfs(0, -1, -1, 1, now, MM);
        //debug(G.ans);
        //vdebug(MM);
        mint ans = G.ans;
        FOR(i, 2, n + 1) if(MM[i] > 0) ans *= pow((mint)i, MM[i]);
        Out(ans); 
    }

    return 0;
}