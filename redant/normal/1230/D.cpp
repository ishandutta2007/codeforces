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

const int MX = 7005;
LL a[MX], b[MX];
int n;

LL solve() {
    LL r = 0;
    vector<bool> vis(n, false);
    REP(i, n) {
        REP(j, n) if (i != j) {
            if (!((a[i]&~a[j]) || (~a[i]&a[j])))
                vis[i] = vis[j] = true;
        }
        REP(j, n) if (i != j) {
            if (vis[i] && !(~a[i]&a[j]))
                vis[i] = vis[j] = true;
        }
    }
    REP(i, n) if (vis[i]) r += b[i];
    return r;
}

int main() {
    setIO();
    cin>>n;
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];
    cout<<solve()<<"\n";    
    return 0;
}