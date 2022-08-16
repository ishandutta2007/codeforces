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

const int MX = 4;
int a[MX];
int n = 4;

int solve() {
    VI id(4);
    iota(ALL(id), 0);
    sort(ALL(id), [&](int i, int j) {
        return a[i] < a[j];
    });
    return id[3]/2 != id[2]/2;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        REP(i, n) {
            cin>>a[i];
        }
        cout<<(solve()?"YES":"NO")<<"\n";
    }
    
    return 0;
}