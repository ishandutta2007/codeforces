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

    int n; cin >> n;

    vec xs, ys;
    REP(i, n){
        cout << "? " << i + 1 << " " << 1 << " " << i + 1 << " " << n << endl;
        int a; cin >> a;
        if(a % 2) xs.pb(i);
    }
    REP(i, n){
        cout << "? " << 1 << " " << i + 1 << " " << n << " " << i + 1 << endl;
        int a; cin >> a;
        if(a % 2) ys.pb(i);
    }

    if(SZ(xs) == 2 && SZ(ys) == 2){
        cout << "? " << xs[0] + 1 << " " << ys[0] + 1 << " " <<  xs[0] + 1 << " " << ys[0] + 1 << endl;
        int a; cin >> a;
        if(a % 2){
            cout << "! " << xs[0] + 1 << " " << ys[0] + 1 << " " <<  xs[1] + 1 << " " << ys[1] + 1 << endl;
        }else{
            cout << "! " << xs[0] + 1 << " " << ys[1] + 1 << " " <<  xs[1] + 1 << " " << ys[0] + 1 << endl;
        }
    }else if(SZ(xs) == 2){
        int y0 = -1, y1 = n - 1;
        while(y1 - y0 > 1){
            int y = (y0 + y1) / 2;
            cout << "? " << xs[0] + 1 << " " << 1 << " " <<  xs[0] + 1 << " " << y + 1 << endl;
            int a; cin >> a;
            if(a % 2) y1 = y;
            else y0 = y;
        }
        cout << "! " << xs[0] + 1 << " " << y1 + 1 << " " <<  xs[1] + 1 << " " << y1 + 1 << endl;
    }else{
        int x0 = -1, x1 = n - 1;
        while(x1 - x0 > 1){
            int x = (x0 + x1) / 2;
            cout << "? " << 1 << " " << ys[0] + 1 << " " <<  x + 1 << " " << ys[0] + 1 << endl;
            int a; cin >> a;
            if(a % 2) x1 = x;
            else x0 = x;
        }
        cout << "! " << x1 + 1 << " " << ys[0] + 1 << " " <<  x1 + 1 << " " << ys[1] + 1 << endl;
    }


    return 0;
}