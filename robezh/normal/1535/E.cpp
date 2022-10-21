#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)3e5 + 50, LOGN = 19;


int q;
int a[N], c[N];
int jp[LOGN][N];
int p[N];
bool vis[N];

int find_first(int v) {
    for(int i = LOGN - 1; i >= 0; i--) {
        if(jp[i][v] != -1 && !vis[jp[i][v]]) v = jp[i][v];
    }
    return v;
}

void dig(int v, int x) {
    ll tot_amount = 0, tot_cost = 0;
    while(x) {
        int rt = find_first(v);
        ll take = min(a[rt], x);
        ll cost = take * c[rt];
        a[rt] -= take;
        x -= take;
        if(a[rt] == 0) vis[rt] = true;

        tot_amount += take;
        tot_cost += cost;
        if(rt == v) break;
    }
    cout << tot_amount << " " << tot_cost << '\n';
    fflush(stdout);
}


int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);

    cin >> q >> a[0] >> c[0];
    rep(i, 0, LOGN) jp[i][0] = -1;
    rep(i, 1, q + 1) {
        int tp; cin >> tp;
        if(tp == 1) {
            cin >> p[i] >> a[i] >> c[i];
            jp[0][i] = p[i];
            rep(j, 0, LOGN - 1) {
                int pj = jp[j][i];
                jp[j + 1][i] = (pj == -1 ? -1 : jp[j][pj]);
            }
        } else {
            int v, w;
            cin >> v >> w;
            dig(v, w);
        }
    }
}