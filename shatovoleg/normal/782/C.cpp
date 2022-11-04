#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> list_gr;
vector<int> clr;
int color_size = 1;

void solve(int v, int p = -1)
{
    int n = list_gr.size();
    if (p == -1)
    {
        for (int i = 0; i < list_gr[v].size(); ++i)
        {
            clr[list_gr[v][i]] = i + 1;
            solve(list_gr[v][i], v);
        }
        return;
    }
    int j = 0;
    for (int i = 0; j < list_gr[v].size(); ++i)
    {
        if (list_gr[v][j] == p)
            ++j;
        if (j >= list_gr[v].size())
            break;
        if (i != clr[v] && i != clr[p])
        {
            clr[list_gr[v][j]] = i;
            solve(list_gr[v][j], v);
            ++j;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    list_gr.resize(n);
    clr.resize(n, -1);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        list_gr[x].push_back(y);
        list_gr[y].push_back(x);
    }
    for (auto &x : list_gr)
        color_size = max(color_size, (int)x.size());
    if (color_size == 1)
    {
        cout << color_size << endl;
        for (int i = 0; i < n; ++i)
            cout << 1 << " ";
        cout << endl;
        return 0;
    }
    clr[0] = 0;
    solve(0);
    cout << color_size + 1 << endl;
    for (auto x : clr)
        cout << x + 1 << " ";
    cout << endl;
}