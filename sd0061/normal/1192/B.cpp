#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

inline int id(int l, int r) {
    return l + r | l != r;
}
#define Left l , mid
#define Right mid + 1 , r 

struct stree {
    pair<long long, int> mx;
    pair<long long, int> mid, lm, mr;
    tuple<long long, int, int> res;
    long long f;

    void add(long long x) {
        f += x;
        mx.first += x;
        mid.first -= 2 * x;
        lm.first -= x;
        mr.first -= x;
    }
} t[N << 1];

void pushup(int p , int l , int mid , int r) {
    int L = id(Left), R = id(Right);
    t[p].mx = max(t[L].mx, t[R].mx);
    t[p].mid = max(t[L].mid, t[R].mid);
    t[p].lm = max(t[L].lm, t[R].lm);
    t[p].mr = max(t[L].mr, t[R].mr);
    t[p].res = max(t[L].res, t[R].res);
    
    if (t[L].mx.first + t[R].mid.first > t[p].lm.first) {
        t[p].lm = make_pair(t[L].mx.first + t[R].mid.first, t[L].mx.second);
    }
    if (t[L].mid.first + t[R].mx.first > t[p].mr.first) {
        t[p].mr = make_pair(t[L].mid.first + t[R].mx.first, t[R].mx.second);
    }
    if (t[L].lm.first + t[R].mx.first > get<0>(t[p].res)) {
        t[p].res = make_tuple(t[L].lm.first + t[R].mx.first,
                              t[L].lm.second, t[R].mx.second);
    }
    if (t[L].mx.first + t[R].mr.first > get<0>(t[p].res)) {
        t[p].res = make_tuple(t[L].mx.first + t[R].mr.first,
                              t[L].mx.second, t[R].mr.second);
    }
}

void pushdown(int p , int l , int mid , int r) {
    if (t[p].f) {
        t[id(Left)].add(t[p].f);
        t[id(Right)].add(t[p].f); 
        t[p].f = 0;
    }
}

int n , m;
vector<pair<int, long long>> e[N];
pair<int, int> edge[N];
int L[N] , R[N] , ncnt;
int order[N] , fa[N];
long long w[N], dis[N];

void dfs(int x) {
    L[x] = ++ ncnt;
	order[L[x]] = x;
	for (auto it : e[x]) {
		int y = it.first;
		long long z = it.second;
        if (y != fa[x]) {
            dis[y] = dis[x] + z;
            w[y] = z;
            fa[y] = x;
            dfs(y);
            order[++ ncnt] = x;
        }
    }
    R[x] = ncnt;
}

void build(int l , int r) {
    int p = id(l, r);
    if (l == r) {
        int x = order[l];
        // cout << "- " << l << ' ' << x << ' ' << dis[x] << endl;
        t[p].add(dis[x]);
        t[p].mx.second = t[p].mid.second = x;
        t[p].lm.second = t[p].mr.second = x;
        get<1>(t[p].res) = get<2>(t[p].res) = x; 
        t[p].f = 0;
    } else {
        int mid = l + r >> 1;
        build(l , mid);
        build(mid + 1 , r);
        pushup(p, l , mid , r);
    }
}

void add(int l , int r , int top , int bot , long long delta) {
    int p = id(l, r);
    if (top <= l && r <= bot) {
        t[p].add(delta);
    } else {
        int mid = l + r >> 1;
        pushdown(p, l , mid , r);
        if (top <= mid) {
            add(Left, top , bot , delta);
        } 
        if (bot > mid) {
            add(Right, top, bot, delta);
        }
        pushup(p, l , mid , r);
    }
}

void work() {
    long long maxw;
    scanf("%d%d%lld" , &n , &m , &maxw);
    for (int i = 0 ; i + 1 < n ; ++ i) {
        int x , y;
        long long z;
        scanf("%d%d%lld" , &x , &y , &z);
        e[x].emplace_back(y, z);
        e[y].emplace_back(x, z);
        edge[i] = make_pair(x , y);
    }
    ncnt = 0;
    dfs(1);
    build(1, ncnt);

    long long last = 0;
    while (m --) {
        int o , x , y;
        long long v;
        static char str[5];
        scanf("%d%lld" , &o, &v);
        o = (o + last) % (n - 1);
        v = (v + last) % maxw;
        tie(x , y) = edge[o];
        if (fa[y] == x) {
            swap(x , y);
        }
        add(1 , ncnt, L[x], R[x], v - w[x]);
        w[x] = v;
        printf("%lld\n" , last = get<0>(t[id(1 , ncnt)].res));
    }
}

int main() {
    work();
}