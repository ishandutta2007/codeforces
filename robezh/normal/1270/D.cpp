#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int N = 505;

struct edge {
    int to, c;
};

int n, k;
vector<edge> G[N];
int cnt[2];
int vis[N];

P ask(vector<int> x) {
    cout << "? ";
    for(int i : x) cout << i + 1 << " ";
    cout << endl;
    fflush(stdout);
    P res;
    cin >> res.first >> res.second;
    return res;
}

void answer(int x) {
    cout << "! " << x << "\n";
    fflush(stdout);
    exit(0);
}

void add(int u, int v, int c) {
//    cout << "adding " << u + 1 << ", " << v + 1 << ", " << c << endl;
    G[u].push_back({v, c});
    G[v].push_back({u, c});
}

vector<int> cur;

void dfs(int v, int c) {
    vis[v] = c;
    for(auto e : G[v]) {
        if(vis[e.to] != -1) {
            assert(vis[e.to] == (e.c ^ c));
            continue;
        }
        dfs(e.to, c ^ e.c);
    }
}

int main() {
    cin >> n >> k;
    if(k == 1) {
        answer(1);
    }
    for(int i = 0; i < k; i++) cur.push_back(i);
    auto p = ask(cur);
    int pi = p.first - 1, pval = p.second;
    int s = (pi == 0 ? 1 : 0);
    for(int i = k; i < n; i++) {
        cur[s] = i;
        p = ask(cur);
        add(s, i, p.second != pval);
        cur[s] = s;
    }
    for(int i = 0; i < k; i++) {
        if(pi == i || s == i) continue;
        cur[i] = n - 1;
        p = ask(cur);
        add(i, n - 1, p.second != pval);
        cur[i] = i;
    }
    fill(vis, vis + n, -1);
    cur[pi] = n - 1;
    p = ask(cur);
    if(p.second < pval) {
        dfs(p.first - 1, 0);
    }
    else dfs(p.first - 1, 1);
    cnt[0] = 0;
    assert(vis[pi] == -1);
    for(int i = 0; i < k; i++) {
        if(vis[i] == 0) cnt[0]++;
    }

//    cout << "cnt0 is " << cnt[0] << endl;
    answer(cnt[0] + 1);
}