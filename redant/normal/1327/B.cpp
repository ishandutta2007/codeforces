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

const int SZ = 100005;
int n;
VI G[SZ];

void solve() {
    vector<bool> taken(n+1, false);
    int gotNone = -1;
    REP(i, n) {
        int gotId = 0;
        REP(j, G[i].size()) {
            if (taken[G[i][j]]) continue;
            gotId = G[i][j];
            break;
        }
        if (gotId) {
            taken[gotId] = true;
        } else {
            gotNone = i + 1;
        }
    }

    if (gotNone == -1) {
        cout << "OPTIMAL" << "\n";
        return;
    }

    REP(i, n)
        if (!taken[i+1]) {
            cout << "IMPROVE" << "\n";
            cout << gotNone << " " << (i+1) << "\n";
            return;
        }
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            int k; cin >> k;
            G[i].clear();
            REP(j, k) {
                int v; cin >> v;
                G[i].PB(v);
            }
        }
        
        solve();
    }
    
    return 0;
}