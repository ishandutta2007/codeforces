#include <bits/stdc++.h>
using namespace std;

const int M = (int)105, N = 11, mod = 1000000009;

int ch[256];

struct Trie{
    static const int B = 4;

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
    }
    void insert(const string &buf){
        int len = buf.length();
        int now = root;
        for(int i = 0; i < len; i++){
            if(next[now][ch[buf[i]]] == -1) next[now][ch[buf[i]]] = newnode();
            now = next[now][ch[buf[i]]];
        }
        end[now] ++;
        dep[now] = buf.length();
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
            if(end[fail[now]]) {
                end[now]++;
                dep[now] = max(dep[now], dep[fail[now]]);
            }
        }
    }
};

Trie Aho;
int n, m;
int dp[1005][105][11];
string str[N];

void add(int &to, int val) {
    to += val;
    to %= mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    ch['A'] = 0, ch['G'] = 1;
    ch['C'] = 2, ch['T'] = 3;
    Aho.init();
    for(int i = 0; i < m; i++) {
        cin >> str[i];
        Aho.insert(str[i]);
    }
    Aho.build();

    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int s = 0; s < Aho.L; s++) {
            for(int len = 0; len <= 10; len++) {
                for(int c = 0; c < 4; c++) {
                    int nxt_s = Aho.next[s][c];
                    if(Aho.end[nxt_s] && Aho.dep[nxt_s] >= len + 1) add(dp[i+1][nxt_s][0], dp[i][s][len]);
                    else if(len + 1 <= 10) add(dp[i+1][nxt_s][len+1], dp[i][s][len]);
                }
            }
        }
    }
    int res = 0;
    for(int s = 0; s < Aho.L; s++) add(res, dp[n][s][0]);
    cout << res << "\n";
}