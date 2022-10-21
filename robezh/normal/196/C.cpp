#include <bits/stdc++.h>
using namespace std;

const int N = 1505;
typedef long long ll;

struct Pt {
    int x, y, i;
} pt[N];

int mx = -1;

bool InUpper(Pt p) {
    return p.y > 0 || (p.y == 0 && p.x > 0);
}
ll CrossProd(Pt A, Pt B) {
    return 1LL * A.x * B.y - 1LL * A.y * B.x;
}
int n;
int ssize[N];
vector<int> G[N];
int res[N];

void dfs(int v, int p) {
    ssize[v] = 1;
    for(int nxt : G[v]) {
        if(nxt != p) {
            dfs(nxt, v);
            ssize[v] += ssize[nxt];
        }
    }
}

void dfs2(int v, int p, int l, int r) {
    mx = -1;
    for(int i = l; i <= r; i++) {
        if(mx == -1 || pt[i].y > pt[mx].y || (pt[i].y == pt[mx].y && pt[i].x < pt[mx].x))
            mx = i;
    }
    res[pt[mx].i] = v;
    swap(pt[l], pt[mx]);
    mx = l;
    sort(pt + l + 1, pt + r + 1, [](const Pt &p1, const Pt &p2) {
        return CrossProd({p1.x - pt[mx].x, p1.y - pt[mx].y}, {p2.x - pt[mx].x, p2.y - pt[mx].y}) < 0;
    });
    int cur = l + 1;
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        dfs2(nxt, v, cur, cur + ssize[nxt] - 1);
        cur += ssize[nxt];
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, -1);
    for(int i = 0; i < n; i++) {
        cin >> pt[i].x >> pt[i].y;
        pt[i].i = i;
    }
    dfs2(0, -1, 0, n - 1);
    for(int i = 0; i < n; i++) cout << res[i] + 1 << " ";
    cout << endl;

}