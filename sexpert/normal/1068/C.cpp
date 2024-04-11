#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> squares[105];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        squares[i].push_back({i, i});
    }
    int ht = n + 1;
    for(int i = 0; i < m; i++, ht++)
    {
        int x, y;
        cin >> x >> y;
        squares[x].push_back({x, ht});
        squares[y].push_back({y, ht});
    }
    for(int i = 1; i <= n; i++)
    {
        cout << squares[i].size() << endl;
        for(auto p : squares[i])
            cout << p.first << " " << p.second << endl;
    }
}