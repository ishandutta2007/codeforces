#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct state {
    int link, chr, leaf;
    vector<int> to;
    state(int chr) : chr(chr), leaf(0), link(-1), to(vector<int>(26, -1)) {};
};
vector<state> t;

int add_word(string &s) {
    int cur = 0;
    for(auto &c : s) {
        if(t[cur].to[c - 'a'] == -1) {
            t[cur].to[c - 'a'] = t.size();
            t.push_back(state(c - 'a'));
        }
        cur = t[cur].to[c - 'a'];
    }
    t[cur].leaf = 1;
    return cur;
}

void build_aho() {
    queue<int> q;
    q.push(0);
    t[0].link = 0;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(int ch = 0; ch < 26; ch++) {
            if(t[v].to[ch] != -1) {
                t[t[v].to[ch]].link = v == 0 ? 0 : t[t[v].link].to[ch];
                q.push(t[v].to[ch]);
            }
            else
                t[v].to[ch] = v == 0 ? 0 : t[t[v].link].to[ch];
        }
    }
}

const int MAXN = 4e5 + 5;
vector<pair<int, int>> adj[MAXN], qs[MAXN];
vector<int> sons[MAXN];
int ans[MAXN], tin[MAXN], tout[MAXN], curt, BIT[MAXN];

void tour(int s) {
    tin[s] = ++curt;
    for(auto v : sons[s])
        tour(v);
    tout[s] = curt;
}

int upd(int p, int v) {
    for(; p < MAXN; p += (p & -p)) BIT[p] += v;
}

int sum(int p) {
    int res = 0;
    for(; p; p -= (p & -p)) res += BIT[p];
    return res;
}

void dfs(int s, int cur = 0) {
    //cout << "position " << s << " at state " << cur << endl;
    upd(tin[cur], 1);
    for(auto q : qs[s]) {
        int pos = q.first;
        ans[q.second] = sum(tout[pos]) - sum(tin[pos] - 1);
    }
    for(auto e : adj[s])
        dfs(e.first, t[cur].to[e.second]);
    upd(tin[cur], -1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int t, p;
        char c;
        cin >> t;
        if(t == 1)
            p = 0;
        else
            cin >> p;
        cin >> c;
        adj[p].push_back({i, c - 'a'});
    }
    t.push_back(state(-1));
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int pos;
        string s;
        cin >> pos >> s;
        qs[pos].push_back({add_word(s), i});
    }
    build_aho();
    for(int i = 1; i < t.size(); i++) {
        sons[t[i].link].push_back(i);
        //cout << t[i].link << " -> " << i << endl;
    }
    tour(0);
    dfs(0);
    for(int i = 0; i < q; i++)
        cout << ans[i] << '\n';
}