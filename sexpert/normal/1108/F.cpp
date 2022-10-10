#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, w;
    bool operator<(const edge &o) const { return w < o.w; }
};

const int MAXN = 2e5 + 5;
int par[MAXN];

int find(int v) {
    return (par[v] == 0 ? v : par[v] = find(par[v]));
}

bool conn(int u, int v) {
    return find(u) == find(v);
}

bool join(int u, int v) {
    u = find(u), v = find(v);
    if(u == v)
        return false;
    par[u] = v;
    return true;
}

vector<edge> vec;
int n, m;

int kruskal() {
    int cwt = -1, comp = n, cnt = 0;
    sort(vec.rbegin(), vec.rend());
    while(comp > 1) {
        if(vec.back().w > cwt)
            cwt = vec.back().w;
        vector<edge> pend;
        while(!vec.empty() && vec.back().w == cwt) {
            auto e = vec.back();
            vec.pop_back();
            if(conn(e.u, e.v))
                continue;
            else
                pend.push_back(e);
        }
        while(!pend.empty()) {
            auto e = pend.back();
            pend.pop_back();
            if(join(e.u, e.v))
                comp--;
            else
                cnt++;
        }
    }
    /*for(auto e : vec) {
        if(e.w > cwt && comp == 1)
            return cnt;
        if(e.w > cwt)
            cwt = e.w;
        if(join(e.u, e.v))
            comp--;
        else
            cnt++;
    }*/
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vec.push_back(edge{u, v, w});
    }
    cout << kruskal() << endl;
}