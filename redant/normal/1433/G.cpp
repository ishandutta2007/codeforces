#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

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

const int inf = 1e9;
int n, m, k;
vector<vector<PI>> G;

int solve() {
    cin >> n >> m >> k;
    
    G.resize(n);
    REP(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        G[u].PB(MP(v, w));
        G[v].PB(MP(u, w));
    }

    vector<VI> D(n);
    REP(s, n) {
        D[s].assign(n, inf);
        D[s][s] = 0;
        priority_queue<PI, vector<PI>, greater<PI>> pq;
        pq.push({0, s});
        vector<bool> vis(n, false);
        while (!pq.empty()) {
            int x = pq.top().S;
            pq.pop();
            if (vis[x]) continue;
            vis[x] = true;
            TRAV(e, G[x])
                if (tmin(D[s][e.F], D[s][x] + e.S)) {
                    pq.push({D[s][e.F], e.F});
                }
        }
    }

    vector<PI> routes(k);
    REP(i, k) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        routes[i] = {x, y};
    }

    int ans = inf;
    
    REP(x, n) 
        for (auto [y, _] : G[x]) if (x < y) {
            int cur = 0;
            for (auto [u, v] : routes) {
                int b = D[u][v];
                tmin(b, D[u][x] + D[y][v]);
                tmin(b, D[u][y] + D[x][v]);
                cur += b;
            }
            tmin(ans, cur);
        }

    return ans;
}

int main() {
    setIO();
    cout << solve() << endl;    
    return 0;
}