#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 1005;

int n;
vi G[N];
int dep[N], par[N];
int h0, h1;
int ans[N];


void dfs(int v, int p, int d) {
    dep[v] = d;
    for(int nxt : G[v]) {
        if(nxt != p) dfs(nxt, v, d + 1);
    }
};

//void pre() {
//    h0 =
//    rep(i, 0, n) dfs(h0, )
//}

vi gene(int x, int d) {
    vi res;
    dfs(x, -1, 0);
    rep(i, 0, n) if(dep[i] == d) res.push_back(i);
    return res;
}

pii ask(vi vs) {
    if(vs.empty()) {
        return {-1, N};
    }
    cout << "? " << sz(vs) << ' ';
    for(int x : vs) cout << x + 1 << " ";
    cout << '\n';
    fflush(stdout);
    int a, b; cin >> a >> b; a--;
    if(a < 0) exit(0);
    return {a, b};
}

void answer(int u, int v) {
    cout << "! " << u + 1 << " " << v + 1 << endl;
    fflush(stdout);
    string s;
    cin >> s;
    if(s[0] == 'I') exit(0);
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) G[i].clear();
        rep(i, 0, n - 1) {
            int u, v; cin >> u >> v;
            u--, v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vi vs(n);
        rep(i, 0, n) vs[i] = i;
        pii p = ask(vs);
        int d = p.second, rt = p.first;
        int l = (d + 1) / 2, r = d, mid;
        int ans0 = -1;
        while(l <= r) {
            mid = (l + r) / 2;
            p = ask(gene(rt, mid));
//            cout << rt << " " << mid << " " << p.first << " " << p.second << endl;
            if(p.second == d) {
                l = mid + 1;
                ans0 = p.first;
//                cout << "assigning ans0 = : " << ans0 << endl;
            } else r = mid - 1;
        }
        assert(ans0 != -1);
        int ans1 = ask(gene(ans0, d)).first;
        answer(ans0, ans1);
    }
}