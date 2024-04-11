#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 2;
vector<int> adj[MAXN];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long n, m;
    cin >> n >> m;
    vector<long long> x, y, d, partiald, sd;
    long long sumx = 0;
    for(int i = 0; i < n; i++)
    {
        long long a, b;
        cin >> a >> b;
        sumx += a;
        x.push_back(a);
        y.push_back(b);
        d.push_back(b - a);
    }
    sd = d;
    sort(sd.begin(), sd.end());
    long long dsum = 0;
    for(int i = 0; i < n; i++)
    {
        partiald.push_back(dsum);
        dsum += sd[i];
    }
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    for(int i = 0; i < n; i++)
    {
        long long cool = (n - 2)*x[i] + sumx;
        for(auto j : adj[i])
        {
            cool -= (x[i] + x[j] + min(d[i], d[j]));
        }
        auto it = lower_bound(sd.begin(), sd.end(), d[i]);
        int amt = it - sd.begin();
        cool += partiald[amt];
        cool += (n - amt - 1)*d[i];
        cout << cool << " ";
    }
    cout << "\n";
}