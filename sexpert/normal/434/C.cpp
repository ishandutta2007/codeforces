#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct state {
    int link, chr, p, leaf;
    int pval, val;
    vector<int> nxt;
    state(int c = -1, int p = -1) : chr(c), p(p), pval(0), link(-1), val(-1), nxt(vector<int>(20, -1)) {}
};
vector<state> trie;

void add(vector<int> &v, int val) {
    int cur = 0;
    for(auto &x : v) {
        if(trie[cur].nxt[x] == -1) {
            trie[cur].nxt[x] = trie.size();
            trie.push_back(state(x, cur));
        }
        cur = trie[cur].nxt[x];
    }
    trie[cur].pval += val;
}

int link(int v);

int to(int v, int c) {
    if(trie[v].nxt[c] == -1) {
        if(v == 0)
            trie[v].nxt[c] = 0;
        else
            trie[v].nxt[c] = to(link(v), c);
    }
    return trie[v].nxt[c];
}

int link(int v) {
    if(trie[v].link == -1) {
        if(v == 0 || trie[v].p == 0)
            trie[v].link = 0;
        else
            trie[v].link = to(link(trie[v].p), trie[v].chr);
    }
    return trie[v].link;
}

const ll MOD = 1e9 + 7;

int val(int v) {
    if(trie[v].val == -1) {
        if(v == 0)
            trie[v].val = 0;
        else
            trie[v].val = trie[v].pval + val(link(v));
    }
    return trie[v].val;
}

int n, m, k;
vector<int> l, r;

int dp[202][202][505][2], D[202][202][505];

int calc(vector<int> &v, bool baneq = false) {
    for(int i = 0; i < 202; i++)
        for(int j = 0; j < 202; j++)
            for(int k = 0; k < 505; k++)
                dp[i][j][k][0] = dp[i][j][k][1] = D[i][j][k] = 0;

    dp[0][0][0][1] = 1;
    for(int pos = 0; pos < v.size(); pos++) {
        for(int st = 0; st < trie.size(); st++) {
            for(int cval = 0; cval <= k; cval++) {
                for(int chr = 0; chr < m; chr++) {
                    if(pos == 0 && chr == 0)
                        continue;
                    int fwd = trie[st].nxt[chr];
                    int nv = cval + trie[fwd].val;
                    if(nv > k)
                        continue;
                    dp[pos + 1][fwd][nv][0] += dp[pos][st][cval][0];
                    if(dp[pos + 1][fwd][nv][0] >= MOD)
                        dp[pos + 1][fwd][nv][0] -= MOD;
                    if(chr < v[pos]) {
                        dp[pos + 1][fwd][nv][0] += dp[pos][st][cval][1];
                        if(dp[pos + 1][fwd][nv][0] >= MOD)
                            dp[pos + 1][fwd][nv][0] -= MOD;
                    }
                    if(chr == v[pos]) {
                        dp[pos + 1][fwd][nv][1] += dp[pos][st][cval][1];
                        if(dp[pos + 1][fwd][nv][1] >= MOD)
                            dp[pos + 1][fwd][nv][1] -= MOD;
                    }
                }
            }
        }
    }
    ll ans = 0;
    for(int st = 0; st < trie.size(); st++) {
        for(int cval = 0; cval <= k; cval++) {
            ans += dp[v.size()][st][cval][0];
            if(ans >= MOD)
                ans -= MOD;
            if(!baneq) {
                ans += dp[v.size()][st][cval][1];
                if(ans >= MOD)
                    ans -= MOD;
            }
        }
    }
    D[0][0][0] = 1;
    for(int pos = 0; pos < v.size(); pos++) {
        for(int st = 0; st < trie.size(); st++) {
            for(int cval = 0; cval <= k; cval++) {
                for(int chr = 0; chr < m; chr++) {
                    if(pos == 0 && chr == 0)
                        continue;
                    int fwd = trie[st].nxt[chr];
                    int nv = cval + trie[fwd].val;
                    if(nv > k)
                        continue;
                    D[pos + 1][fwd][nv] += D[pos][st][cval];
                    if(D[pos + 1][fwd][nv] >= MOD)
                        D[pos + 1][fwd][nv] -= MOD;
                }
            }
        }
    }
    for(int pos = 1; pos < v.size(); pos++)
        for(int st = 0; st < trie.size(); st++)
            for(int cval = 0; cval <= k; cval++) {
                ans += D[pos][st][cval];
                if(ans >= MOD)
                    ans -= MOD;
            }


    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    trie.push_back(state());
    cin >> n >> m >> k;
    int L, R;
    cin >> L;
    l.resize(L);
    for(int i = 0; i < L; i++)
        cin >> l[i];
    cin >> R;
    r.resize(R);
    for(int i = 0; i < R; i++)
        cin >> r[i];
    while(n--) {
        int len;
        cin >> len;
        vector<int> word(len);
        for(int i = 0; i < len; i++)
            cin >> word[i];
        ll val;
        cin >> val;
        add(word, val);
    }
    for(int i = 0; i < trie.size(); i++) {
        link(i);
        val(i);
        for(int c = 0; c < m; c++)
            to(i, c);
    }
    cout << ((calc(r) - calc(l, true)) % MOD + MOD)%MOD << '\n';
}