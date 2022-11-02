#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define x first
#define y second
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)
template <class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template <class T> void chkmin(T &a, T b) {if (a > b) a = b;}

typedef pair <int, int> pii;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;

const int inf = 0x3f3f3f3f;

#define N 200010
vector <int> v[N];

stack <int> stk;
int n, tot, G, sz, m, h;
int dt[N], low[N], u[N], rt[N];
int nxt[N], head[N], to[N];

void add_edge(int x, int y) {
    tot ++;
    nxt[tot] = head[x]; to[tot] = y; head[x] = tot;
    return;
}

void dfs(int k) {
    dt[k] = low[k] = ++ G; stk.push(k);
    for (int i = head[k]; i; i = nxt[i]) {
        int x = to[i];
        if (!dt[x]) {
            dfs(x);
            chkmin(low[k], low[x]);
        }
        else chkmin(low[k], dt[x]);
    }
    if (dt[k] == low[k]) {
        int x;
        while (!stk.empty()) {
            x = stk.top(); stk.pop();
            rt[x] = k;
            v[k].pb(x);
            if (x == k) break;
        }
    }
    return;
}

int main() {
    scanf("%d %d %d", &n, &m, &h);
    int x, y;
    f1(i, 1, n) scanf("%d", &u[i]);
    f1(i, 1, m) {
        scanf("%d %d", &x, &y);
        if ((u[x] + 1) % h == u[y]) add_edge(x, y);
        if ((u[y] + 1) % h == u[x]) add_edge(y, x);
    }
    f1(i, 1, n) if (!dt[i]) dfs(i);
    memset(dt, 0, sizeof dt);
    f1(i, 1, n) {
        for (int x = head[i]; x; x = nxt[x]) {
            if (rt[to[x]] != rt[i]) dt[rt[i]] = 1;
        }
    }
    int ans = inf, id;
    f1(i, 1, n) if (!dt[i] && v[i].size() > 0 && ans > v[i].size()) {
        id = i; ans = v[i].size();
    }
    printf("%d\n", ans);
    f0(i, 0, v[id].size()) printf("%d ", v[id][i]);
	return 0;
}