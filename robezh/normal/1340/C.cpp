#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define what_is(x) cerr << #x << " is " << x << endl;

typedef long long ll;

const ll INF = (ll)1e18;
const int N = (int)1e4 + 50, G = 1005;

int n, m;
int d[N];
int g, r;
ll dis[N][G];

struct P {
    ll cost;
    int i, j;

    bool operator < (const P &p) const {
        return cost < p.cost;
    }

    bool operator > (const P &p) const {
        return cost > p.cost;
    }
};

priority_queue<P, vector<P>, greater<> > pque;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    swap(n, m);
    for(int i = 0; i < n; i++) memset(dis[i], 0x3f, sizeof(dis[i]));

    for(int i = 0; i < n; i++) cin >> d[i];
    sort(d, d + n);
    cin >> g >> r;
    dis[0][0] = 0;
    pque.push({0, 0, 0});
    while(!pque.empty()) {
        P p = pque.top(); pque.pop();
        if(p.cost > dis[p.i][p.j]) continue;
//        cout << p.i << " " << p.j << p.cost << endl;
        if(p.i + 1 < n && d[p.i + 1] - d[p.i] <= g - p.j) {
            int df = d[p.i + 1] - d[p.i];
            int nxti = p.i + 1, nxtj = (p.j + df) % g;
            ll nxtcost = dis[p.i][p.j] + df + (nxti != n - 1 && nxtj == 0 ? r : 0);
            if(dis[nxti][nxtj] > nxtcost) {
                dis[nxti][nxtj] = nxtcost;
                pque.push({nxtcost, nxti, nxtj});
            }
        }
        if(p.i - 1 >= 0 && d[p.i] - d[p.i - 1] <= g - p.j) {
            int df = d[p.i] - d[p.i - 1];
            int nxti = p.i - 1, nxtj = (p.j + df) % g;
            ll nxtcost = dis[p.i][p.j] + df + (nxti != n - 1 && nxtj == 0 ? r : 0);
            if(dis[nxti][nxtj] > nxtcost) {
                dis[nxti][nxtj] = nxtcost;
                pque.push({nxtcost, nxti, nxtj});
            }
        }
    }

    ll res = INF;
    for(int i = 0; i < g; i++) res = min(res, dis[n-1][i]);
    cout << (res == INF ? -1 : res) << endl;
//    cout << (dis[n - 1][0] > INF ? -1 : dis[n-1][0]) << endl;

}