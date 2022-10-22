#include <bits/stdc++.h>
using namespace std;

const int M = (int)4e5 + 500, N = M;

struct edge {
    int to, c;
};

int id[N], cnt[N];
int res[N];
vector<edge> G[N];
vector<int> qrs[N];

struct Trie{
    static const int B = 26;

    int next[M][B], fail[M], end[M], fail_to[M];
    int root, L;
    int newnode(){
        for(int i = 0; i < B; i++) next[L][i] = -1;
        end[L++] = -1;
        return L - 1;
    }
    void init(){
        L = 0;
        root = newnode();
    }
    void insert(const string &buf, int idx){
        int len = buf.length();
        int now = root;
        for(int i = 0; i < len; i++){
            if(next[now][buf[i]-'a'] == -1) next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
        }
        end[now] = 1;
        id[idx] = now;
    }
    void build(){
        memset(fail_to, -1, sizeof(fail_to));

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
    void add(int temp, int val){
        while(temp != 0){
            cnt[temp] += val;
            temp = get_fail_out(temp);
        }
    }
    int get_fail_out(int idx) {
        if(idx == 0) return 0;
        if(fail_to[idx] != -1) return fail_to[idx];
        return fail_to[idx] = (end[fail[idx]] != -1 ? fail[idx] : get_fail_out(fail[idx]));
    }


};

Trie Aho;


void dfs(int v, int t_v) {
    Aho.add(t_v, 1);
    for(int idx : qrs[v]) res[idx] = cnt[id[idx]];
    for(auto e : G[v]) {
        dfs(e.to, Aho.next[t_v][e.c]);
    }
    Aho.add(t_v, -1);
}   
int n, m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        int tp, from = 0;
        char c;
        cin >> tp;
        if(tp == 2) cin >> from;
        cin >> c;
        G[from].push_back({i, (c - 'a')});
    }
    Aho.init();
    cin >> m;
    for(int i = 0; i < m; i++){
        int j; string str;
        cin >> j >> str;
        Aho.insert(str, i);
        qrs[j].push_back(i);
    }
    Aho.build();
    dfs(0, 0);
    for(int i = 0; i < m; i++) cout << res[i] << "\n";

}