#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int M = (int)1e6 + 50, N = M;

struct BIT {
    int n;
    int bit[N];

    void add(int x, int val) {
        for(int i = x; i < n; i |= i + 1) bit[i] += val;
    }

    ll get(int x) {
        ll res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
        return res;
    }
} bit;
int n, q;
int vidx[N];
int in[N], out[N], tim;
int has[N];

struct Trie{
    static const int B = 26;

    int next[M][B], fail[M], end[M];
    int root, L;
    vi G[N];
    int newnode(){
        for(int i = 0; i < B; i++) next[L][i] = -1;
        end[L++] = 0;
        return L - 1;
    }
    // Please do initalize it !!!
    void init(){
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
//        end[now] ++;
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
        rep(i, 1, L) G[fail[i]].push_back(i);
    }
    void dfs(int v) {
        in[v] = tim++;
        for (int nxt : G[v]) {
            dfs(nxt);
        }
        out[v] = tim - 1;
    }
    ll query(const string &buf){
        int len = buf.length();
        int cur = root;
        ll res = 0;
        for(int i = 0; i < len; i++){
            cur = next[cur][buf[i]-'a'];
//            cout << "add" << in[cur] << " " << bit.get(in[cur]) << endl;
            res += bit.get(in[cur]);
        }
        return res;
    }
} Aho;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Aho.init();
    cin >> q >> n;
    rep(i, 0, n) {
        string s;
        cin >> s;
        vidx[i] = Aho.insert(s);
    }
    Aho.build();
    Aho.dfs(0);
    bit.n = Aho.L;
    rep(i, 0, n) {
        bit.add(in[vidx[i]], 1);
        bit.add(out[vidx[i]] + 1, -1);
        has[i] = 1;
    }

    rep(qid, 0, q) {
        string s;
        cin >> s;
        if(s[0] == '?') {
            cout << Aho.query(s.substr(1)) << '\n';
        } else  {
            int idx = stoi(s.substr(1)) - 1;
            if(s[0] == '+' && !has[idx]) {
                has[idx] = 1;
                bit.add(in[vidx[idx]], 1);
                bit.add(out[vidx[idx]] + 1, -1);
            }
            if(s[0] == '-' && has[idx]) {
                has[idx] = 0;
                bit.add(in[vidx[idx]], -1);
                bit.add(out[vidx[idx]] + 1, 1);
            }
        }
    }



}