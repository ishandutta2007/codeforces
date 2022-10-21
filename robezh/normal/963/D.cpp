#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5 + 500, N = M, INF = (int)1e9;

int num[N];
string t[N];
vector<int> pos[N];

struct Trie{
    int next[M][26], fail[M];
    vector<int> end[M];
    bool vis[M];
    int root, L;
    int newnode(){
        for(int i = 0; i < 26; i++) next[L][i] = -1;
        vis[L++] = false;
        return L - 1;
    }
    void init(){
        L = 0;
        root = newnode();
    }
    void insert(const string &buf, int index){
        int len = buf.length();
        int now = root;
        for(int i = 0; i < len; i++){
            if(next[now][buf[i]-'a'] == -1) next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
        }
        end[now].push_back(index);
    }
    void build(){
        queue<int> Q;
        fail[root] = root;
        for(int i = 0; i < 26; i++){
            if(next[root][i] == -1) next[root][i] = root;
            else{
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        }
        while(!Q.empty()){
            int now = Q.front();
            Q.pop();
            for(int i = 0; i < 26; i++){
                if(next[now][i] == -1) next[now][i] = next[fail[now]][i];
                else{
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                    for(int oc : end[fail[next[now][i]]]){
                        end[next[now][i]].push_back(oc);
                    }
                }
            }
        }
    }

    void query(const string &buf){
        int len = buf.length();
        int now = root;
        int res = 0;
        for(int i = 0; i < len; i++){
            now = next[now][buf[i]-'a'];
            for(int ind : end[now]) pos[ind].push_back(i);
        }
    }
};

Trie Aho;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

//    freopen("963.txt", "r", stdin);
//    freopen("963w.txt", "w", stdout);

    Aho.init();

    string s;
    cin >> s;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i] >> t[i];
        Aho.insert(t[i], i);
    }

    Aho.build();
    Aho.query(s);

    for(int i = 0; i < n; i++){
        int res = INF;
        for(int j = 0; j + num[i] <= pos[i].size(); j++){
            res = min(res, pos[i][j+num[i]-1] - pos[i][j] + (int)t[i].length());
        }
        cout << (res == INF ? -1 : res) << "\n";
    }
}