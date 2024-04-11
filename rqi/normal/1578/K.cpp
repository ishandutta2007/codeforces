#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;

using pi = pair<int, int>;
#define mp make_pair
#define f first
#define s second
#define tcT template<class T
tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vpi = V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for(int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for(auto& a: x)

const int MOD = 1e9+7;
const db EPS = 1e-9;
const ll BIG = 1e18;


tcT> bool ckmin(T& a, const T& b){
    return b < a ? a = b, 1 : 0;
}

tcT> bool ckmax(T& a, const T& b){
    return a < b ? a = b, 1 : 0;
}

struct mi{
    int v; explicit operator int() const {return v;}
    mi():v(0) {}
    mi(ll _v):v(int(_v % MOD)) {v+=(v<0)*MOD; }

};

mi& operator+=(mi& a, mi b){
    if((a.v+=b.v) >= MOD) a.v-=MOD;
    return a;
}

mi& operator-=(mi& a, mi b){
    if((a.v-=b.v) < 0) a.v+=MOD;
    return a;
}

mi operator+(mi a, mi b){
    return a+=b;
}

mi operator-(mi a, mi b){
    return a-=b;
}

mi operator*(mi a, mi b){
    return mi((ll)a.v*b.v);
}

mi& operator*=(mi& a, mi b){
    return a = a*b;
}

mi pow(mi a, ll p){
    assert(p >= 0);
    return p==0?1:pow(a*a,p/2)*(p&1?a:1);
}

mi inv(mi a){assert(a.v!=0); return pow(a, MOD-2);}
mi operator/(mi a, mi b){return a*inv(b);}
bool operator==(mi a, mi b){return a.v==b.v;}

typedef vector<mi> vmi;

vmi invs, fac, ifac;
void genFac(int SZ){
    invs.rsz(SZ), fac.rsz(SZ), ifac.rsz(SZ);
    invs[1] = fac[0] = ifac[0] = 1;
    FOR(i, 2, SZ) invs[i] = mi(-(ll)MOD/i*(int)invs[MOD%i]);
    FOR(i, 1, SZ) fac[i] = fac[i-1]*i,ifac[i] = ifac[i-1]*invs[i];
}

mi comb(int a, int b){
    if(a < b || b < 0) return 0;
    return fac[a]*ifac[b]*ifac[a-b];
}

const int mx = 100005;

struct Eff{

int n, k;
mi f[mx];

void solve(){
    genFac(100005);
    cin >> n >> k;
    map<int, int> cnt;

    int negs = 0;
    for(int i = 1; i <= n; i++){
        int A; cin >> A;
        if(A == -1){
            negs++;
        }
        else{
            cnt[A]++;
        }
    }

    

    map<int, mi> all_cnts;
    for(auto u: cnt){
        all_cnts[u.s] = mi(0);
    }

    all_cnts[0] = mi(0);

    f[0] = mi(0);
    for(int i = 0; i <= n-1; i++){
        // f[i+1] = mi(-k)*mi(i);
        f[i+1] = mi(-n);
        if(i-1 >= 0){
            f[i+1]-=mi(i)*mi(k-1)*f[i-1];
        }
        f[i+1]+=f[i]*(mi(n)-2*mi(i)+mi(i)*mi(k));
        f[i+1] = f[i+1]/mi(n-i);
    }

    // for(int i = 0; i <= n; i++){
    //     cout << i << " " << f[i].v << "\n";
    // }

    // cout << "all_cnts: " << "\n";
    vmi k1pows(n+1, mi(1));
    for(int i = 1; i <= n; i++){
        k1pows[i] = k1pows[i-1]*mi(k-1);
    }

    for(auto& u: all_cnts){
        for(int i = 0; i <= negs; i++){
            u.s+=f[u.f+i]*mi(comb(negs, i))*k1pows[negs-i];
        }
        u.s = u.s/pow(mi(k), negs);

        // cout << u.f << " " << u.s.v << "\n";
    }

    mi ans = mi(0);

    map<int, int> cnt_cnt;
    for(auto u: cnt){
        cnt_cnt[u.s]++;
    }
    cnt_cnt[0]+=(k-sz(cnt));

    for(auto u: cnt_cnt){
        // cout << "u: " << u.f << " " << u.s << "\n";
        ans+=all_cnts[u.f]*mi(u.s);
    }

    // for(auto u: cnt){
    //     ans+=all_cnts[u.s];
    // }

    ans-=(f[n]+mi(k-1)*f[0]);

    cout << ans.v << "\n";
}

};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    Eff e; e.solve();
}