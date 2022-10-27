#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
const int NICO = 100000+10;
typedef pair<int, int> pii;
typedef long long LL;

int n, m, q;
int qu[NICO], qv[NICO];
int a[NICO], b[NICO], c[NICO];
vector<pii> edge[NICO];
vector<int> room;

map<pii, int> ans; int res[NICO];
int par[NICO], id[NICO];

int find(int x) {
    return par[x] == -1? x: par[x] = find(par[x]);
}

void unite(int x, int y) {
    int p1 = find(x);
    int p2 = find(y);
    if(p1 != p2) {
        par[p1] = p2;
    }
}

int main() {
    for(int i=1;i<=n;i++) {
        par[i] = -1;
    }
    scanf("%d %d", &n, &m);
    for(int i=1;i<=m;i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edge[c].push_back(make_pair(a, b));
    }

    scanf("%d", &q);
    for(int i=1;i<=q;i++) {
        scanf("%d %d", &qu[i], &qv[i]);
    }

    for(int i=1;i<=m;i++) {
        room.clear();
        for(int j=0;j<edge[i].size();j++) {
            room.push_back(edge[i][j].first); 
            room.push_back(edge[i][j].second);
        }
        sort(room.begin(), room.end());
        room.erase(unique(room.begin(), room.end()), room.end());
        for(int j=0;j<room.size();j++) {
            par[room[j]] = -1;
            id[room[j]] = i;
        }
        for(int j=0;j<edge[i].size();j++) {
            unite(edge[i][j].first, edge[i][j].second);
        }

        if((LL)room.size() * (LL)room.size() > n) {
            for(int j=1;j<=q;j++) {
                int u = qu[j], v = qv[j];
                if( id[u] == i && id[v] == i && find(u) == find(v) ) {
                    res[j] ++;
                }
            }
        } else {
            for(int j=0;j<room.size();j++) {
                for(int k=j+1;k<room.size();k++) {
                    if(find(room[j]) == find(room[k])) {
                        ans[make_pair(room[j], room[k])] ++;
                        ans[make_pair(room[k], room[j])] ++;
                    }
                }
            }
        }
    }

    for(int i=1;i<=q;i++) {
        printf("%d\n", ans[make_pair(qu[i], qv[i])] + res[i]);
    }
}