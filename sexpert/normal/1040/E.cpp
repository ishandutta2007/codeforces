#include <bits/stdc++.h>

using namespace std;
long long n, m, k;
const long long MOD = 1000000007;
vector<int> p(500005, -1);
map<long long, vector<pair<int, int>>> edges;


int comp(int x)
{
    return(p[x]==-1 ? x : p[x] = comp(p[x]));
}

bool join(int i, int j)
{
    int a = comp(i), b = comp(j);
    bool con = (a == b);
    if(!con)
    {
        if(a > b) p[a] = b;
        else p[b] = a;
    }
    return con;
}

long long unionFind(long long val)
{
    vector<int> used;
    vector<pair<int, int>> E = edges[val];
    long long num = n;
    for(auto p : E)
    {
        int i = p.first, j = p.second;
        used.push_back(i);
        used.push_back(j);
        if(!join(i, j)) num--;
    }
    for(auto v : used) p[v] = -1;
    return num;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin >> n >> m >> k;
    long long c[500005];
    long long twopow[500005];
    set<long long> xorvals;
    for(int i = 0; i < n; i++) cin >> c[i+1];
    for(int i = 0; i < m; i++)
    {
        int p, q;
        cin >> p >> q;
        xorvals.insert(c[p]^c[q]);
        edges[c[p]^c[q]].push_back(make_pair(p, q));
    }
    twopow[0] = 1ll;
    for(int i = 0; i < 500000; i++)
    {
        twopow[i + 1] = (2ll*twopow[i])%MOD;
    }
    long long ans = (twopow[n]*((twopow[k] - xorvals.size() + MOD)%MOD))%MOD;
    for(auto val : xorvals)
    {
        ans = (ans + twopow[unionFind(val)])%MOD;
    }
    cout << ans << endl;
}