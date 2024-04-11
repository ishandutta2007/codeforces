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
//#define int long long
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

class Lazy_segment_tree
{
    using data_type = Pii;

public:

    vector<data_type> dat, lazy;
    int N;
    data_type id, id2;

    //
    data_type func(data_type u, data_type v){
        if(v.f) return v;
        else return Pii(u.f, u.s ^ v.s);
    }
    //
    data_type func2(data_type u, data_type v){
        if(v.f) return v;
        else return Pii(u.f, u.s ^ v.s);
    }
    //
    data_type func3(data_type u, data_type v){
        if(v.f) return v;
        else return Pii(u.f, u.s ^ v.s);
    }

    Lazy_segment_tree(int n, data_type id, data_type id2): id(id), id2(id2) {
        N = 1;
        while(n > N) N = N << 1;
        dat = vector<data_type>(2 * N - 1, id);
        lazy = vector<data_type>(2 * N - 1, id2);
    }

    Lazy_segment_tree(int n, data_type id, data_type id2, vector<data_type> v): id(id), id2(id2) {
        N = 1;
        while(n > N) N = N << 1;
        dat = vector<data_type>(2 * N - 1, id);
        lazy = vector<data_type>(2 * N - 1, id2);
        REP(i, n) dat[i + N - 1] = v[i];
        IREP(i, N - 1) dat[i] = func(dat[i * 2 + 1], dat[i * 2 + 2]); 
    }

    //
    void eval(int k, int l, int r){
        if(lazy[k] != id2){
            //
            //dat[k] = func2(dat[k], lazy[k] * (r - l));
            //
            dat[k] = func2(dat[k], lazy[k]);

            if(r - l > 1){
                lazy[k * 2 + 1] = func3(lazy[k * 2 + 1], lazy[k]);
                lazy[k * 2 + 2] = func3(lazy[k * 2 + 2], lazy[k]);
            }

            lazy[k] = id2;
        }
    }

    void update(int a, int b, data_type x, int k, int l, int r){

        eval(k, l, r);

        if(b <= l || r <= a) return;

        if(a <= l && r <= b){
            lazy[k] = func3(lazy[k], x);
            eval(k, l, r);
        }else{
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);
            dat[k] = func(dat[k * 2 + 1], dat[k * 2 + 2]);
        }

    }

    data_type query(int a, int b, int k, int l, int r){
        if(r <= a || b <= l) return id;

        eval(k, l, r);
        if(a <= l && r <= b) return dat[k];
        else{
            data_type vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            data_type vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return func(vl, vr);
        }
    }

    //[a,b)
    void update(int a, int b, data_type x){
        update(a, b, x, 0, 0, N);
    }

    //[a, b)
    data_type query(int a, int b){
        return query(a, b, 0, 0, N);
    }

    data_type getdat(int k){
        return query(k, k + 1);
    }
};

signed main(){

    int n, q; cin >> n >> q;
    vec a(n); readv(a);
    vector<char> s(q);
    vec x(q);
    REP(i, q) cin >> s[i] >> x[i];

    int M = 100000;
    Lazy_segment_tree ST(M + 1, Pii(0, 0), Pii(0, 0));
    REP(i, q){
        if(s[i] == '>' && x[i] >= 0){
            ST.update(x[i] + 1, M + 1, Pii(1, 1));
        }else if(s[i] == '<' && x[i] <= 0){
            ST.update(-x[i] + 1, M + 1, Pii(1, 0));
        }else if(s[i] == '<' && x[i] > 0){
            ST.update(x[i], M + 1, Pii(1, 0));
            ST.update(0, x[i], Pii(0, 1));
        }else if(s[i] == '>' && x[i] < 0){
            ST.update(-x[i], M + 1, Pii(1, 1));
            ST.update(0, -x[i], Pii(0, 1));
        }
    }
    REP(i, n){
        Pii p = ST.getdat(abs(a[i]));
        if(p.f){
            if(p.s) a[i] = -abs(a[i]);
            else a[i] = abs(a[i]); 
        }else{
            if(p.s) a[i] *= -1;
        }
        cout << a[i] << " ";
    }
    Pii p = ST.getdat(3);

    return 0;
}