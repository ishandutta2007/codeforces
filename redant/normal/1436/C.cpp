#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;

template<class T> bool tmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool tmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define SZ(x) (int)(x).size()
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define TRAV(a,x) for (auto& a : x)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int mod = 1000000007;
const int MX = 1003;

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

int fac[MX];

void nfinit() {
    fac[0] = fac[1] = 1;
    for (int i = 2; i < MX; i++) {
        fac[i] = mmul(i, fac[i-1]);
    }
}

int facc(int n) {
    if (n < 0) return 0;
    if (fac[0] == 0) nfinit();
    return fac[n];
}

int nck(int n, int k) {
    if (n < k) return 0;
    if (k == 0 || n == k) return 1;
    if (fac[0] == 0) nfinit();
    return mdiv(fac[n], mmul(fac[n-k], fac[k]));
}

int n, x, pos;

int solve() {
    int a = 0, b = 0;

    int left = 0, right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (mid == pos) {
            left = mid + 1;
        } else if (mid < pos) {
            a++;
            left = mid + 1;
        } else {
            b++;
            right = mid;
        }
    }

    int ra = mmul(nck(x-1,a), facc(a));
    int rb = mmul(nck(n-x,b), facc(b));
    int rc = facc(n-1-a-b);
    return mmul(ra, mmul(rb, rc));
}

int main() {
    setIO();
    cin>>n>>x>>pos;
    cout<<solve()<<"\n";
    return 0;
}