#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e6 + 500;

struct Trie{
    const static int B = 26;

    int next[M][B], fail[M], end[M];
    int dep[M];
    int root, L;
    int newnode(){
        for(int i = 0; i < B; i++) next[L][i] = -1;
        end[L++] = 0;
        return L - 1;
    }
    void init(){
        L = 0;
        root = newnode();
        dep[root] = 0;
    }
    void insert(const string &buf){
        int len = buf.length();
        int now = root;
        int d = 0;
        for(int i = 0; i < len; i++){
            if(next[now][buf[i]-'a'] == -1) next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
            dep[now] = ++d;
        }
        end[now]++;
    }
    void build(){
        queue<int> Q;
        fail[root] = root;
        for(int i = 0; i < B; i++){
            if(next[root][i] == -1) next[root][i] = root;
            else{
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        }
        while(!Q.empty()){
            int now = Q.front();
            Q.pop();
            for(int i = 0; i < B; i++){
                if(next[now][i] == -1) next[now][i] = next[fail[now]][i];
                else{
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
            }
        }
    }
};

Trie Aho;

vector<int> G[M];
bool vis[M];
int in[M];
int dp[M][2];

void dfs(int v) {
    vis[v] = true;
    dp[v][0] = 0;
    dp[v][1] = 1;
    for(int nxt : G[v]) {
        assert(!vis[nxt]);
        dfs(nxt);
        dp[v][0] += max(dp[nxt][0], dp[nxt][1]);
        dp[v][1] += dp[nxt][0];
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        Aho.init();
        int n;
        string s;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> s;
            Aho.insert(s);
        }
        Aho.build();
        for(int i = 0; i < Aho.L; i++) G[i].clear();
        fill(in, in + Aho.L, 0);
        for(int i = 1; i < Aho.L; i++) {
            int u = i, v = Aho.fail[u];
            if(Aho.dep[v] + 1 == Aho.dep[u] && v != 0) {
                G[v].push_back(u);
                in[u]++;
            }
        }
        fill(vis, vis + Aho.L, false);
        int res = 0;
        for(int i = 1; i < Aho.L; i++) {
            if(in[i] == 0) {
                dfs(i);
                res += max(dp[i][0], dp[i][1]);
            }
        }
        cout << res << "\n";
    }

}