#include <cstdio>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <map>

using namespace std;

int n;
int a[100005];
int b[100005];
int c[100005];
int cnt[100005];
vector<int> nxt[100005];
bool vis[100005];

set<pair<int, int> > polygon_edge;
multiset<pair<int, int> > all_edges;
map<pair<int, int>, vector<int> > edge_loc;

queue<int> to_remove;

void add(int x, int y, int id)
{
    if (x > y) {
        int t = x; x = y; y = t;
    }
    pair<int, int> pr = make_pair(x, y);
    all_edges.insert(pr);
    if (polygon_edge.count(pr)) {
        polygon_edge.erase(pr);
    } else {
        polygon_edge.insert(pr);
    }
    edge_loc[pr].push_back(id);
}

int findpair(int x, int y)
{
    if (x > y) {
        int t = x; x = y; y = t;
    }
    return all_edges.count(make_pair(x, y));
}

void removeedge(int x, int y)
{
    if (x > y) {
        int t = x; x = y; y = t;
    }
    pair<int, int> pr = make_pair(x, y);
    for (int i = 0; i < edge_loc[pr].size(); i++) {
        cnt[edge_loc[pr][i]]++;
        if (cnt[edge_loc[pr][i]] == 2) to_remove.push(edge_loc[pr][i]);
    }
}

void work(void)
{
    polygon_edge.clear();
    all_edges.clear();
    edge_loc.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) nxt[i].clear(), vis[i] = false, cnt[i] = 0;
    for (int i = 1; i <= n - 2; i++) {
        scanf("%d%d%d", a + i, b + i, c + i);
        add(a[i], b[i], i);
        add(b[i], c[i], i);
        add(c[i], a[i], i);
    }
    for (set<pair<int, int> >::iterator cur = polygon_edge.begin(); ; cur++) {
        if (cur == polygon_edge.end()) break;
        int x = cur->first;
        int y = cur->second;
        nxt[x].push_back(y);
        nxt[y].push_back(x);
    }
    int cur = 1;
    for (int i = 1; i <= n; i++) {
        printf("%d ", cur);
        vis[cur] = true;
        if (!vis[nxt[cur][0]]) {
            cur = nxt[cur][0];
        } else {
            cur = nxt[cur][1];
        }
    }
    printf("\n");
    for (int i = 1; i <= n - 2; i++) {
        if (findpair(a[i], b[i]) == 1) cnt[i]++;
        if (findpair(b[i], c[i]) == 1) cnt[i]++;
        if (findpair(a[i], c[i]) == 1) cnt[i]++;
        if (cnt[i] >= 2) to_remove.push(i);
    }
    while (!to_remove.empty()) {
        int trig = to_remove.front();
        printf("%d ", trig);
        removeedge(a[trig], b[trig]);
        removeedge(b[trig], c[trig]);
        removeedge(a[trig], c[trig]);
        to_remove.pop();
    }
    printf("\n");
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        work();
    }
    return 0;
}