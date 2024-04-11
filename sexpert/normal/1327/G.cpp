#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXST = 1005;
const ll INF = 1e18;
int to[MAXST][14], val[MAXST], link[MAXST], sz;
vector<int> adj[MAXST], masks[14][14];

void add(string &s, int x) {
    int cur = 0;
    for(auto c : s) {
        if(to[cur][c - 'a'] == -1)
            to[cur][c - 'a'] = ++sz;
        cur = to[cur][c - 'a'];
    }
    val[cur] += x;
}

void build_aho() {
    queue<int> q;
    q.push(0);
    while(q.size()) {
        int v = q.front(); q.pop();
        for(int ch = 0; ch < 14; ch++) {
            if(to[v][ch] != -1) {
                link[to[v][ch]] = v == 0 ? 0 : to[link[v]][ch];
                adj[link[to[v][ch]]].push_back(to[v][ch]);
                q.push(to[v][ch]);
            }
            else
                to[v][ch] = v == 0 ? 0 : to[link[v]][ch];
        }
    }
}

void dfs(int s, int cur = 0) {
    val[s] += cur;
    cur = val[s];
    for(auto v : adj[s])
        dfs(v, cur);
}

pair<int, ll> walk(int st, string &s) {
    ll res = 0;
    for(auto c : s) {
        st = to[st][c - 'a'];
        res += val[st];
    }
    return {st, res};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(to, -1, sizeof to);
    int k;
    cin >> k;
    while(k--) {
        string s;
        int x;
        cin >> s >> x;
        add(s, x);
    }
    string s;
    cin >> s;
    build_aho();
    dfs(0);
    //for(int i = 0; i <= sz; i++)
    //    cout << link[i] << " " << val[i] << '\n';
    vector<vector<ll>> dp(sz + 1, vector<ll>(1 << 14, -INF));
    dp[0][0] = 0;
    vector<string> pieces;
    s += '?';
    string cur;
    for(auto c : s) {
        if(c == '?') {
            pieces.push_back(cur);
            cur = "";
        }
        else
            cur += c;
    }
    for(int ch = 0; ch < 14; ch++) {
        for(int ms = 0; ms < (1 << 14); ms++) {
            if(ms & (1 << ch))
                continue;
            masks[ch][__builtin_popcount(ms)].push_back(ms);
        }
    }
    int ps = 0;
    for(auto t : pieces) {
        //cout << t << endl;
        ps++;
        vector<vector<ll>> ndp(sz + 1, vector<ll>(1 << 14, -INF));
        for(int i = 0; i <= sz; i++) {
            auto dst = walk(i, t);
            for(int ms = 0; ms < (1 << 14); ms++) {
                //if(i == 0 && ms == 0)
                //    cout << dst.first << " " << dp[i][ms] + dst.second << endl;
                ndp[dst.first][ms] = max(ndp[dst.first][ms], dp[i][ms] + dst.second);
            }
        }
        dp = ndp;
        //cout << "yay" << endl;
        if(ps < pieces.size()) {
            for(int st = 0; st <= sz; st++) {
                for(int ch = 0; ch < 14; ch++) {
                    for(auto ms : masks[ch][ps - 1]) {
                    //cout << ch << " " << ms << endl;
                        dp[to[st][ch]][ms ^ (1 << ch)] = max(dp[to[st][ch]][ms ^ (1 << ch)], dp[st][ms] + val[to[st][ch]]);
                    }
                }
            }
        }
        //cout << "double yay" << endl;
    }
    ll ans = -INF;
    ps--;
    //cout << ps << endl;
    //cout << dp[3][0] << endl;
    for(int ms = 0; ms < (1 << 14); ms++) {
        if(__builtin_popcount(ms) != ps)
            continue;
        for(int i = 0; i <= sz; i++)
            ans = max(ans, dp[i][ms]);
    }
    cout << ans << '\n';
}