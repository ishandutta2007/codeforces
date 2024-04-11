#include <bits/stdc++.h>
using namespace std;

const int FN = 2005, INF = (int)1e9;
const int N = 1005;

struct point{
    int x, y;
    point(int _x, int _y){x = _x, y = _y;}
    bool operator < (const point &other) const{
        return x == other.x ? y < other.y : x < other.x;
    }
};

typedef pair<int, int> P;
typedef pair<point, point> Pt;

struct edge{
    int to, cap, rev;
    edge(int _to, int _cap, int _rev){
        to = _to, cap = _cap, rev = _rev;
    }
};

vector<edge> G[FN];
bool used[FN];

void add_edge(int from, int to, int cap){
    G[from].push_back(edge(to, cap, G[to].size()));
    G[to].push_back(edge(from, 0, G[from].size() - 1));
}

int dfs(int v, int t, int f){
    if(v == t) return f;
    used[v] = true;

    for(int i = 0; i < G[v].size(); i++){
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0){
            int d = dfs(e.to, t, min(e.cap, f));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t){
    int f = 0;
    for(;;){
        fill(used, used + FN, false);
        int d = dfs(s, t, INF);
        if(d == 0) return f;
        f += d;
    }
}

map<int, int> mpx, mpy;
int cntx = 0, cnty = 0;

int x_id(int x){
    if(!mpx.count(x)) mpx[x] = cntx++; return mpx[x];
}

int y_id(int y){
    if(!mpy.count(y)) mpy[y] = cnty++; return mpy[y];
}

bool btw(int &x, int &l, int &r){
    return x > l && x < r;
}

bool inter(Pt &a, Pt &b){
    return btw(a.first.x, b.first.x, b.second.x) && btw(b.first.y, a.first.y, a.second.y);
}

void print_out(Pt a){
    printf("%d %d %d %d\n", a.first.x, a.first.y, a.second.x, a.second.y);
}

int n;
int x[N], y[N];
vector<int> xt[N], yt[N];
vector<Pt> sx, sy;
vector<Pt> resx, resy;
int nx, ny;
bool take[FN], vis[FN];

bool cmpy(Pt a, Pt b){
    return a.first.y == b.first.y ? a.first.x < b.first.x : a.first.y < b.first.y;
}

void dfs(int x){
    vis[x] = true;
    take[x] = true;
    for(edge &e : G[x]){
        if(e.cap > 0 && !vis[e.to]) dfs(e.to);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        xt[x_id(x[i])].push_back(y[i]);
        yt[y_id(y[i])].push_back(x[i]);
    }
    for(int i = 0; i < cntx; i++) sort(xt[i].begin(), xt[i].end());
    for(int j = 0; j < cnty; j++) sort(yt[j].begin(), yt[j].end());
    for(auto p : mpx){
        int x = p.first, i = p.second;
        if(xt[i].size() == 1) resx.push_back({point(x, xt[i][0]), point(x, xt[i][0])});
        for(int j = 0; j + 1 < xt[i].size(); j++) sx.push_back({point(x, xt[i][j]), point(x, xt[i][j+1])});
    }
    for(auto p : mpy){
        int y = p.first, i = p.second;
        if(yt[i].size() == 1) resy.push_back({point(yt[i][0], y), point(yt[i][0], y)});
        for(int j = 0; j + 1 < yt[i].size(); j++) sy.push_back({point(yt[i][j], y), point(yt[i][j+1], y)});
    }
    sort(sx.begin(), sx.end());
    sort(sy.begin(), sy.end(), cmpy);
    nx = sx.size(), ny = sy.size();

    int s = nx + ny, t = s + 1;

    for(int i = 0; i < nx; i++) add_edge(s, i, 1);
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            if(inter(sx[i], sy[j])){
                add_edge(i, j + nx, 1);
            }
        }
    }
    for(int j = 0; j < ny; j++) add_edge(j + nx, t, 1);
    max_flow(s, t);
    dfs(s);
    for(int j = 0; j < ny; j++) take[j + nx] = !take[j + nx];

    bool exi = false;
    point a = point(-1, -1), b = point(-1, -1);
    for(int i = 0; i < nx; i++){
        if(b.x != sx[i].first.x){
            if(b.x != -1) resx.push_back({a, b});
            a = sx[i].first;
            b = sx[i].first;
        }
        if(take[i]) b = sx[i].second;
        else {
            resx.push_back({a, b});
            a = b = sx[i].second;
        }
    }
    if(b.x != -1) resx.push_back({a, b});

    a = b = point(-1, -1);
    for(int j = 0; j < ny; j++){
        if(b.y != sy[j].first.y){
            if(b.y != -1) resy.push_back({a, b});
            a = sy[j].first;
            b = sy[j].first;
        }
        if(take[j + nx]) b = sy[j].second;
        else{
            resy.push_back({a, b});
            a = b = sy[j].second;
        }
    }
    if(b.y != -1) resy.push_back({a, b});

    printf("%d\n", resy.size());
    for(auto p : resy) print_out(p);
    printf("%d\n", resx.size());
    for(auto p : resx) print_out(p);
}