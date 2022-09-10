#include <bits/stdc++.h>
#define ll long long
#define st first
#define nd second
#define VI vector<int>
#define pb push_back
using namespace std;

#define int ll
const int inf = 1e9+7;
const int N = 1e5+7;

int n, m;

vector<pair<int, int> > G[N];
vector<int> D[N];

int rep[N];
int skadBfs[N];
int skadDir[N];
int vis[N];
int dist[N];

int Find(int a)
{
    if(a!=rep[a])
        rep[a] = Find(rep[a]);

    return rep[a];
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    rep[a] = b;
}

void bfs(int v, bool zero)
{
    for(int i = 0; i < n; ++i)
    {
        dist[i] = inf;
    }

    queue<int> Q;
    dist[v] = 0;
    Q.push(v);

    while(!Q.empty())
    {
        int v = Q.front();
        Q.pop();

        for(auto it:G[v])
        {
            int u = it.first;

            if(zero && it.second)
                continue;

            if(dist[u]==inf)
            {
                dist[u] = dist[v]+1;
                skadBfs[u] = v;
                Q.push(u);
            }
        }
    }
}

void dfs(int v)
{
    vis[v] = 1;

    for(auto it:D[v])
    {
        if(!vis[it])
        {
            skadDir[it] = v;
            dfs(it);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; ++i)
    {
        rep[i] = i;
    }

    for(int i = 1; i <= m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);

        if(!c)
            Union(a, b);
    }

    bfs(0, 0);

    int d = inf;

    for(int i = 0; i < n; ++i)
    {
        if(Find(i)==Find(n-1))
            d = min(d, dist[i]);
    }

    vector<int> mid;
    set<int> curr, nast;

    for(int i = 0; i < n; ++i)
    {
        if(Find(i)==Find(n-1) && d==dist[i])
        {
            curr.insert(i);
            mid.push_back(i);
        }
    }

    /*for(int i = 0; i < n; ++i)
    {
        cerr << i << " " << dist[i] << " " << Find(i) << endl;
    }

    cerr << curr.size() << endl;*/

    while(curr.find(0)==curr.end())
    {
        int b = inf;

        for(auto v:curr)
        {
            for(auto it:G[v])
            {
                int u = it.first;

                if(dist[v]==dist[u]+1)
                    b = min(b, it.second);
            }
        }

        for(auto v:curr)
        {
            for(auto it:G[v])
            {
                int u = it.first;

                if(dist[v]==dist[u]+1 && b==it.second)
                {
                    nast.insert(u);
                    D[u].push_back(v);
                }
            }
        }

        curr = nast;
        nast.clear();
    }

    dfs(0);
    bfs(n-1, 1);

    int best = -1;

    for(auto it:mid)
    {
        if(!vis[it])
            continue;

        if(best==-1 || dist[it]<dist[best])
            best = it;
    }

    vector<int> ans;

    int c = best;

    while(c)
    {
        ans.push_back(c);
        c = skadDir[c];
    }

    ans.push_back(0);

    reverse(ans.begin(), ans.end());

    c = best;

    while(c!=n-1)
    {
        c = skadBfs[c];
        ans.push_back(c);
    }

    VI digs;

    for(int i = 0; i+1 < ans.size(); ++i)
    {
        int x = inf;

        for(auto it:G[ans[i]])
        {
            if(it.st==ans[i+1])
                x = min(x, it.nd);
        }

        digs.pb(x);
    }

    while(digs.size()>1 && digs.back()==0)
        digs.pop_back();

    reverse(digs.begin(), digs.end());

    for(auto it:digs)
        cout << it;

    cout << endl;

    cout << ans.size() << endl;

    for(auto it:ans)
        cout << it << " ";

    cout << endl;
}