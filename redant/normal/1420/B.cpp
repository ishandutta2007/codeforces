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

const int SZ = 200005;
int n, m;
int a[SZ];

LL solve() {
    map<int, int> m;
    REP(i, n) {
        int x = a[i];
        int b = 0, msb = 0;
        while (x > 0) {
            if (x&1) msb = b;
            x >>= 1;
            b++;
        }
        m[msb]++;
    }
    LL r = 0;
    REP(i, 31) {
        LL k = m[i];
        if (k>0) {
            // cout << i << ", " << k << endl;
        }
        r += (k*(k-1))/2;
    }
    return r;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i];
        }
        
        cout<<(solve())<<"\n";
    }
    
    return 0;
}