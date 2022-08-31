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

LL P, Q;
LL p, q, r;

bool upd(LL pr) {
    // cout << "Prime " << pr << endl;
    int fp = 0, fq = 0;
    while(q > 1 && q % pr == 0) { ++fq; q /= pr; }
    if (fq == 0)
        return false;
    while(p > 1 && p % pr == 0) { ++fp; p /= pr; }
    // cout << pr << " " << fq << " " << fp << endl;
    if (fq > fp) return true;
    LL rr = 1;
    REP(i, fp-fq+1) rr *= pr;
    r = min(r, rr);
    return false;
}

LL solve() {
    if (P < Q) return P;
    r = P;
    p = P; q = Q;
    if (upd(2)) return P;
    for (LL pr = 3; pr * pr <= Q; pr += 2)
        if (upd(pr)) return P;
    if (q > 1 && upd(q)) return P;
    return P / r;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>P>>Q;
        cout<<solve()<<"\n";
    }
    
    return 0;
}