#include <bits/stdc++.h>
using namespace std;

const int M = 1005, MK = 17000;
typedef long long ll;
const ll INF = (ll)1e18;

struct Trie {
    static const int B = 14;
    int next[M][B], fail[M];
    ll cost[M];
    int root, L;
    vector<int> G[M];

    int newnode() {
        for(int i = 0; i < B; i++) next[L][i] = -1;
        cost[L++] = 0;
        return L - 1;
    }

    void init() {
        L = 0;
        root = newnode();
    }

    void insert(const string &buf, int c) {
        int len = buf.length();
        int now = root;
        for(int i = 0; i < len; i++) {
            if(next[now][buf[i] - 'a'] == -1) next[now][buf[i] - 'a'] = newnode();
            now = next[now][buf[i] - 'a'];
        }
        cost[now] += c;
    }

    void build() {
        queue<int> Q;
        fail[root] = root;
        for(int i = 0; i < B; i++) {
            if(next[root][i] == -1) next[root][i] = root;
            else {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        }
        while(!Q.empty()) {
            int now = Q.front();
            Q.pop();
            for(int i = 0; i < B; i++) {
                if(next[now][i] == -1) next[now][i] = next[fail[now]][i];
                else {
                    fail[next[now][i]] = next[fail[now]][i];
                    cost[next[now][i]] += cost[fail[next[now][i]]];
                    Q.push(next[now][i]);
                }
            }
        }
        for(int i = 1; i < L; i++) G[fail[i]].push_back(i);
    }

    void dfs(int v, ll c) {
        c += cost[v];
        cost[v] = c;

        for (int nxt : G[v]) {
            dfs(nxt, c);
        }
    }
} Aho;

int k, n;
ll dp[MK][M];
int nxt[14][M];
ll add[14][M];
int loc[14], cnt[MK];
string str;

void umax(ll &to, ll val) {
    if(val > to) to = val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Aho.init();

    cin >> k;
    for(int i = 0; i < k; i++) {
        string str; int c;
        cin >> str >> c;
        Aho.insert(str, c);
    }
    Aho.build();
//    Aho.dfs(0, 0);
    cin >> str;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '?') loc[n++] = i;
    }
    for(int i = 0; i < MK; i++) for(int j = 0; j < M; j++) dp[i][j] = -INF;
    int cur = 0;

    if(n == 0) {
        ll cost = 0; cur = 0;
        for(char c : str) {
            cur = Aho.next[cur][c - 'a'];
            cost += Aho.cost[cur];
        }
        cout << cost << '\n';
        return 0;
    }
    for(int i = 1; i < (1 << 14); i++) cnt[i] = cnt[i / 2] + (i % 2);

    for(int i = 0; i < 14; i++) {
        ll cost = 0; cur = 0;
        for(int j = 0; j <= loc[0]; j++) {
            char c = (j == loc[0] ? (char)(i + 'a') : str[j]);
            cur = Aho.next[cur][c - 'a'];
            cost += Aho.cost[cur];
        }
        dp[(1 << i)][cur] = cost;
    }
    for(int i = 0; i < n; i++) {
        for(int s = 0; s < Aho.L; s++) {
            ll cost = 0; cur = s;
            for(int j = loc[i] + 1; j < (i == n - 1 ? str.length() : loc[i+1]); j++) {
                char c = str[j];
                cur = Aho.next[cur][c - 'a'];
                cost += Aho.cost[cur];
            }
            nxt[i][s] = cur;
            add[i][s] = cost;
        }
    }

    for(int i = 1; i < (1 << 14); i++) {
        if(cnt[i] >= n) continue;
        for(int j = 0; j < Aho.L; j++) {
            if(dp[i][j] == -INF) continue;
//            cout << i << " " << j << " " << dp[i][j] << endl;
            for(int nx = 0; nx < 14; nx++) {
                if((i >> nx) & 1) continue;
                int st = Aho.next[nxt[cnt[i] - 1][j]][nx];
                ll cost = add[cnt[i] - 1][j] + Aho.cost[st];
                umax(dp[i | (1 << nx)][st], dp[i][j] + cost);
            }
        }
    }
    ll res = -INF;
    for(int i = 1; i < (1 << 14); i++) {
        if(cnt[i] == n) {
            for(int j = 0; j < Aho.L; j++) {
                if(dp[i][j] == -INF) continue;
//                cout << i << " " << j << " " << dp[i][j] << endl;


                umax(res, add[cnt[i] - 1][j] + dp[i][j]);

            }
        }
    }
    cout << res << '\n';



}