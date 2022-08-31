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

const int MX = 100005;
const int inf = 1e9+10;
int a[6];
VI b;
int n, nk;
PI notes[600005];
int mx[MX];

bool poss(int diff) {
    REP(i, n) mx[i] = -inf;

    int cc = 1, lt = 0;
    mx[notes[0].S] = notes[0].F;

    for (int rt = 1; rt < nk; rt++) {
        int cs = notes[rt].S;
        int cn = notes[rt].F;
        if (mx[cs] < notes[lt].F)
            ++cc;
        mx[cs] = cn;
        while (cn - notes[lt].F > diff) {
            if (mx[notes[lt].S] == notes[lt].F)
                --cc;
            ++lt;
        }
        if (cc == n)
            return true;
    }
    return false;
}

int solve() {
    if (n == 1) return 0;
    nk = 0;
    REP(i, 6) REP(j, n) 
        notes[nk++] = MP(b[j] - a[i], j);
    sort(notes, notes+nk);

    int lo = 0, hi = inf;
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (poss(mid)) hi = mid;
        else lo = mid + 1;
        // cout << lo << ", " << hi << endl;
    }
    return lo;
}

int main() {
    setIO();
    REP(i, 6) {
        cin>>a[i];
    }
    cin>>n;
    REP(i, n) {
        int x; cin>>x;
        b.PB(x);
    }
    sort(ALL(b));
    b.erase(unique(ALL(b)), b.end());
    n=b.size();
    cout<<solve()<<"\n";
    return 0;
}