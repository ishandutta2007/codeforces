#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;
typedef pair<int, int> P;


int n;
set<int> G[N];
int deg[N];
map<P, int> mp;
map<P, P> ep;

struct Tri {
    int a, b, c;
    void read() {
        cin >> a >> b >> c;
        a--, b--, c--;
        if(a > b) swap(a, b);
        if(b > c) swap(b, c);
        if(a > b) swap(a, b);
    }
} tri[N];

int nxt[N];
stack<Tri> tris;
vector<int> cut;

void connect(P p, int i) {
    if(mp.count(p)) {
        int v = mp[p];
        G[v].insert(i);
        G[i].insert(v);
        deg[v]++;
        deg[i]++;
        ep[{v, i}] = p;
        ep[{i, v}] = p;
//        cout << "connecting " << v + 1 << " " << i + 1 << endl;
    }
    else {
        mp[p] = i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        mp.clear();
        cut.clear();
        ep.clear();
        cin >> n;
        for(int i = 0; i < n; i++) deg[i] = 0;
        for(int i = 0; i < n; i++) G[i].clear();
        for(int i = 0; i < n - 2; i++) {
            tri[i].read();
            connect({tri[i].a, tri[i].b}, i);
            connect({tri[i].a, tri[i].c}, i);
            connect({tri[i].b, tri[i].c}, i);
        }
        queue<int> que;
        for(int i = 0; i < n - 2; i++) {
            if(deg[i] <= 1) que.push(i);
        }
        while(!que.empty()) {
            int v = que.front(); que.pop();
            cut.push_back(v);
            if(deg[v] == 0) {
                tris.push(tri[v]);
                continue;
            }
            assert(G[v].size() == 1);
            for(int nxt : G[v]) {
                P p = ep[{nxt, v}];
                tris.push({p.first, p.second, tri[v].a + tri[v].b + tri[v].c - p.first - p.second});
                G[nxt].erase(v);
                deg[nxt]--;
                if(deg[nxt] == 1) {
                    que.push(nxt);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            nxt[i] = -1;
        }
        Tri tr = tris.top(); tris.pop();
        nxt[tr.a] = tr.b;
        nxt[tr.b] = tr.c;
        nxt[tr.c] = tr.a;

        while(!tris.empty()) {
            Tri p = tris.top(); tris.pop();
            assert(nxt[p.a] == p.b || nxt[p.b] == p.a);
            if(nxt[p.a] == p.b) {
                nxt[p.c] = p.b;
                nxt[p.a] = p.c;
            }
            else {
                nxt[p.c] = p.a;
                nxt[p.b] = p.c;
            }
        }
        int s = 0;
        for(int i = 0; i < n; i++) {
            cout << s + 1 << " ";
            s = nxt[s];
        }
        cout << '\n';
        for(int x : cut) cout << x + 1 << " ";
        cout << '\n';
    }
}