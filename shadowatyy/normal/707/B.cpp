#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000000
#define INF 1000000000000000000LL
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define REP(x, y) for(int x = 0; x < (y); ++x)
using namespace std;

#define N 100007

ll n, m, k, a, b, c, result = INF;

vector<pair<int, ll> > G[N];

ll dist[N];

struct comp
{
    bool operator()(const int &a, const int &b)
    {
        return dist[a]>=dist[b];
    }
};

priority_queue<int, vector<int>, comp> Q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m >> k;

    while(m--)
    {
        cin >> a >> b >> c;

        G[a].eb(b, c);
        G[b].eb(a, c);
    }

    for(int i = 1; i <= n; ++i)
    {
        dist[i] = INF;
    }

    while(k--)
    {
        cin >> a;

        dist[a] = 0;

        Q.push(a);
    }

    while(!Q.empty())
    {
        int v = Q.top();
        Q.pop();

        for(auto it:G[v])
        {
            if(dist[it.st]>dist[v]+it.nd)
            {
                dist[it.st] = dist[v]+it.nd;
                Q.push(it.st);
            }
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        if(dist[i])
        {
            result = min(result, dist[i]);
        }
    }

    if(result==INF)
    {
        cout << -1;
    }
    else
    {
        cout << result;
    }

}