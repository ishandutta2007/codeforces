#include <bits/stdc++.h>
using namespace std;

const int M = (int)2e5 + 500, N = (int)2e5 + 50;
int cumu[2][N];
typedef long long ll;

struct Trie{
    static const int B = 26;

    int next[M][B], fail[M], end[M];
    int root, L;
    int dp[M];
    int newnode(){
        for(int i = 0; i < B; i++) next[L][i] = -1;
        dp[L] = -1;
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
            if(next[now][buf[i]-'a'] == -1) next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
        }
        end[now] ++;
    }

    int get(int v) {
        if(dp[v] != -1) return dp[v];
        if(v == 0) return dp[v] = 0;
        return dp[v] = end[v] + get(fail[v]);
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

    void query(const string &buf, int id){
        int len = buf.length();
        int now = root;
        int res = 0;
        for(int i = 0; i < len; i++){
            now = next[now][buf[i]-'a'];
            cumu[id][i] = get(now);
        }
    }
};

Trie Aho;
string str;
int n;
string s[N];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> str;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];

    for(int swapped = 0; swapped < 2; swapped++) {
        if(swapped) {
            reverse(str.begin(), str.end());
            for(int i = 0; i < n; i++) reverse(s[i].begin(), s[i].end());
        }
        Aho.init();
        for(int i = 0; i < n; i++) Aho.insert(s[i]);
        Aho.build();
        Aho.query(str, swapped);
    }
    ll res = 0;
    int len = str.length();
    for(int i = 0; i < len - 1; i++) {
        res += 1LL * cumu[0][i] * cumu[1][len - 2 - i];
    }
    cout << res << endl;

}