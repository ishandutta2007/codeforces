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
#define Add(x, y) x = (x + (y)) % mod
#define Mult(x, y) x = (x * (y)) % mod

struct SegmentTree
{
    using T = int;

    int N;
    vector<T> dat;

    T id = 0;
    T F(T &a, T &b) { return max(a, b); }
    
    SegmentTree(int n){
        N = 1;
        while(n > N) N = N << 1;
        dat = vector<T>(2 * N - 1, id);
    }

    SegmentTree(int n, vector<T> &v){
        N = 1;
        while(n > N) N = N << 1;
        dat = vector<T>(2 * N - 1, id);
        for(int i = 0; i < n; i++) dat[i + N - 1] = v[i];
        for(int i = N - 2; i >= 0; i--) dat[i] = F(dat[i * 2 + 1], dat[i * 2 + 2]); 
    }


    void update(int k, T a){
        k += N - 1;
        dat[k] = a;
        while(k > 0){
            k = (k - 1) / 2;
            dat[k] = F(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    void reset() { fill(dat.begin(), dat.end(), id); }

    T get(int a, int b, int k, int l, int r){
        if(r <= a || b <= l) return id;
        if(a <= l && r <= b) return dat[k];
        else{
            T vl = get(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = get(a, b, k * 2 + 2, (l + r) / 2, r);
            return F(vl, vr);
        }
    }
    T get(int a, int b) { return get(a, b, 0, 0, N); }

    T val(int k){ return dat[k + N - 1]; }
};

signed main(){

    int n; cin >> n;
    vec a(n), b(n);
    REP(i, n){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }

    pairs p1, p2;
    REP(i, n){
        if(a[i] < b[i]) p1.pb(Pii(a[i] + b[i], i));
        else{
            a[i] = 2 * n - 1 - a[i];
            b[i] = 2 * n - 1 - b[i];
            p2.pb(Pii(a[i] + b[i], i));
        }
    }


    Sort(p1); Reverse(p1);
    vec ans1;
    SegmentTree ST1(2 * n);
    mat m1(2 * n + 1);
    REP(i, SZ(p1)){
        int i0 = p1[i].s;
        int a0 = a[i0], b0 = b[i0];
        int t = ST1.get(a0 + 1, 2 * n);
        ST1.update(b0, t + 1);
        m1[t + 1].pb(i0);
    }

    int tmp1 = 0;
    IFOR(i, 1, 2 * n + 1) if(SZ(m1[i])){
        for(int i0: m1[i]) if(b[i0] > tmp1){
            ans1.pb(i0);
            tmp1 = a[i0];
            break;
        }
    }
    Reverse(ans1);

    Sort(p2); Reverse(p2);
    vec ans2;
    SegmentTree ST2(2 * n);
    mat m2(2 * n + 1);
    REP(i, SZ(p2)){
        int i0 = p2[i].s;
        int a0 = a[i0], b0 = b[i0];
        int t = ST2.get(a0 + 1, 2 * n);
        ST2.update(b0, t + 1);
        m2[t + 1].pb(i0);
    }

    int tmp2 = 0;
    IFOR(i, 1, 2 * n + 1) if(SZ(m2[i])){
        for(int i0: m2[i]) if(b[i0] > tmp2){
            ans2.pb(i0);
            tmp2 = a[i0];
            break;
        }
    }
    Reverse(ans2);

    if(SZ(ans2) > SZ(ans1)) ans1.swap(ans2);
    cout << SZ(ans1) << "\n";
    REP(i, SZ(ans1)) cout << ans1[i] + 1 << " ";
    cout << "\n";

    return 0;
}