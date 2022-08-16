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

const int MX = 8;
int n, m, r;
int a[MX];
vector<int> g[MX];
int vis[MX][MX], vn = 0;

void go(int u) {
    if (u == n + 1) {
        ++vn;
        int cr = 0;
        REP(i, n) {
            int x = a[i+1];
            TRAV(j, g[i+1]) {
                int y = a[j];
                if (vis[x][y] != vn) {
                    cr++;
                    vis[x][y] = vis[y][x] = vn;
                }
            }
        }
        tmax(r, cr);
        return;
    }
    REP(i, 6) {
        a[u] = i + 1;
        go(u + 1);
    }
}

int solve() {
    r = 0;
    go(1);
    return r; 
}

int main() {
    setIO();
    cin>>n>>m;
    REP(i, m) {
        int a, b; cin >> a >> b;
        g[a].PB(b);
    }
    cout<<solve()<<"\n";
    return 0;
}