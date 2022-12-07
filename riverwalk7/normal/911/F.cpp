#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

#ifndef ONLINE_JUDGE
#define _TRACE(format, ...)      fprintf(stderr, format, __VA_ARGS__)
#else
#define _TRACE(format, ...)
#endif

struct node {
    int a, b, c;

    node(int _a, int _b, int _c) : a(_a), b(_b), c(_c) { }
};

vector<int> adj[200005];
int ht[200005], far[200005];
int d[2][200005];
bool del[200005];
int dia, dv1, dv2;
int n;

void diameter(int now, int parent, int& dlen, int& v1, int& v2, int& root) {
    ht[now] = 0;
    far[now] = now;

    for (int child : adj[now]) {
        if (child == parent)
            continue;
        
        diameter(child, now, dlen, v1, v2, root);

        if (ht[child] + 1 > ht[now]) {
            ht[now] = ht[child] + 1;
            far[now] = far[child];
        }
    }

    int f1 = -1;
    int maxht = -1;
    for (int child : adj[now]) {
        if (child == parent)
            continue;
        if (ht[child] > maxht) {
            maxht = ht[child];
            f1 = child;
        }
    }

    int f2 = -1;
    maxht = -1;
    for (int child : adj[now]) {
        if (child == parent)
            continue;
        if (ht[child] > maxht && child != f1) {
            maxht = ht[child];
            f2 = child;
        }
    }

    int nowd;
    if (f1 == -1) {
        assert(f2 == -1);
        f1 = f2 = now;
        nowd = 0;
    } else if (f2 == -1) {
        f2 = now;
        nowd = ht[f1] + 1;
        f1 = far[f1];
    } else {
        nowd = ht[f1] + ht[f2] + 2;
        f1 = far[f1];
        f2 = far[f2];
    }

    if (nowd > dlen) {
        dlen = nowd;
        v1 = f1;
        v2 = f2;
        root = now;
    }
}

void dfs_dist(int res[], int now, int parent, int len) {
    res[now] = len;
    for (int child : adj[now]) {
        if (child == parent)
            continue;
        dfs_dist(res, child, now, len + 1);
    }
}

void dfs_solve(vector<node>& op, int now, int parent, long long int& res) {
    if (now == dv1 || now == dv2)
        return;
    
    del[now] = true;
    for (int child : adj[now]) {
        if (child == parent)
            continue;
        
        dfs_solve(op, child, now, res);
        if (!del[child])
            del[now] = false;
    }

    if (del[now]) {
        int partner = (d[0][now] >= d[1][now] ? dv1 : dv2);

        res += max(d[0][now], d[1][now]);
        op.emplace_back(now, partner, now);
    }
}

int main(int argc, char* argv[]) {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Find a diameter using tree DP.
    int root;
    dia = -1;
    diameter(1, -1, dia, dv1, dv2, root);
    _TRACE("TRACE: main: diameter: length = %d, endpoints are %d and %d, root = %d.\n", 
        dia, dv1, dv2, root);

    dfs_dist(d[0], dv1, -1, 0);
    dfs_dist(d[1], dv2, -1, 0);
    assert(d[0][dv2] == dia);
    assert(d[1][dv1] == dia);

    vector<node> oseq;
    long long int ans = 0ll;
    dfs_solve(oseq, root, -1, ans);
    assert(!del[dv1]);
    assert(!del[dv2]);

    int now = dv1;
    while (now != dv2) {
        ans += dia--;
        oseq.emplace_back(now, dv2, now);
        del[now] = true;

        for (int child : adj[now]) {
            if (!del[child]) {
                now = child;
                break;
            }
        }
    }

    assert(dia == 0);
    assert((int)oseq.size() == n - 1);

    printf("%lld\n", ans);
    for (const node& nd : oseq)
        printf("%d %d %d\n", nd.a, nd.b, nd.c);

    return 0;
}