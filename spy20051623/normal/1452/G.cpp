#include<bits/stdc++.h>

using namespace std;

const int N = 200043;
const int LN = 18;

vector<int> g[N];
vector<int> dist[N];
int sz[N];
int par[N];
bool used[N];
int max_dist[N];
vector<int> val[N];

int calc_size(int x, int p = -1)
{
    sz[x] = 1;
    for(auto y : g[x])
        if(y != p && !used[y])
            sz[x] += calc_size(y, x);
    return sz[x];   
}

int find_centroid(int x, int p, int s)
{
    int ans = -1;
    bool good = true;
    for(auto y : g[x])
        if(y != p && !used[y])
            good &= sz[y] * 2 <= s;
        else if(y == p && !used[y])
            good &= (s - sz[x]) * 2 <= s;
    if(good)
        ans = x;
    for(auto y : g[x])
        if(y != p && !used[y])
            ans = max(ans, find_centroid(y, x, s));
    return ans;
}

void calc_dist(int x, int p, int d, int s)
{
    dist[x].push_back(d);
    for(auto y : g[x])
        if(y != p && !used[y])
            calc_dist(y, x, d + 1, s);
    max_dist[s] = max(max_dist[s], d);  
}

int decomposition(int v)
{
    calc_size(v);
    int c = find_centroid(v, v, sz[v]);
    used[c] = true;
    for(auto y : g[c])
        if(!used[y])
        {
            par[decomposition(y)] = c;
        }
    used[c] = false;
    calc_dist(c, c, 0, c); 
    return c;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    decomposition(0);
    for(int i = 0; i < n; i++)
        val[i].resize(max_dist[i] + 1);    
    int k;
    scanf("%d", &k);
    vector<int> d(n, int(1e9));
    queue<int> q;
    for(int i = 0; i < k; i++)
    {
        int x;
        scanf("%d", &x);
        --x;
        q.push(x);
        d[x] = 0;
    }
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(auto y : g[x])
            if(d[y] > d[x] + 1)
            {
                q.push(y);
                d[y] = d[x] + 1;
            }
    }
    for(int i = 0; i < n; i++)
    {
        if(d[i] == 0) continue;
        
        int curc = i;
        for(int j = 0; j < dist[i].size(); j++)
        {
            int dd = dist[i][j];
            if(dd > d[i] - 1)
            {
                curc = par[curc];
                continue;
            }
            dd = d[i] - 1 - dd;
            if(dd >= val[curc].size())
                dd = val[curc].size() - 1; 
            val[curc][dd] = max(val[curc][dd], d[i]);
            curc = par[curc];
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = max_dist[i]; j >= 1; j--)
            val[i][j - 1] = max(val[i][j], val[i][j - 1]);
    for(int i = 0; i < n; i++)
    {
        int ans = 0; 
        int curc = i;
        for(int j = 0; j < dist[i].size(); j++)
        {
            int dd = dist[i][j];
            ans = max(ans, val[curc][dd]);
            curc = par[curc];
        }
        if(d[i] == 0)
            ans = 0;
        printf("%d%c", ans, " \n"[i == n - 1]);
    }
}