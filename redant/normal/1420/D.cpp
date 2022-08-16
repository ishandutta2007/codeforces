#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define SET(v,x) memset(v,x,sizeof v)
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define SZ(v) int((v).size())

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 300005;
const int mod = 998244353;

int madd(int a, int b) {
    a = a + b;
    while (a < 0) a += mod;
    while (a >= mod) a -= mod;
    return a;
}

int mmul(int a, int b) {
    return (a * 1ll * b) % mod;
}

int mpow(int a, int n) {
    int r = 1;
    for(; n; n >>= 1) {
        if (n&1) r = mmul(r, a);
        a = mmul(a, a);
    }
    return r;
}

int minv(int a) {
    return mpow(a, mod-2);
}

int mdiv(int a, int b) {
    return mmul(a, minv(b));
}

int fac[SZ];

void nfinit() {
    fac[0] = fac[1] = 1;
    for (int i = 2; i < SZ; i++) {
        fac[i] = mmul(i, fac[i-1]);
    }
}

int nck(int n, int k) {
    if (n < k) return 0;
    if (k == 0 || n == k) return 1;
    if (fac[0] == 0) nfinit();
    return mdiv(fac[n], mmul(fac[n-k], fac[k]));
}

// ------------

int n, k;
PI a[2*SZ];

int solve() {
    int N = n<<1;
    sort(a, a+N);
    int res = 0, tc = 0;
    for (int i = 0; i < N; i++) {
        if(a[i].S == -1) {
            tc--;
        } else {
            tc++;
            if (tc >= k) {
                res = madd(res, nck(tc - 1, k - 1));
            }
        }
    }
    return res; 
}

int main() {
    setIO();
    cin>>n>>k;
    int p=0;
    REP(i, n) {
        int l, r;
        cin>>l>>r;
        a[p++] = MP(l, 1);
        a[p++] = MP(r + 1, -1);
    }
    cout<<solve()<<"\n";
    
    return 0;
}