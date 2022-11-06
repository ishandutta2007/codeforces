#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

constexpr int MAXN = 200000 + 9;

int n, m, q;
int ans;
int cnt[MAXN];

void addEdge(int u, int v)
{
    if (u > v)
        std::swap(u, v);
    if (cnt[u] == 0)
        --ans;
    ++cnt[u];
}

void removeEdge(int u, int v)
{
    if (u > v)
        std::swap(u, v);
    --cnt[u];
    if (cnt[u] == 0)
        ++ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int u, v, type;
    cin >> n >> m;
    ans = n;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        addEdge(u, v);
    }
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        cin >> type;
        switch (type)
        {
        case 1:
            cin >> u >> v;
            addEdge(u, v);
            break;
        
        case 2:
            cin >> u >> v;
            removeEdge(u, v);
            break;

        case 3:
            cout << ans << '\n';
            break;
            
        default:
            break;
        }
    }

    return 0;
}