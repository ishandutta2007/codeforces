#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;
using pii = pair<int, int>;

bool check(int v, vector<pii> edges)
{
    for (auto x : edges)
        if (x.first != v && x.second != v)
            return false;
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<pii> edges;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        edges.push_back({x - 1, y - 1});
    }
    vector<int> color(n);
    for (auto &x : color)
        cin >> x;
    vector<pii> ed;
    for (auto x : edges)
        if (color[x.first] != color[x.second])
            ed.push_back(x);
    if (!ed.size())
    {
        cout << "YES\n1" << endl;
        return 0;
    }
    if (check(ed[0].first, ed))
    {
        cout << "YES" << endl << ed[0].first + 1 << endl;
        return 0;
    }
    if (check(ed[0].second, ed))
    {
        cout << "YES" << endl << ed[0].second + 1 << endl;
        return 0;
    }
    cout << "NO" << endl;
}