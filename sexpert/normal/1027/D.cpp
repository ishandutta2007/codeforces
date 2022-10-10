#include <bits/stdc++.h>
using namespace std;

int n;
int son[200005];
int W[200005];
set<int> sources;
vector<int> vist(200005, -1);
vector<int> best(200005, -1);

int dfs(int source)
{
    vist[source] = 0;
    int v = son[source];
    if(vist[v] == -1)
    {
        best[source] = dfs(v);
        return best[source];
    }
    else
    {
        if(best[v] != -1)
        {
            best[source] = best[v];
            return best[source];
        }
        else
        {
            int bestwt = W[source];
            int bestguy = source;
            while(v != source)
            {
                if(W[v] < bestwt)
                {
                    bestguy = v;
                    bestwt = W[v];
                }
                v = son[v];
            }
            best[source] = bestguy;
            return bestguy;
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> W[i + 1];
        sources.insert(i + 1);
    }
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        son[i] = x;
    }
    set<int> goodguys;
    for(auto s : sources) goodguys.insert(dfs(s));
    long long ans = 0;
    for(auto v : goodguys) ans += W[v];
    cout << ans;
}