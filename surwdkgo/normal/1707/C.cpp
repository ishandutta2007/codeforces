#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cinttypes>

using namespace std;

#define MAXN 1000010
#define F first
#define S second
#define P pair<int,int>

int64_t s64() { int64_t res; scanf("%" PRId64, &res); return res; }
void p64(int64_t res) { printf("%" PRId64, res); }

int n,m;

struct Edge
{
    int s,t,c;
    Edge(int _s, int _t, int _c) : s(_s),t(_t),c(_c) {}

    bool operator <(const Edge& ot) const
    {
        return s < ot.s;
    }
};
vector<Edge> edg;
int st[MAXN];
bool vis[MAXN];
int ord[MAXN];

int pa[MAXN];
set<int> ch[MAXN];

int dif[MAXN];
char ans[MAXN];

int main()
{
    scanf("%d%d",&n,&m);

    for (int i = 0; i < m; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        u--;
        v--;
        edg.push_back(Edge(u,v,i));
        edg.push_back(Edge(v,u,i));
        st[u+1]++;
        st[v+1]++;
    }

    sort(edg.begin(), edg.end());
    for (int i = 0; i < n; i++) st[i+1] += st[i];

    map<int, P> que;
    que[0] = P(0,0);

    int norder = 0;

    while (que.size() > 0)
    {
        auto it = que.begin();
        P p = it->second;
        int u = p.second;
        int parent = p.first;

        que.erase(it);

        if (vis[u])
        {
            continue;
        }

        ord[u] = norder++;
        if (parent != u)
        {
            pa[u] = parent;
            ch[parent].insert(u);
        }

        vis[u] = 1;
        for (int i = st[u]; i < st[u+1]; i++)
        {
            if (!vis[edg[i].t])
            {
                que[edg[i].c] = P(u,edg[i].t);
            }
        }
    }


    struct Frame
    {
        int u;
        set<int>::iterator it;
    };

    stack<Frame> stk;
    map<int,int> anc;

    Frame ini;
    ini.u = 0;
    ini.it = ch[ini.u].begin();
    stk.push(ini);

    while (stk.size() > 0)
    {
        Frame& f = stk.top();

        if (f.it == ch[f.u].end())
        {
            anc.erase(f.u);
            stk.pop();
            continue;
        }

        Frame nf;
        int v = *f.it;
        ++f.it;
        nf.u = v;
        nf.it = ch[nf.u].begin();
        stk.push(nf);

        anc[f.u] = v;

        for (int i = st[v]; i < st[v+1]; i++)
        {
            int ev = edg[i].t;
            if (ev == pa[v] || ch[v].find(ev) != ch[v].end())
            {
                continue;
            }
            if (ord[ev] > ord[v])
            {
                continue;
            }

            if (anc.find(ev) != anc.end())
            {
                dif[anc[ev]]++;
                dif[v]--;
            }
            else
            {
                dif[0]++;
                dif[v]--;
                dif[ev]--;
            }
        }
    }

    ini.u = 0;
    ini.it = ch[ini.u].begin();
    stk.push(ini);

    int sum = dif[0];
    ans[0] = sum ? '0' : '1';

    while (stk.size() > 0)
    {
        Frame& f = stk.top();

        if (f.it == ch[f.u].end())
        {
            sum -= dif[f.u];

            stk.pop();
            continue;
        }

        Frame nf;
        int v = *f.it;
        ++f.it;
        nf.u = v;
        nf.it = ch[nf.u].begin();
        stk.push(nf);
        sum += dif[nf.u];
        ans[nf.u] = sum ? '0' : '1';
    }

    printf("%s\n", ans);

    return 0;
}