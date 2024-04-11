#include <bits/stdc++.h>
using namespace std;

using namespace std;

const int N = (int)2e5 + 50;
typedef pair<int, int> P;

//Need to initialize before every test case!

int n;
int zeros[N];

struct PSGT {
    int ncnt = 1;

    struct node{
        int ls, rs, sum;
    } ns[N * 2 * 30];

    int newnode(int val){
        ns[ncnt].ls = ns[ncnt].rs = 0;
        ns[ncnt].sum = val;
        return ncnt++;
    }

    int newnode(int ls, int rs){
        ns[ncnt].ls = ls;
        ns[ncnt].rs = rs;
        ns[ncnt].sum = (ls ? ns[ls].sum : 0) + (rs ? ns[rs].sum : 0);
        return ncnt++;
    }


    int build(int a[], int tl = 0, int tr = n-1){
        if(tl == tr) return newnode(a[tl]);
        int mid = (tl + tr) / 2;
        return newnode(build(a, tl, mid), build(a, mid + 1, tr));
    }

    int get_sum(int v, int l, int r, int tl = 0, int tr = n-1){
        if(tr < l || tl > r) return 0;
        if(l <= tl && tr <= r) return ns[v].sum;
        int tm = (tl + tr) / 2;

        return get_sum(ns[v].ls, l, r, tl, tm)
               + get_sum(ns[v].rs, l, r, tm + 1, tr);
    }

    int update(int v, int pos, int tl = 0, int tr = n-1){
        if(tl == tr) return newnode(ns[v].sum + 1);
        int tm = (tl + tr) / 2;
        if(pos <= tm) return newnode(update(ns[v].ls, pos, tl, tm), ns[v].rs);
        else return newnode(ns[v].ls, update(ns[v].rs, pos, tm+1, tr));
    }

} psgt;


struct Trie{
    const static int M = (int)2e5 + 50;
    static const int B = 26;

    int next[M][B], fail[M], end[M];
    vector<int> have[M];
    int root, L;
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
    int insert(const string &buf, int idx){
        int len = buf.length();
        int now = root;
        for(int i = 0; i < len; i++){
            if(next[now][buf[i]-'a'] == -1) next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
            have[now].push_back(idx);
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
} Aho;

int id[N];
int q;
int vs[N];
int in[N], out[N], eul[N], tim = 0;
vector<int> G[N];

void dfs(int v) {
    tim++;
    vs[tim] = vs[tim - 1];
    for(int x : Aho.have[v]) vs[tim] = psgt.update(vs[tim], x, 0, n - 1);
    in[v] = tim;
    eul[tim] = v;

    for(int nxt : G[v]) dfs(nxt);
    out[v] = tim;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    Aho.init();
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        id[i] = Aho.insert(s, i);
    }
    Aho.build();
    for(int i = 1; i < Aho.L; i++) G[Aho.fail[i]].push_back(i);

    vs[0] = psgt.build(zeros, 0, n - 1);
    dfs(0);
    while(q--) {
        int l, r, k; cin >> l >> r >> k;
        l--, r--, k--;
        int v = id[k];
        cout << psgt.get_sum(vs[out[v]], l, r, 0, n - 1) - psgt.get_sum(vs[in[v] - 1], l, r, 0, n - 1) << '\n';
    }



}