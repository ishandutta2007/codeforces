#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

LL n, m, q;
LL a[2], b[2];
LL g;

LL gcd (LL x, LL y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

LL get(LL op, LL k) {
    if (op==1) return (k-1)/(n/g);
    return (k-1)/(m/g);
}

bool solve() {
    cin>>a[0]>>a[1];
    cin>>b[0]>>b[1];
    return get(a[0], a[1]) == get(b[0], b[1]);
}

int main() {
    setIO();
    int t=1; //; cin>>t;
    while(t--) {
        cin>>n>>m>>q;
        g = gcd(n, m);
        REP(i, q)
            cout<<(solve()?"YES":"NO")<<"\n";
    }
    
    return 0;
}