#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

typedef long long ll;
typedef pair<int, int> P;
const int N = (int)3e5 + 500, mod = (int)1e9 + 7, INF = (int)1e9;


int n;
int a[N], b[N];
int dis[N];
set<int> S;
pii pv[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 1, n + 1) cin >> a[i];
    rep(i, 1, n + 1) cin >> b[i];
    rep(i, 0, n + 1) S.insert(i);
//    tree.init_dat(0, 0, n);
    queue<int> que;
    fill(dis, dis + N, INF);
    que.push(n);

    while(!que.empty()) {
        int v = que.front(); que.pop();
        int d = dis[v];
        int l = v - a[v], r = v;
        auto it = S.lower_bound(l);
        while(it != S.end() && *it <= r) {
            int nxt = *it;
            if(dis[nxt + b[nxt]] == INF) {
                dis[nxt + b[nxt]] = d + 1;
                pv[nxt + b[nxt]] = {v, nxt};
                que.push(nxt + b[nxt]);
            }
            it = S.erase(it);
        }
    }
    int cur = 0;
    if(dis[0] == INF) {
        cout << -1 << endl;
        return 0;
    }
    vi res;
    while(cur != n) {
        res.push_back(pv[cur].second);
        cur = pv[cur].first;
    }

    cout << res.size() << "\n";
    reverse(all(res));
    for (int x : res) cout << x << " ";
    cout << '\n';


}