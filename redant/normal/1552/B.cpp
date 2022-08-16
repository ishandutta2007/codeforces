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

const int MX = 500005;
int a[MX][5];
int n;

int solve() {
    VI id(n);
    iota(ALL(id), 0);
    auto cmp = [&](int i, int j) {
        int cnt = 0;
        REP(k, 5) cnt += a[i][k] < a[j][k];
        return cnt > 2;
    };
    sort(ALL(id), cmp);
    bool dom = true;
    REP(i, n-1)
        dom &= cmp(id[0], id[i+1]);
    return dom ? id[0] + 1 : -1;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) REP(j, 5) {
            cin>>a[i][j];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}