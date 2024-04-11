#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <queue>

using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50;
const int mods[4] = {(int)1e9 + 7, (int)1e9 + 9, (int)1e9 + 21, (int)1e9 + 33};

int n, m;
int p = 2;
int num[N];
bool vis[N];
int pv[N];
ll pw[4][N];

struct edge {
    int to, cost;
};

struct Hash {
    ll val[4];

    Hash(int x = 0) { fill(val, val + 4, x); }

    Hash(ll a, ll b, ll c, ll d) {
        val[0] = a, val[1] = b, val[2] = c, val[3] = d;
    }

    bool operator<(const Hash &other) const {
        for (int i = 0; i < 4; i++) if (val[i] != other.val[i]) return val[i] < other.val[i];
        return false;
    }

    bool operator==(const Hash &other) const {
        for (int i = 0; i < 4; i++) if (val[i] != other.val[i]) return false;
        return true;
    }

    Hash operator + (const Hash &other) const{
        Hash res;
        for(int i = 0; i < 4; i++) res.val[i] = (val[i] + other.val[i]) % mods[i];
        return res;
    }

    Hash operator - (const Hash &other) const{
        Hash res;
        for(int i = 0; i < 4; i++) res.val[i] = (val[i] - other.val[i] + mods[i]) % mods[i];
        return res;
    }

    Hash up_pow(int pwi){
        Hash res;
        for(int i = 0; i < 4; i++){
            res.val[i] = (val[i] * pw[i][pwi]) % mods[i];
        }
        return res;
    }
};

//Need to initialize before every test case!
int ncnt = 1;

struct node{
    int ls, rs;
    int sum;
    Hash hs;
} ns[N * 100];

struct Tree{
    const static int n = N;

    static int newnode(int val){
        ns[ncnt].ls = ns[ncnt].rs = 0;
        ns[ncnt].sum = val;
        ns[ncnt].hs = Hash(val);
        return ncnt++;
    }

    static int newnode(int ls, int rs, int tl, int tr){
        int tm = (tl + tr) / 2;
        ns[ncnt].ls = ls;
        ns[ncnt].rs = rs;
        ns[ncnt].sum = (ls ? ns[ls].sum : 0) + (rs ? ns[rs].sum : 0);
        ns[ncnt].hs = (ls ? ns[ls].hs.up_pow(tr - tm) : Hash()) + (rs ? ns[rs].hs : Hash());

        return ncnt++;
    }

    static int build(int a[], int tl = 0, int tr = n-1){
        if(tl == tr) return newnode(a[tl]);
        int mid = (tl + tr) / 2;
        return newnode(build(a, tl, mid), build(a, mid + 1, tr), tl, tr);
    }

    static int get_sum(int v, int l, int r, int tl = 0, int tr = n-1){
        if(tr < l || tl > r) return 0;
        if(l <= tl && tr <= r) return ns[v].sum;
        int tm = (tl + tr) / 2;

        return get_sum(ns[v].ls, l, r, tl, tm)
               + get_sum(ns[v].rs, l, r, tm + 1, tr);
    }

    static int update(int v, int pos, int tl = 0, int tr = n-1){
        if(tl == tr) return newnode(1);
        int tm = (tl + tr) / 2;
        if(pos <= tm) return newnode(update(ns[v].ls, pos, tl, tm), ns[v].rs, tl, tr);
        else return newnode(ns[v].ls, update(ns[v].rs, pos, tm+1, tr), tl, tr);
    }

    static int fill(int v, int l, int r, int num_cur, int tl = 0, int tr = n-1) {
        if(tr < l || tl > r) return v;
        if(l <= tl && tr <= r){
            return num_cur;
        }
        int tm = (tl + tr) / 2;
        return newnode(fill(ns[v].ls, l, r, ns[num_cur].ls, tl, tm),
                       fill(ns[v].rs, l, r, ns[num_cur].rs, tm + 1, tr), tl, tr);
    }

    static int smaller(int v1, int v2, int tl = 0, int tr = n-1) {
        if(tl == tr){
            int cur = ns[v1].sum - ns[v2].sum;
            return cur;
        }
        int tm = (tl + tr) / 2;
        if(ns[ns[v1].ls].hs == ns[ns[v2].ls].hs) return smaller(ns[v1].rs, ns[v2].rs, tm + 1, tr);
        else return smaller(ns[v1].ls, ns[v2].ls, tl, tm);
    }

    static int search(int v1, int tl, int tr, int loc, int tot) {
        if(tl == tr) return tl;
        int tm = (tl + tr) / 2;
        if(tm > loc || tot - ns[ns[v1].ls].sum == loc - tm)
            return search(ns[v1].ls, tl, tm, loc, tot);
        else return search(ns[v1].rs, tm + 1, tr, loc, tot - ns[ns[v1].ls].sum);
    }

};

int ZEROS;

struct Int {
    const static int n = (int)1e5 + 50;
    int root;

    Int(int _root = 0){root = _root;}

    bool operator < (const Int &o) const{
        return Tree::smaller(root, o.root) < 0;
    }
    bool operator > (const Int &o) const{
        return Tree::smaller(root, o.root) > 0;
    }
    bool operator == (const Int &o) const{
        return Tree::smaller(root, o.root) == 0;
    }

    Int add(int x) {
        if(Tree::get_sum(root, x, x) == 0){
            return Tree::update(root, x);
        }
        int tot = Tree::get_sum(root, 0, x);
        int lb = Tree::search(root, 0, n-1, x, tot);
        int res = Tree::fill(root, lb + 1, x, ZEROS);
       res = Tree::update(res, lb);
        return Int(res);
    }
};

vector<edge> G[N];
Int dis[N];

typedef pair<Int, int> P;

struct cmp{
    bool operator() (const P &p1, const P &p2) const{
        return p1.first > p2.first;
    }
};

void dijkstra(int s){
    priority_queue<P, vector<P>, cmp > pque;
    dis[s] = Int(ZEROS);
    vis[s] = true;
    pque.push({dis[s], s});

    while(!pque.empty()){
        P p = pque.top(); pque.pop();
        int i = p.second;
        Int dist = p.first;
        if(dist > dis[i]) continue;

        for(edge e : G[i]){

            Int newdis = dis[i].add(e.cost);
            if(!vis[e.to] || newdis < dis[e.to]){
                pv[e.to] = i;
                vis[e.to] = true;
                dis[e.to] = newdis;
                pque.push({dis[e.to], e.to});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int t = 0; t < 4; t++){
        pw[t][n] = 1;
        for(int i = 1; i < N; i++) pw[t][i] = pw[t][i-1] * p % mods[t];
    }
    ZEROS = Tree::build(num);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w; a--, b--;
        w = (N - 1) - w;
        G[a].push_back({b, w});
        G[b].push_back({a, w});
    }
    int s, t;
    cin >> s >> t; s--, t--;
    dijkstra(s);
    if(!vis[t]) cout << "-1" << endl;
    else {
        int res = ns[dis[t].root].hs.val[0];
        int cur = t;
        vector<int> path = {t};
        while(cur != s){
            cur = pv[cur];
            path.push_back(cur);
        }
        reverse(path.begin(), path.end());
        cout << res << endl;
        cout << path.size() << endl;
        for(int x : path) cout << x + 1 << " ";
        cout << endl;
    }
}