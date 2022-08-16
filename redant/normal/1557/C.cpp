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

const int mod = 1e9+7;


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

const int MX = 200005;
int n, k;
int dp[MX];

int f() {
    dp[0] = 1;
    for (int i = 1; i <= k; i++) {
        int r = 0;
        if (n&1) { // odd
            //10
            // = 0

            //11
            // f(m-1)

            //00
            // (2^(n-1)) * f(m-1)

            r = mmul(dp[i-1], madd(1, mpow(2, n-1)));

        } else { // even
            //10
            // = 1 * 2^(n*(m-1))

            //11
            // = 0

            //00
            // (2^(n-1) - 1) * f(m-1)

            r = madd(mpow(mpow(2, n), i-1), mmul(dp[i-1], madd(mpow(2, n-1), -1)));
        }
        dp[i] = r;
    }
    return dp[k];
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>k;
        cout<<f()<<"\n";
    }
    
    return 0;
}