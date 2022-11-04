#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <complex>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <cmath>

using namespace std;
using ld = float;

vector<vector<int>> list_gr;
vector<bool> vst;

ld dfs(int v)
{
    ld cnt = 1;
    vst[v] = true;
    for (auto x : list_gr[v])
        if (!vst[x])
            cnt += dfs(x);
    return cnt;
}

int main()
{
    int n;
    ld m;
    cin >> n >> m;
    list_gr.resize(n);
    vst.resize(n, false);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        list_gr[x].push_back(y);
        list_gr[y].push_back(x);
    }
    ld cnt = 0;
    for (int i = 0; i < n; ++i)
        if (!vst[i])
        {
            ld v = dfs(i);
            cnt += (v * (v - 1)) / 2;
        }
    if (cnt == m)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}