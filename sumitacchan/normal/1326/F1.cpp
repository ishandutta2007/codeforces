#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using gpp_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename L> using gpp_map = tree<T, L, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using gpp_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;*/
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define Sort(v) sort(v.begin(), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define all(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)
#define bit(n) (1<<(n))
#define bit_exist(x, n) ((x >> n) & 1)
#define debug(x) cout << #x << "=" << x << endl;
#define vdebug(v) { cout << #v << "=" << endl; REP(i_debug, v.size()){ cout << v[i_debug] << ","; } cout << endl; }
#define mdebug(m) { cout << #m << "=" << endl; REP(i_debug, m.size()){ REP(j_debug, m[i_debug].size()){ cout << m[i_debug][j_debug] << ","; } cout << endl;} }
#define Return(ans) { cout << (ans) << endl; return 0; }
#define pb push_back
#define f first
#define s second
//#define int long long
//#define INF 1000000000000000000
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
using bools = vector<bool>;
using pairs = vector<Pii>;

//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//char d[4] = {'D','R','U','L'};

const int mod = 1000000007;
//const int mod = 998244353;
//#define Add(x, y) x = (x + (y)) % mod
//#define Mult(x, y) x = (x * (y)) % mod



signed main(){

    int n; cin >> n;
    vector<string> s_(n); cin >> s_;
    //vector<bools> s(n, bools(n, false));
    bool s[14][14] = {};
    REP(i, n) REP(j, n) if(s_[i][j] == '1') s[i][j] = true;

    if(n == 2){
        if(s[0][1]){
            cout << 0 << ' ' << 2 << endl;
        }else{
            cout << 2 << ' ' << 0 << endl;
        }
        return 0;
    }

    int k = n / 2 + 1;
    vec cnt1(bit(k - 1)), cnt2(bit(n - k));
    vector<long long> ans(bit(n - 1));
    REP(a, n){

        int comb = bit(k) - 1;
        while(comb < bit(n)){
            fill(all(cnt1), 0);
            fill(all(cnt2), 0);
            //debug(comb);
            if((comb >> a) & 1){
                int rev = (bit(n) - 1) ^ comb ^ bit(a);

                vec v, w;
                REP(i, n) if(i != a){
                    if((comb >> i) & 1) v.pb(i);
                    else if((rev >> i) & 1) w.pb(i);
                }
                const int sv = SZ(v), sw = SZ(w);

                do{
                    int val = 0;
                    if(s[v[0]][a]) val++;
                    REP(i, sv - 1){
                        val <<= 1;
                        if(s[v[i]][v[i + 1]]) val++;
                    }
                    cnt1[val]++;
                }while(next_permutation(all(v)));

                do{
                    int val = 0;
                    REP(i, sw - 1){
                        if(s[w[i]][w[i + 1]]) val++;
                        val <<= 1;
                    }
                    if(s[a][w[sw - 1]]) val++;
                    cnt2[val]++;
                }while(next_permutation(all(w)));

                REP(i, bit(sv)) if(cnt1[i]){
                    REP(j, bit(sw)) ans[i ^ (j << sv)] += cnt1[i] * cnt2[j];
                }
            }

            int x = comb & -comb, y = comb + x;
            comb = ((comb & ~y) / x >> 1) | y;
        }
    } 
    
    for(auto x: ans) cout << x << ' ';
    cout << endl;

    return 0;
}