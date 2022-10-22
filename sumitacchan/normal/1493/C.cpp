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

string calcans(string s, vec r, int S, int k){
    int n = SZ(s);
    IREP(i, n){
        S -= r[s[i] - 'a'];
        (r[s[i] - 'a'] += 1) %= k;
        S += r[s[i] - 'a'];

        REP(a, 26) if(a > s[i] - 'a'){
            S -= r[a];
            (r[a] += -1 + k) %= k;
            S += r[a];

            if(S <= n - 1 - i){
                string ans = s.substr(0, i);
                ans += 'a' + a;
                ans += string(n - 1 - i - S, 'a');
                REP(b, 26) ans += string(r[b], 'a' + b);
                return ans;
            }

            S -= r[a];
            (r[a] += 1) %= k;
            S += r[a];
        }
    }
}

signed main(){

    int T; cin >> T;
    REP(q, T){
        int n, k; cin >> n >> k;
        string s; cin >> s;
        if(n % k) Out(-1);
        else{
            vec r(26, 0);
            REP(i, n) (r[s[i] - 'a'] += -1 + k) %= k;
            int S = 0;
            REP(a, 26) S += r[a];
            if(S == 0) Out(s);
            else Out(calcans(s, r, S, k));
        }
    }

    return 0;
}