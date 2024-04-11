#include <bits/stdc++.h>
using namespace std;

#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;

inline int qread() {
    register char c = getchar();
    register int x = 0, f = 1;
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + c - 48;
        c = getchar();
    }
    return x * f;
}

const int N = 200005;

struct Edge {
    int to, nxt;
    Edge() {
        nxt = -1;
    }
};
int n, m, hd[N], pnt, oud[N];
long long dis[N];
Edge e[N << 1];
priority_queue <pair <long long, int>, vector <pair <long long, int> >, greater <pair <long long, int> > > que;

inline void AddEdge(int u, int v) {
    e[++pnt].to = v;
    e[pnt].nxt = hd[u];
    hd[u] = pnt;
}

inline void Read() {
    n = qread(); m = qread();
    for (int i = 1;i <= m;i++) {
        int u = qread(), v = qread();
        oud[u]++;
        AddEdge(v, u);
    }
}

inline void Solve() {
    memset(dis, 0x3f, sizeof(dis));
    dis[n] = 0;
    que.push(make_pair(0, n));
    while (!que.empty()) {
        int u = que.top().second;
        if (dis[u] < que.top().first) {
            que.pop();
            continue;
        }
        que.pop();
        for (int i = hd[u];~i;i = e[i].nxt) {
            oud[e[i].to]--;
            if (oud[e[i].to] + dis[u] + 1 < dis[e[i].to]) {
                dis[e[i].to] = oud[e[i].to] + dis[u] + 1;
                que.push(make_pair(dis[e[i].to], e[i].to));
            }
        }
    }
    cout << dis[1] << endl;
}

int main() {
    memset(hd, -1, sizeof(hd));
    Read();
    Solve();
    return 0;
}