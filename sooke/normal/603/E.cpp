#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 4e5 + 5;

int n, m, now, ans;
bool used[N];

struct Edge {
    int u, v, w, i;
} edg[N];

bool operator <(const Edge &i, const Edge &j) {
    return i.w < j.w;
}

std::priority_queue<Edge> que;

struct LinkCutTree {
    int ft[N], son[N][2], siz[N], sizi[N], f[N];
    bool rev[N];

    inline bool isRoot(int u) {
        return son[ft[u]][0] != u && son[ft[u]][1] != u;
    }
    inline bool isRight(int u) {
        return son[ft[u]][1] == u;
    }
    inline void connect(int u, int fa, int d) {
        ft[u] = fa; son[fa][d] = u;
    }

    inline void pushUp(int u) {
        int ls = son[u][0], rs = son[u][1];
        siz[u] = siz[ls] + siz[rs] + sizi[u];
        if (u <= n) {
            f[u] = 0; siz[u]++;
        } else {
            f[u] = u - n;
        }
        if (edg[f[u]] < edg[f[ls]]) { f[u] = f[ls]; }
        if (edg[f[u]] < edg[f[rs]]) { f[u] = f[rs]; }
    }
    inline void pushRev(int u) {
        std::swap(son[u][0], son[u][1]); rev[u] ^= 1;
    }
    inline void pushDown(int u) {
        if (rev[u]) {
            pushRev(son[u][0]); pushRev(son[u][1]);
            rev[u] = false;
        }
    }
    inline void rotate(int u) {
        int fa = ft[u], fd = isRight(u);
        int ga = ft[fa], gd = isRight(fa);
        ft[u] = ga;
        if (!isRoot(fa)) { son[ga][gd] = u; }
        int s = son[u][fd ^ 1];
        connect(s, fa, fd); pushUp(fa);
        connect(fa, u, fd ^ 1); pushUp(u);
    }
    
    void splay(int u) {
        static int vol = 0, stc[N];
        stc[++vol] = u;
        for (int fa = u; !isRoot(fa); fa = ft[fa]) {
            stc[++vol] = ft[fa];
        }
        for (; vol; vol--) { pushDown(stc[vol]); }
        for (int fa = ft[u]; !isRoot(u); rotate(u), fa = ft[u]) {
            if (!isRoot(fa)) { rotate(isRight(u) == isRight(fa) ? fa : u); }
        }
    }
    void access(int u) {
        for (int s = 0; u > 0; s = u, u = ft[u]) {
            splay(u);
            sizi[u] += siz[son[u][1]];
            son[u][1] = s;
            sizi[u] -= siz[son[u][1]];
            pushUp(u);
        }
    }
    void setRoot(int u) {
        access(u); splay(u); pushRev(u);
    }
    int findRoot(int u) {
        access(u); splay(u); pushDown(u);
        for (; son[u][0] > 0; u = son[u][0], pushDown(u));
        return u;
    }
    void split(int u, int v) {
        setRoot(v); access(u); splay(u);
    }

    void link(int u, int v) {
        split(u, v); ft[v] = u; sizi[u] += siz[v]; pushUp(u);
    }
    void cut(int u, int v) {
        split(u, v); ft[v] = 0; son[u][0] = 0; pushUp(u);
    }
    int query(int u) {
        setRoot(u); return siz[u];
    }
} lct;

void link(int i) {
    lct.link(edg[i].u, n + i);
    lct.link(edg[i].v, n + i);
    used[i] = true;
    que.push(edg[i]);
}
void cut(int i) {
    lct.cut(edg[i].u, n + i);
    lct.cut(edg[i].v, n + i);
    used[i] = false;
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read(), w = read();
        edg[i] = (Edge) {u, v, w, i};
    }
    for (int u = 1; u <= n + m; u++) {
        lct.pushUp(u);
    }
    now = n;
    for (int i = 1, j; i <= m; i++) {
        int u = edg[i].u, v = edg[i].v, w = edg[i].w;
        if (lct.findRoot(u) == lct.findRoot(v)) {
            lct.split(u, v); j = lct.f[u];
            if (edg[j].w > w) {
                cut(j); link(i);
            }
        } else {
            int sizu = lct.query(u);
            int sizv = lct.query(v);
            now -= sizu & 1;
            now -= sizv & 1;
            now += sizu + sizv & 1;
            link(i);
        }
        while (now == 0 && !que.empty()) {
            j = que.top().i; que.pop();
            if (!used[j]) { continue; }
            cut(j);
            int sizu = lct.query(edg[j].u);
            int sizv = lct.query(edg[j].v);
            if (sizu % 2 != 0 || sizv % 2 != 0) {
                link(j); ans = edg[j].w; break;
            }
        }
        printf("%d\n", now == 0 ? ans : -1);
    }
    return 0;
}