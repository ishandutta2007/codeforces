#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 50, B = 26;

int n;
int p[N];
string s[N];
string t;
int f[N], f_nxt[N][B];
int id[N], len;
vector<int> G[N];
ll res = 0;

struct Trie {
    int nxt[N][B];
    int vol[N];
    int cnt;

    void init() {
        memset(nxt, -1, sizeof(nxt));
        fill(vol, vol + N, 0);
        cnt = 1;
    }

    int add(string &s, int from) {
        int cur = from;
        for(char c : s) {
            int &nx = nxt[cur][c - 'a'];
            if(nx == -1) nx = cnt++;
            cur = nx;
            vol[cur]++;
        }
        return cur;
    }

    void dfs(int v, int cur) {
        if(cur == len) {
            res += vol[v];
        }
        for(int c = 0; c < 26; c++) {
            if(nxt[v][c] != -1) dfs(nxt[v][c], f_nxt[cur][c]);
        }
    }

} trie;


void getnext(){
    int m = t.length();
    f[0] = 0; f[1] = 0;
    for(int i = 1; i < m; i++){
        int j = f[i];
        while(j && t[i] != t[j]) j = f[j];
        f[i+1] = t[i] == t[j] ? j + 1 : 0;
    }
}

void dfs(int v, int cur) {
    for(int nxt : G[v]) {
        dfs(nxt, trie.add(s[nxt], cur));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i < n; i++) {
        cin >> p[i] >> s[i]; p[i]--;
        G[p[i]].push_back(i);
    }
    trie.init();

    id[0] = 0;
    dfs(0, 0);
    cin >> t;
    getnext();
    len = t.length();
    for(int i = 0; i <= len; i++) {
        for(int c = 0; c < 26; c++) {
            f_nxt[i][c] = (i < len && c == (t[i] - 'a') ? i + 1 : f_nxt[f[i]][c]);
//            cout << i << " " << c << " " << f_nxt[i][c] << endl;
        }
    }
    trie.dfs(0, 0);
    cout << res << endl;
}