#include <bits/stdc++.h>
using namespace std;
#define inf 1000000007
struct dat{
    int x, hei;
    dat(int x = 0, int hei = 0):x(x), hei(hei){}
};

bool operator < (dat a, dat b) {
    if(a.hei != b.hei) return a.hei < b.hei;
    return a.x < b.x;
}

priority_queue<dat> q;
#define N 501000
int h[N], s[N];
vector<int> v[N];
vector<int> in[N][2];
int A[N], pa[N];
int Mi[N], Mi1[N];
typedef pair<int, int> pi;
set<int> S, S1;
set<int> :: iterator it;
void DFS(int x, int p) {
    for(int i = 0; i < v[x].size(); i ++) {
        int y = v[x][i];
        if(y == p) continue;
        Mi[y] = Mi[x];
        pa[y] = x;
        Mi1[y] = Mi1[x];
        if(Mi[y] > h[y]) Mi1[y] = Mi[y], Mi[y] = h[y];
        else if(Mi1[y] > h[y]) Mi1[y] = h[y];
        DFS(y, x);
    }
}

int m;

void Doit(int st, int di) {
    while(!q.empty()) q.pop();
    dat a = dat(st, Mi[st]);
    q.push(a);
    while(!q.empty()) {
        a = q.top();
        q.pop();
        int x = a.x;
        int he = a.hei;
        int k = upper_bound(s, s + m, he) - s - 1;
        if(k >= 0) in[st][di].push_back(k);
        for(int i = 0; i < v[x].size(); i ++) {
            int y = v[x][i];
            if(y == pa[x]) continue;
            dat b = dat(y, Mi[y]);
            q.push(b);
        }
    }
    return ;
}

int mi[N * 4], add[N * 4];

void push_up(int id) {
    mi[id] = min(mi[id * 2], mi[id * 2 + 1]);
    return ;
}

void add_delta(int id, int x) {
    add[id] += x;
    mi[id] += x;
    return ;
}

void push_down(int id) {
    int l = id * 2;
    int r = id * 2 + 1;
    if(add[id]) {
        add_delta(l, add[id]);
        add_delta(r, add[id]);
        add[id] = 0;
    }
    return ;
}

int deg[N];

void build(int st, int en, int id) {
    if(st == en) {
        mi[id] = deg[st];
        add[id] = 0;
        return ;
    }
    int mid = (st + en) >> 1;
    build(st, mid, id * 2);
    build(mid + 1, en, id * 2 + 1);
    push_up(id);
    return ;
}

void Add(int l, int r, int st, int en, int id, int k) {
    if(l > en || r < st) return ;
    if(l <= st && en <= r) {
        add_delta(id, k);
        return ;
    }
    push_down(id);
    int mid = (st + en) >> 1;
    Add(l, r, st, mid, id * 2, k);
    Add(l, r, mid + 1, en, id * 2 + 1, k);
    push_up(id);
}

int val[N];
int main() {
    //freopen("1.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &h[i]);
    for(int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i ++) scanf("%d", &s[i]);
    sort(s, s + m);
    Mi[1] = h[1];
    Mi1[1] = inf;
    DFS(1, 0);
    while(!q.empty()) q.pop();
    dat a = dat(1, Mi[1]);
    q.push(a);
    int en = m - 1;
    bool ok = true;
    while(!q.empty()) {
        a = q.top();
        int x = a.x;
        int he = a.hei;
        if(he >= s[en]) {
            en --;
        } else {
            ok = false;
            break;
        }
        if(en == -1) break;
        q.pop();
        for(int i = 0; i < v[x].size(); i ++) {
            int y = v[x][i];
            if(y == pa[x]) continue;
            dat b = dat(y, Mi[y]);
            q.push(b);
        }
    }
    if(ok) {
        puts("0");
        return 0;
    }
    int cnt = 0;
    while(!q.empty()) {
        a = q.top();
        q.pop();
        A[cnt ++] = a.x;
    }
    for(int i = 0; i < cnt; i ++) {
        int x = A[i];
        Doit(x, 0);
        val[x] = -1;
        if(Mi1[x] >= s[en]) {
            val[x] = s[en] - Mi[x];
            Mi[x] = s[en];
            DFS(x, pa[x]);
            Doit(x, 1);
        }
    }
    for(int i = 0; i <= en; i ++) deg[i] = -1;
    for(int i = 0; i < cnt; i ++) {
        int x = A[i];
        for(int j = 0; j < in[x][0].size(); j ++) {
            int k = in[x][0][j];
            deg[k] ++;
        }
    }
    for(int i = en - 1; i >= 0; i --) deg[i] += deg[i + 1];
    build(0, en, 1);
    int ans = -1;
    for(int i = 0; i < cnt; i ++) {
        int x = A[i];
        if(val[x] == -1) continue;
        for(int j = 0; j < in[x][0].size(); j ++) {
            int k = in[x][0][j];
            Add(0, k, 0, en, 1, -1);
        }
        for(int j = 0; j < in[x][1].size(); j ++) {
            int k = in[x][1][j];
            Add(0, k, 0, en, 1, 1);
        }
        if(mi[1] >= 0) {
            if(ans == -1) ans = val[x];
            else if(ans > val[x]) ans = val[x];
        }
        for(int j = 0; j < in[x][1].size(); j ++) {
            int k = in[x][1][j];
            Add(0, k, 0, en, 1, -1);
        }
        for(int j = 0; j < in[x][0].size(); j ++) {
            int k = in[x][0][j];
            Add(0, k, 0, en, 1, 1);
        }
    }
    printf("%d\n", ans);
    return 0;
}