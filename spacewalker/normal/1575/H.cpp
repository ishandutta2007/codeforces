#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define MAXN 505
#define INF 1e9
#define rep(i,x,y) for (i = (x); i < (y); i++)

struct Trie {
    int root, rcnt;
    int next[MAXN][2], fail[MAXN], end[MAXN];
    //by default every guy is false
    bool isnext[MAXN][2];
    int leaf = -1;
    int newnode() {
        for (int i = 0; i < 2; i++) next[rcnt][i] = -1;
        end[rcnt++] = 0;
        return rcnt - 1;
    }

    void init() {
        rcnt = 0;
        root = newnode();
    }

    void insert(string buf) {
        int len = (int)(buf.size());
        int now = root;
        for (int i = 0; i < len; i++) {
            if (next[now][buf[i] - '0'] == -1) {
                next[now][buf[i] - '0'] = newnode();
            }
            isnext[now][buf[i] - '0'] = true;
            now = next[now][buf[i] - '0'];
        }
        leaf = now;
        end[now]++;
    }

    void build() {
        queue<int> que;
        fail[root] = root;
        for (int i = 0; i < 2; i++) {
            if (next[root][i] == -1) {
                next[root][i] = root;
            } else {
                fail[next[root][i]] = root;
                que.push(next[root][i]);
            }
        }

        while (que.size()) {
            int now = que.front();
            end[now] += end[fail[now]];
            que.pop();
            for (int i = 0; i < 2; i++) {
                if (next[now][i] == -1) {
                    next[now][i] = next[fail[now]][i];
                } else {
                    fail[next[now][i]] = next[fail[now]][i];
                    que.push(next[now][i]);
                }
            }
        }
    }
} t;

int n, m, dp[505][505][505];
string s, pat;
vector<int> conv;
int memo(int u, int p, int occur) {
    if (u == n) {
        if (!occur) return 0;
        return INF;
    }
    if (dp[u][p][occur] != -1) return dp[u][p][occur];
    int &ans = dp[u][p][occur];
    ans = INF;
    //try to not change
    int np = t.next[p][conv[u]];
    int noccur = occur;
    if (t.leaf == np) noccur--;
    //no change made
    if (noccur >= 0) {
        int val = memo(u + 1, np, noccur);
        if (val != INF) ans = min(ans, val);
    }

    //try to change this vertex now
    np = t.next[p][!conv[u]];
    noccur = occur;
    if (t.leaf == np) noccur--;
    if (noccur >= 0) {
        int val = memo(u + 1, np, noccur);
        if (val != INF) ans = min(ans, val + 1);
    }
    return ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    t.init();
    cin >> s >> pat;
    t.insert(pat);
    t.build();
    //initialise the base case for now
    for (char &c : s) conv.push_back(c - '0');
    //for (auto &i : conv) cout << i;
    //cout << '\n';
    int i;
    rep(i,0,n-m+2) {
        int ans = memo(0, 0, i);
        if (ans == INF) {
            cout << -1;
        } else cout << ans;
        cout << ' ';
    }
    cout << '\n';
}