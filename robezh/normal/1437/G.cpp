#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int M = (int)3e5 + 500;

int n, m;


struct Trie{
    static const int B = 26;

    int next[M][B], fail[M], end[M], to[M];
    multiset<int> S[M];
    int val[M];

    int root, L;
    int newnode(){
        for(int i = 0; i < B; i++) next[L][i] = -1;
        end[L++] = 0;
        return L - 1;
    }
    // Please do initalize it !!!
    void init(){
        memset(to, -1, sizeof(to));
        memset(val, -1, sizeof(val));
        L = 0;
        root = newnode();
    }
    int insert(const string &buf){
        int len = buf.length();
        int now = root;
        for(int i = 0; i < len; i++){
            if(next[now][buf[i]-'a'] == -1) next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
        }
        end[now] ++;
        return now;
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
    int query(const string &buf){
        int len = buf.length();
        int now = root;
        int res = 0;
        for(int i = 0; i < len; i++){
            now = next[now][buf[i]-'a'];
            int temp = now;
            while(temp != root){
                res += end[temp];
                end[temp] = 0;
                temp = fail[temp];
            }
        }
        return res;
    }

    int fail_out(int v) {
        if(to[v] != -1) return to[v];
        if(v == 0) return 0;
        if(end[fail[v]]) return to[v] = fail[v];
        return to[v] = fail_out(fail[v]);
    }

    int get_max(int st) {
        int res = -1;
        while(st) {
            res = max(res, val[st]);
            st = fail_out(st);
        }
        return res;
    }
} Aho;

const int N = (int)3e5 + 50;

int loc[N], val[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    Aho.init();
    rep(i, 0, n) {
        string s; cin >> s;
        int pos = Aho.insert(s);
        loc[i] = pos;
        val[i] = 0;
        Aho.S[pos].insert(0);
        Aho.val[pos] = 0;
    }
    Aho.build();
    rep(i, 0, m) {
        int tp; cin >> tp;
        if(tp == 1) {
            int v, x; cin >> v >> x; v--;
            int pos = loc[v];
            Aho.S[pos].erase(Aho.S[pos].find(val[v]));
            val[v] = x;
            Aho.S[pos].insert(val[v]);
            Aho.val[pos] = *Aho.S[pos].rbegin();
        } else {
            string s; cin >> s;
            int cur = 0, res = -1;
            for(char c : s) {
                cur = Aho.next[cur][c - 'a'];
                res = max(res, Aho.get_max(cur));
            }
            cout << res << '\n';
        }
    }
}