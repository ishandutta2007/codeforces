#include <bits/stdc++.h>
#include <iomanip>
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
PI a[MX];
int n;

class BIT {
    public:
    int n;
    vector<int> tree;
    
    BIT(int _n) {
        n = _n + 1;
        tree.assign(n + 1, 0);
    }
 
    void update(int x, int v) {
        ++x;
        for (; x <= n; x += x&-x)
            tree[x] += v;
    }
 
    int read(int x) {
        ++x;
        int sum = 0;
        for (; x > 0; x -= x&-x)
            sum += tree[x];
        return sum;
    }
};
 

int solve() {
    VPI g(2*n);
    REP(i, n) {
        g[2 * i] = {a[i+1].F, -i-1};
        g[2 * i + 1] = {a[i+1].S, i+1};
    }
    sort(ALL(g));
    int k = 0;
    REP(i, 2*n) {
        if (i == 0 || g[i].F != g[i-1].F)
            ++k;
        g[i].F = k;
        if (g[i].S < 0) a[-g[i].S].F = k;
        else a[g[i].S].S = k;
    }

    // REP(i, n) {
    //     cout << a[i+1].F << ", " << a[i+1].S << endl;
    // }
    // cout << endl;

    BIT bit(k);
    int bc = 0;
    int r = 0;
    int st = 0;
    REP(i, 2*n) {
        if (g[i].S > 0) { // end
            int c = st + bc - bit.read(a[g[i].S].F - 1);
            r = max(c, r);

            --st;
            bit.update(g[i].F, 1);
            ++bc;
        } else { // start
            ++st;
        }
    }
    return n - r;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i+1].F>>a[i+1].S;
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}