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

const int mod = 1000000007;
//int mod = 998244353;
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
int lcm(int a, int b){
    int x, y;
    int g = extgcd(a, b, x, y);
    a /= g;
    return a * b;
}

signed main(){

    int n, m;cin >> n >> m;
    vec a(m), b(m);
    mat ls(n / 2 + 1);
    REP(i, m){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        if(a[i] > b[i]) swap(a[i], b[i]);
        int v1 = b[i] - a[i], v2 = n - v1;
        if(v1 == v2){
            ls[v1].pb(a[i]);
            ls[v1].pb(b[i]);
        }else if(v1 <= v2){
            ls[v1].pb(a[i]);
        }else{
            ls[v2].pb(b[i]);
        }
    }
    bool f = true;
    int l = 1;
    FOR(i, 1, n / 2 + 1){
        int sz = SZ(ls[i]);
        if(sz){
            if(sz == 1){
                f = false;
            }else{
                int tmp = n;
                Sort(ls[i]);
                FOR(nd, 2, sz + 1) if(sz % nd == 0){
                    bool tmpf = true;
                    int D = sz / nd;
                    int d = ls[i][D] - ls[i][0];
                    REP(j, sz) if(ls[i][(j + D) % sz] != (ls[i][j] + d) % n) tmpf = false;
                    if(tmpf) Min(tmp, d);
                }
                if(tmp == n) f = false;
                if(f) l = lcm(l, tmp);
            }
        }
        if(!f) break;
    }
    Ans(f && l < n, "Yes", "No");

    return 0;
}