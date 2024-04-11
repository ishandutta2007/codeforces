#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 50;
typedef pair<int, int> P;

int n, m;
set<int> G[N];
deque<P> tour;
vector<P> res;

void add_path(vector<P> &path) {
    int len = path.size();
    if(len % 2 == 0) {
        for(int j = 0; j < len; j++) if(j == len - 1 || j % 2 == 0) res.push_back(path[j]);
    }
    else {
        for(int j = 0; j < len; j++) if(j % 2 == 0) res.push_back(path[j]);
    }
    path.clear();
}

void dfs(int v) {
    while(!G[v].empty()) {
        int nxt = *G[v].begin();
        G[v].erase(nxt);
        G[nxt].erase(v);
        tour.push_back({v, nxt});
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].insert(v);
        G[v].insert(u);
    }
    for(int i = 0; i < n; i++) {
        if(G[i].size() % 2 == 1) {
            G[i].insert(n);
            G[n].insert(i);
        }
    }

    for(int i = 0; i < n; i++) {
        if(!G[i].empty()) {
            dfs(i);
            bool del = false;
            for(const auto &p : tour) {
                if(p.first == n || p.second == n) {del = true; break;}
            }
            if(del) {
                while(tour.front().first != n && tour.front().second != n) {
                    tour.push_back(tour.front());
                    tour.pop_front();
                }
            }
            vector<P> path;
            while(!tour.empty()) {
                if(tour.front().first == n || tour.front().second == n) {
                    add_path(path);
                }
                else {
                    path.push_back(tour.front());
                }
                tour.pop_front();
            }
            add_path(path);
        }
    }
    cout << res.size() << "\n";
    for(const auto &p : res) cout << p.first + 1 << " " << p.second + 1 << "\n";

}