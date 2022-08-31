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
int n;
int x[MX], y[MX];

LL manh(PI a, PI b) {
    // cout << a.F << ", " << a.S << "\t";
    // cout << b.F << ", " << b.S << "\n";
    return abs(a.F - b.F) + abs(a.S - b.S);
}

LL solve() {
    map<int, vector<PI> > points;
    REP(i, n) {
        int k = max(x[i], y[i]);
        points[k].PB(MP(x[i], -y[i]));
    }
    LL r[2] = {0}, nr[2];
    PI cur[2] = {MP(0, 0), MP(0, 0)};
    PI nxt[2] = {MP(0, 0), MP(0, 0)};
    for (auto p : points) {
        auto ps = p.second;
        sort(ALL(ps));
        // TRAV(x, ps) cout << x.F << ", " << x.S << "   ";
        // cout << endl;
        nxt[0] = ps.front();
        nxt[1] = ps.back();
        REP(i, 2) {
            nr[i] = 1e18;
            nr[i] = min(nr[i], r[0] + manh(nxt[i], cur[0]));
            nr[i] = min(nr[i], r[1] + manh(nxt[i], cur[1]));
        }
        LL k = manh(nxt[0], nxt[1]);
        // cout << " >>>> " << nr[0] << " & " << nr[1] << " : " << k << endl;
        r[0] = nr[1] + k;
        r[1] = nr[0] + k;
        // cout << " >>>> " << r[0] << " & " << r[1] << endl;
        cur[0] = nxt[0];
        cur[1] = nxt[1];
    }
    return min(r[0], r[1]); 
}

int main() {
    setIO();
    int t=1; //  cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>x[i]>>y[i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}