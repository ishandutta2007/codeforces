#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;

const int N = (int)2e5 + 50;
const int mods[4] = {(int)1e9 + 7, (int)1e9 + 9, (int)1e9 + 21, (int)1e9 + 33};
const int mod = 998244353;
int p = 10;
ll pw[4][N];

struct hs {
    ll val[2];

    hs() { fill(val, val + 2, 0); }

    hs(ll a, ll b, ll c, ll d) {
        val[0] = a, val[1] = b;
    }

    bool operator<(const hs &other) const {
        for (int i = 0; i < 2; i++) if (val[i] != other.val[i]) return val[i] < other.val[i];
        return false;
    }

    bool operator==(const hs &other) const {
        for (int i = 0; i < 2; i++) if (val[i] != other.val[i]) return false;
        return true;
    }

    hs operator + (const hs &other) const{
        hs res;
        for(int i = 0; i < 2; i++) res.val[i] = ( val[i] + other.val[i]) % mods[i];
        return res;
    }

    hs operator - (const hs &other) const{
        hs res;
        for(int i = 0; i < 2; i++) res.val[i] = (val[i] - other.val[i] + mods[i]) % mods[i];
        return res;
    }

    hs operator ^ (const int pwi) const {
        hs res;
        for(int i = 0; i < 2; i++){
            res.val[i] = (val[i] * pw[i][pwi]) % mods[i];
        }
        return res;
    }

    void add(int x, int pwi){
        for(int i = 0; i < 2; i++) {
            val[i] = (val[i] + x * pw[i][pwi]) % mods[i];
            if(val[i] < 0) val[i] += mods[i];
        }
    }
};
typedef pair<hs, int> Pl;

int get_count(vector<Pl> &v, Pl &h) {
    return (int)(upper_bound(v.begin(), v.end(), h) - lower_bound(v.begin(), v.end(), h));
}

int fres = 0, id;

struct Graph {
    int n;
    vector<int> G[N];
    Pl dp[N];

    void init() {
        fres = 0;
        id = -1;
        tcnt = 0;
        mp.clear();
        cin >> n;
        for(int i = 0; i < n; i++) G[i].clear();
        for(int i = 0; i < n - 1; i++) {
            int a, b; cin >> a >> b; a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
    }

    Pl wrap(Pl pl) {
        pl.first.add(1, pl.second);
        pl.first = pl.first ^ 1;
        pl.second += 2;
        return pl;
    }

    Pl merge(Pl p1, Pl p2) {
        return Pl((p1.first ^ p2.second) + p2.first, p1.second + p2.second);
    }

    vector<Pl> pls_all[N], psum_all[N], ssum_all[N];
    Pl dfs(int v, int p) {
        vector<Pl> &pls = pls_all[v];
        pls.clear();
        for(int i = 0 ; i < G[v].size(); i++) {
            int nxt = G[v][i];
            if(nxt != p) {
                pls.push_back(dfs(nxt, v));
            }
        }
        sort(pls.begin(), pls.end());
        Pl res;
        for(Pl pl : pls) res = merge(res, pl);
        return dp[v] = wrap(res);
    }

    Pl get_except(vector<Pl> &psum, vector<Pl> &ssum, int i) {
        Pl res;
        if(i > 0) res = merge(res, psum[i - 1]);
        if(i + 1 < ssum.size()) res = merge(res, ssum[i + 1]);
        return res;
    }

    int tcnt;
    map<Pl, int> mp;

    void add(Pl &h, int val) {
        int &cnt = mp[h];
        tcnt -= cnt > 0;
        cnt += val;
        tcnt += cnt > 0;
    }
    void reroot(int v, int p, Pl up_hs) {
        vector<Pl> &pls = pls_all[v]; pls.clear();
        vector<Pl> &psum = psum_all[v]; psum.clear();
        vector<Pl> &ssum = ssum_all[v]; ssum.clear();

        for(int nxt : G[v]) {
            if(nxt != p) pls.push_back(dp[nxt]);
        }

        if(p != -1) pls.push_back(up_hs);
        sort(pls.begin(), pls.end());
        psum.resize(pls.size());
        ssum.resize(pls.size());
        psum[0] = pls[0];
        for(int i = 1; i < pls.size(); i++) psum[i] = merge(psum[i-1], pls[i]);
        ssum.back() = pls.back();
        for(int i = (int)pls.size() - 2; i >= 0; i--) ssum[i] = merge(pls[i], ssum[i+1]);

        add(dp[v], -1);

        Pl cur_res = wrap(ssum[0]);
        add(cur_res, 1);
//        cout << v + 1 << " " << tcnt << endl;
        if(tcnt > fres) {
            fres = tcnt;
            id = v;
        }
        add(cur_res, -1);

        for(int nxt : G[v]) {
            if(nxt == p) continue;
            auto fir = lower_bound(pls.begin(), pls.end(), dp[nxt]) - pls.begin();
            Pl new_hs = wrap(get_except(psum, ssum, fir));
            add(new_hs, 1);
            reroot(nxt, v, new_hs);
            add(new_hs, -1);
        }

        add(dp[v], 1);
    }


} g;

void solve() {
    g.init();
    if(g.n == 1) {
        cout << "1" << "\n";
        return ;
    }
    g.dfs(0, -1);
    for(int i = 0; i < g.n; i++) g.add(g.dp[i], 1);
//    for(int i = 0; i < g.n; i++) cout << i + 1 << ": " << g.prod[i] << " " << g.dp[i].first.val[0] << endl;
    g.reroot(0, -1, Pl());
    cout << id + 1 <<  "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int t = 0; t < 4; t++){
        pw[t][0] = 1;
        for(int i = 1; i < N; i++) pw[t][i] = pw[t][i-1] * p % mods[t];
    }
    solve();


}