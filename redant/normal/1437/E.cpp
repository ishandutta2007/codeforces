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

const int INF = 1e9+10;
const int MX = 500005;
int a[MX], b[MX];
int n, k;

int solve(int li, int ri) {
    if (a[li] > a[ri]) return -INF;
    vector<int> lisEnd(1, a[li]);
    for (int i = li + 1; i < ri; i++) {
        if (a[i] < a[li] || a[i] > a[ri])
            continue;
        auto it  = upper_bound(ALL(lisEnd), a[i]);
        if (it == lisEnd.end())
            lisEnd.PB(a[i]);
        else *it = a[i];
    }
    return SZ(lisEnd) - 1;
}

int solve() {
    REP(i, n) a[i+1] -= i;
    int lis = 0;
    REP(i, k+1) {
        lis += solve(b[i], b[i+1]);
        if (lis < 0) return -1;
    }
    return n - k -  lis;
}

int main() {
    setIO();
    cin>>n>>k;
    REP(i, n) cin>>a[i+1];
    REP(i, k) cin>>b[i+1];
    a[0] = -INF; a[n+1] = INF;
    b[0] = 0; b[k+1] = n+1;
    cout<<solve()<<"\n";    
    return 0;
}