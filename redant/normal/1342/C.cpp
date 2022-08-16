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

LL a, b, ab, q;
LL l, r;
LL cb;
LL s[40004];

void pre() {
    ab = a * b;
    memset(s, 0, sizeof s);
    for (int i = b; i < (a*b); i++) {
        s[i] += s[i-1];
        if ((i%a)%b != (i%b)%a)
            s[i]++;
    }
}

LL solve(LL n) {
    LL k = n / ab;
    LL r = k * s[ab-1];
    n %= ab;
    r += s[n];
    return r;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin >> a >> b >> q;
        if (a == b) {
            REP(i, q) {
                cin >> l >> r;
                cout << "0 ";
            }
        } else {
            if (a > b) swap(a, b);
            pre();
            REP(i, q) {
                cin >> l >> r;
                cout<<(solve(r) - solve(l-1))<<" ";
            }
        }
        cout << "\n";
    }
    
    return 0;
}