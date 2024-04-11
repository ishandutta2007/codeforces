#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

struct Edge
{
    int from, to;
    int cap, flow;
    Edge(int f, int t, int c)
        : from(f), to(t), cap(c), flow(0) {}
};

vector< Edge > e;
vector< vector< int > > g;
int beg, en;
int all_cnt;
vector< pair< int, int > > pr;
vector< int > a;
vector< int > dist;
vector< int > ptr;
int n, m;

void
add_edge(int from, int to, int cap)
{
    g[from].push_back(e.size());
    e.push_back(Edge(from, to, cap));
    g[to].push_back(e.size());
    e.push_back(Edge(to, from, 0));
}

int
get_pow(int val, int div)
{
    int res = 0;
    while (val % div == 0) {
        val /= div;
        res++;
    }
    return res;
}

bool
bfs(int from, int to, int scale)
{
    dist.assign(all_cnt, -1);
    vector< int > q(all_cnt);
    int qh = 0, qt = 0;
    q[qt++] = from;
    dist[from] = 0;
    while (qh < qt) {
        int cur = q[qh++];
        for (auto e_id : g[cur]) {
            int to_v = e[e_id].to;
            if (dist[to_v] == -1 && e[e_id].cap >= e[e_id].flow + scale) {
                dist[to_v] = dist[cur] + 1;
                q[qt++] = to_v;
            }
        }
    }
    return dist[to] != -1;
}

int
dfs(int v, int to, int flow)
{
    if (v == to || !flow) {
        return flow;
    }
    int cnt = int(g[v].size());
    for (int &i = ptr[v]; i < cnt; ++i) {
        int e_id = g[v][i];
        int to_v = e[e_id].to;
        if (dist[to_v] != dist[v] + 1) {
            continue;
        }
        int pushed = dfs(to_v, to, min(flow, e[e_id].cap - e[e_id].flow));
        if (pushed) {
            e[e_id].flow += pushed;
            e[e_id ^ 1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}


int
dinic_it(int scale)
{
    int res = 0;
    while (bfs(beg, en, scale)) {
        ptr.assign(all_cnt, 0);
        int pushed;
        while ((pushed = dfs(beg, en, 100500)) != 0) {
            res += pushed;
        }
    }
    return res;
}

int
dinic()
{
    int res = 0;
    for (int scale = 1 << 16; scale > 0; scale /= 2) {
        res += dinic_it(scale);
    }
    return res;
}

int
get_ans(int div)
{
    for (auto &x : e) {
        x.flow = 0;
    }
    for (auto &x : e) {
        if (x.to == en) {
            x.cap = get_pow(a[x.from], div);
        } else if (x.from == beg) {
            x.cap = get_pow(a[x.to], div);
        }
    }
    return dinic();
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    pr.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> pr[i].first >> pr[i].second;
        if (pr[i].first % 2 == 0) {
            swap(pr[i].first, pr[i].second);
        }
    }
    all_cnt = n + 2;
    beg = 0, en = all_cnt - 1;
    g.resize(all_cnt);
    e.clear();
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 1) {
            add_edge(beg, i, 0);
        } else {
            add_edge(i, en, 0);
        }
    }
    for (int i = 0; i < m; ++i) {
        int x = pr[i].first, y = pr[i].second;
        add_edge(x, y, 100500);
    }
    vector< int > all_divs;
    for (int i = 1; i <= n; ++i) {
        int cur = a[i];
        for (int j = 2; j * j <= cur; ++j) {
            if (cur % j == 0) {
                all_divs.push_back(j);
                while (cur % j == 0) {
                    cur /= j;
                }
            }
        }
        if (cur != 1) {
            all_divs.push_back(cur);
        }
    }
    sort(all_divs.begin(), all_divs.end());
    all_divs.resize(unique(all_divs.begin(), all_divs.end()) - all_divs.begin());
    int res = 0;
    for (auto v : all_divs) {
        res += get_ans(v);
    }
    cout << res << '\n';
    return 0;
}