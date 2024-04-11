#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    vector<pair<int,int>> edg;
    vector<int> st;
    st.resize(n+1);
    edg.resize(m);

    vector<pair<int,int>> edg_r;
    vector<int> st_r;
    st_r.resize(n+1);
    edg_r.resize(m);

    vector<int> deg;
    deg.resize(n+1);

    for (int i = 0; i<=n; i++)
    {
        st[i] = 0;
        st_r[i] = 0;
        deg[i] = 0;
    }

    for (int i = 0; i<m; i++)
    {
        int s, e;
        scanf("%d%d",&s,&e);
        edg[i].first = e-1;
        edg[i].second = s-1;
        edg_r[i].first = s-1;
        edg_r[i].second = e-1;
        st[e]++;
        st_r[s]++;
        deg[s-1]++;
    }

    sort(edg.begin(), edg.end());
    sort(edg_r.begin(), edg_r.end());

    for (int i = 1; i<=n; i++)
    {
        st[i] += st[i-1];
        st_r[i] += st_r[i-1];
        //printf("%d\n", st[i]);
    }

    set<pair<int,int>> hp;
    hp.insert(pair<int,int>(0,n-1));

    vector<bool> vis;
    vis.resize(n);
    for (int i = 0; i < n; i++)vis[i] = 0;

    vector<int> cost;
    cost.resize(n);
    for (int i = 0; i<n; i++)
    {
        cost[i] =  i == n-1 ? 0 : n+m;
        hp.insert(pair<int,int>(cost[i], i));
    }

    while (true)
    {
        pair<int, int> top = *hp.begin();
        hp.erase(top);
        //printf("%d, %d\n", top.first, top.second);

        vis[top.second] = 1;

        if (top.second == 0)
        {
            printf("%d\n", top.first);
            break;
        }

        int nod = top.second;
        for (int i = st[nod]; i <st[nod+1]; i++)
        {
            int oth = edg[i].second;
            if (!vis[oth])
            {
                deg[oth]--;
            }
        }

        for (int i = st[nod]; i < st[nod+1]; i++)
        {
            int oth = edg[i].second;
            if (!vis[oth])
            {
                int new_cost = top.first + 1 + deg[oth];
                //printf("%d %d %d\n", top.first, deg[oth], 1);
                if (new_cost < cost[oth])
                {
                    hp.erase(pair<int,int>(cost[oth], oth));
                    cost[oth] = new_cost;
                    hp.insert(pair<int,int>(cost[oth], oth));
                }
            }
        }
    }
    return 0;
}