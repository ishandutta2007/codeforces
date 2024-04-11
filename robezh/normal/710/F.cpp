#include <bits/stdc++.h>
using namespace std;

const int LOG = 20, N = (int)3e5 + 50;
char c[N];

void read_s(string &s) {
    s.clear();
    scanf("%s", c);
    int len = strlen(c);
    for(int i = 0; i < len; i++) s.push_back(c[i]);
}


struct Trie{
    const static int B = 26;

    vector<string> strs;
    vector<vector<int>> next;
    vector<int> fail, end;

    int root, L;
    Trie(const vector<string> &strs){
        int S = 0;
        for(const string &str : strs) S += str.length();
        L = 0;
        S += 1;
        this->strs = strs;
        next.resize(S, vector<int>(B, 0));
        fail.resize(S, 0);
        end.resize(S, 0);
        root = newnode();
        for(const string &s : strs) insert(s);
        build();
    }
    int newnode(){
        for(int i = 0; i < B; i++) next[L][i] = -1;
        end[L++] = 0;
        return L - 1;
    }
//    void init(){
//        L = 0;
//        root = newnode();
//    }
    void insert(const string &buf){
        int len = buf.length();
        int now = root;
        for(int i = 0; i < len; i++){
            if(next[now][buf[i]-'a'] == -1) next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
        }
        end[now] ++;
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
                    end[next[now][i]] += end[fail[next[now][i]]];
                }
            }
        }
    }
    int query(const string &buf){
        int len = buf.length();
        int now = root;
        int res = 0;
        for(int i = 0; i < len; i++){
            now = next[now][buf[i]-'a'];
            res += end[now];
        }
        return res;
    }
};

int q;
vector<Trie> add[LOG], del[LOG];

void merge(Trie &from, Trie &to) {
    vector<string> strs;
    strs.insert(strs.end(), from.strs.begin(), from.strs.end());
    strs.insert(strs.end(), to.strs.begin(), to.strs.end());
    to = Trie(strs);
}

int main(){
    scanf("%d", &q);
    while(q--) {
        int k; string s;
        scanf("%d", &k);
        read_s(s);
        if(k == 3) {
            int res = 0;
            for(int i = 0; i < LOG; i++) {
                if(!add[i].empty()) res += add[i][0].query(s);
                if(!del[i].empty()) res -= del[i][0].query(s);
            }
            printf("%d\n", res);
            fflush(stdout);
        }
        else {
            Trie cur = Trie({s});
            for(int i = 0; i < LOG; i++) {
                vector<Trie> &to = (k == 1 ? add[i] : del[i]);
                if(to.empty()) {
                    to.push_back(cur);
                    break;
                }
                else {
                    merge(to[0], cur);
                    to.pop_back();
                }
            }
        }
    }


}