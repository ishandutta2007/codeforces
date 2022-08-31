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

const int MX = 200005;
PI res[MX];
int n;

LL solve() {
    sort(res, res+n+1);
    LL sum = 0;
    LL ans = res[n].F;

    for (int i = n; i > 0; ) {
        LL csum = 0;
        int j = i;
        while (j > 0 && res[i].F == res[j].F) {
            csum += res[j].S;
            --j;
        }
        i = j;
        sum += csum;
        ans = min(ans, max(1ll*res[i].F, sum));
    }
    ans = min(ans, sum);
    return ans;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        res[0] = {0, 0};
        REP(i, n) {
            cin>>res[i+1].F;
        }
        REP(i, n) {
            cin>>res[i+1].S;
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}