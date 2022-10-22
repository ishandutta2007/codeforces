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
//#define Add(x, y) x = (x + (y)) % mod
//#define Mult(x, y) x = (x * (y)) % mod

//0-indexed BIT
class BinaryIndexedTree
{
    using T = int;
private:
    void _add(int i, T x) {
        if (i > N) return;
        data[i] += x;
        _add(i + (i & -i), x);
    }

public:
    vector<T> data;
    int N;

    BinaryIndexedTree(int N): data(vector<T>(N + 1, 0)), N(N) {}
    BinaryIndexedTree(){}

    //sum of [0,i) (0<=i<=N)
    T sum(int i) {
        if (!i) return 0;
        return data[i] + sum(i - (i & -i));
    }

    void add(int i, T x) { _add(i + 1, x); };
    void update(int i, T x){
        T now = sum(i + 1) - sum(i);
        add(i, x - now);
    }

};

vec SUM(int n, vec a, vec b){
    vec s(n + 1, 0);
    REP(i, n + 1) s[i] = a[i] + b[i];

    REP(i, n){
        if(s[i] > i){
            s[i] %= (i + 1);
            s[i + 1]++;
        }
    }
    return s;
}

signed main(){

    int n; cin >> n;
    vec p(n); cin >> p;
    vec q(n); cin >> q;
    vec a(n + 1, 0), b(n + 1, 0);
    BinaryIndexedTree bp(n), bq(n);
    REP(i, n){
        a[n - 1 - i] = p[i] - bp.sum(p[i]);
        bp.add(p[i], 1);
        b[n - 1 - i] = q[i] - bq.sum(q[i]);
        bq.add(q[i], 1);
    }
    //vdebug(a);
    //vdebug(b);
    vec s = SUM(n, a, b);
    //vdebug(s);

    vec r(n);
    BinaryIndexedTree br(n);
    REP(i, n){
        int x = s[n - 1 - i];
        int j0 = -1, j1 = n;
        while(j1 - j0 > 1){
            int j = (j0 + j1) / 2;
            if(j - br.sum(j + 1) >= x) j1 = j;
            else j0 = j;
        }
        r[i] = j1;
        br.add(j1, 1);
        //debug(x);
        //debug(j1);
    }

    REP(i, n) cout << r[i] << ' ';
    cout << endl;

    return 0;
}