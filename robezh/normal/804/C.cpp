#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

const int N = (int)3e5 + 50;

int n, m;
int root = -1;
int depth[N], sst[N];
int par[N];
int color[N];
vector<int> S[N];
vector<int> G[N];

struct Tree {
    int n;
    int dat[N * 4];

    void update(int pos, int x, int l, int r){
        int mid = (l + r) / 2;
        if(l == r) {
            dat[x] = !dat[x];
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid);
        else update(pos, rson(x), mid+1, r);
        dat[x] = dat[lson(x)] + dat[rson(x)];
    }

    int find(int x, int l, int r) {
        int mid = (l + r) / 2;
        if(l == r) return l;
        if(dat[lson(x)] != mid - l + 1) return find(lson(x), l, mid);
        else find(rson(x), mid + 1, r);
    }

    void update(int pos) {
        update(pos, 0, 0, n-1);
    }
    int find() {
        return find(0, 0, n-1);
    }
} tree;


void dfs(int v, int p, int d) {
    par[v] = p;
    depth[v] = d;
    for(int nxt : G[v]) if(nxt != p) dfs(nxt, v, d + 1);
}

void assign_color(int v) {
    for(int x : S[v]) if(color[x] != -1) tree.update(color[x]);
    for(int x : S[v]) if(color[x] == -1) color[x] = tree.find(), tree.update(color[x]);
    for(int x : S[v]) tree.update(color[x]);
    for(int nxt : G[v]) if(nxt != par[v]) assign_color(nxt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        while(k--) {
            int a; cin >> a; a--;
            S[i].push_back(a);
        }
        if((root == -1 && !S[i].empty()) || S[i].size() > S[root].size()) root = i;
        sort(S[i].begin(), S[i].end());
    }
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if(root != -1) {
        fill(sst, sst + N, -1);
        dfs(root, -1, 0);
        for(int i = 0; i < n; i++){
            for(const int &x : S[i]) if(sst[x] == -1 || depth[i] < depth[sst[x]]) sst[x] = i;
        }
        tree.n = S[root].size();
        memset(color, -1, sizeof(color));
        assign_color(root);
    }

    if(root != -1) cout << tree.n << endl;
    else cout << 1 << endl;
    for(int i = 0; i < m; i++) {
        if(color[i] == -1) color[i] = 0;
        cout << color[i] + 1 << " ";
    }

}