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
#define Ans(f, y, n) if(f) cout << y << endl; else cout << n << endl;
#define debug(x) cout << #x << "=" << x << endl;
#define vdebug(v) cout << #v << "=" << endl; REP(i, v.size()){ cout << v[i] << ","; } cout << endl;
#define mdebug(m) cout << #m << "=" << endl; REP(i, m.size()){ REP(j, m[i].size()){ cout << m[i][j] << ","; } cout << endl;}
#define pb push_back
#define f first
#define s second
#define int long long
#define INF 1000000000000000000

using vec = vector<int>;
using mat = vector<vec>;
using Pii = pair<int, int>;
using PiP = pair<int, Pii>;
using PPi = pair<Pii, int>;
using bools = vector<bool>;
using pairs = vector<Pii>;

template<typename T> void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readv_m1(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }

//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};

int mod = 1000000007;
//int mod = 998244353;
#define Add(x, y) x = (x + (y)) % mod
#define Mult(x, y) x = (x * (y)) % mod



signed main(){

    int n, m; cin >> n >> m;
    mat a(n, vec(m));
    REP(i, n) readv(a[i]);

    if(n == 1){
        cout << "YES" << endl;
        cout << 0 << endl;
        REP(j, m){
            if(a[0][j]) cout << 1;
            else cout << 0;
        }
        cout << endl;
        return 0;
    }

    bool f = false;
    vec ans1(n), ans2(m);
    REP(ib, n){
        mat b = a;
        int i0 = 0;
        if(ib == 0) i0 = 1;
        REP(j, m){
            if(b[i0][j] != b[i0][0]){
                ans2[j] = 1;
                REP(i, n) b[i][j] ^= 1;
            }else ans2[j] = 0;
        }

        bool f2 = true;
        REP(i, n) if(i != ib){
            REP(j, m) if(b[i][j] != b[i][0]) f2 = false;
        }
        if(!f2) continue;
        FOR(i, 0, ib){
            if(b[i][0] == 1) ans1[i] = 1;
            else ans1[i] = 0;
        }
        FOR(i, ib + 1, n){
            if(b[i][0] == 0) ans1[i] = 1;
            else ans1[i] = 0;
        }

        if(b[ib][0] == 1) ans1[ib] = 1;
        REP(j, m - 1) if((b[ib][j] ^ ans1[ib]) > (b[ib][j + 1] ^ ans1[ib])) f2 = false;
        if(f2){
            f = true;
            break;
        }
    }
    if(f){
        cout << "YES" << endl;
        REP(i, n) cout << ans1[i];
        cout << endl;
        REP(j, m) cout << ans2[j];
        cout << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}