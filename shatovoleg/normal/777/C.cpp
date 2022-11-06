#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;
using ll = unsigned long long;
using ld = long double;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mtr(n, vector<int>(m));
    for (auto &x : mtr)
        for (auto &y : x)
            cin >> y;
    vector<vector<int>> step(n, vector<int>(m, 0));
    for (int i = n - 2; i >= 0; --i)
        for (int j = 0; j < m; ++j)
            if (mtr[i][j] <= mtr[i + 1][j])
                step[i][j] = step[i + 1][j] + 1;
    vector<int> total_step(n, 0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            total_step[i] = max(total_step[i], step[i][j]);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        r -= l;
        --l;
        if (total_step[l] >= r)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}