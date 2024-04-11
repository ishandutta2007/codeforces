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
//#define int long long
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



signed main(){

    int n; cin >> n;
    vector<string> s(n); cin >> s;

    char vowel[5] = {'a', 'i', 'u', 'e', 'o'};
    int MAX = 1000000;
    vector<mat> cnt(MAX + 1, mat(5, vec(0)));
    REP(i, n){
        int l = -1;
        int c = 0;
        IREP(j, SZ(s[i])){
            REP(k, 5) if(s[i][j] == vowel[k]){
                if(l == -1) l = k;
                c++;
                break;
            }
        }
        cnt[c][l].pb(i);
    }
    
    pairs p1, p2;
    REP(i, n){
        vec rest;
        REP(j, 5){
            int sz = SZ(cnt[i][j]);
            REP(k, sz / 2){
                p1.pb(Pii(cnt[i][j][k * 2], cnt[i][j][k * 2 + 1]));
            }
            if(sz % 2) rest.pb(cnt[i][j].back()); 
        }
        int sz = SZ(rest);
        REP(k, sz / 2){
            p2.pb(Pii(rest[k * 2], rest[k * 2 + 1]));
        }
    }
    int ans = min(SZ(p1), (SZ(p1) + SZ(p2)) / 2);
    cout << ans << '\n';

    while(SZ(p2) < ans){
        p2.pb(p1.back());
        p1.pop_back();
    }
    REP(i, ans){
        cout << s[p2[i].f] << " " << s[p1[i].f] << '\n';
        cout << s[p2[i].s] << " " << s[p1[i].s] << '\n';
    }


    return 0;
}