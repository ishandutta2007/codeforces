#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <complex>
#include <fstream>

using namespace std;
using pii = pair<int, int>;
using ll = unsigned long long;
using ld = long double;

int count_max_level(string s)
{
    int cur_lvl = 0, mx = 0;
    for (auto x : s)
    {
        if (x == '[')
            ++cur_lvl;
        else
            --cur_lvl;
        mx = max(mx, cur_lvl);
    }
    return mx;
}

void draw_scope(int x, int lvl, bool opens, int mx_lvl, vector<vector<char>> &fld)
{
    fld[lvl][x] = '+';
    mx_lvl -= lvl;
    mx_lvl *= 2;
    fld[lvl + mx_lvl][x] = '+';
    if (opens)
    {
        fld[lvl][x + 1] = '-';
        fld[lvl + mx_lvl][x + 1] = '-';
    }
    else
    {
        fld[lvl][x - 1] = '-';
        fld[lvl + mx_lvl][x - 1] = '-';
    }
    for (int i = lvl + 1; i < lvl + mx_lvl; ++i)
        fld[i][x] = '|';
}

void print(vector<vector<char>> &fld)
{
    int mx_x = 0, mx_y = 0;
    for (int i = 0; i < 1000; ++i)
        for (int j = 0; j < 1000; ++j)
            if (fld[i][j] != ' ')
            {
                mx_x = max(mx_x, i);
                mx_y = max(mx_y, j);
            }
    for (int i = 0; i <= mx_x; ++i)
    {
        for (int j = 0; j <= mx_y; ++j)
            cout << fld[i][j];
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin  >> s;
    vector<vector<char>> fld(1000, vector<char>(1000, ' '));
    int lvl = count_max_level(s);
    int x = 0, cur_lvl = 0;
    draw_scope(x, cur_lvl, 1, lvl, fld);
    ++cur_lvl;
    for (int i = 1; i < n; ++i)
    {
        if (s[i] == ']')
            --cur_lvl;
        ++x;
        if (s[i] == ']' && s[i - 1] == '[')
            x += 3;
        draw_scope(x, cur_lvl, s[i] == '[', lvl, fld);
        if (s[i] == '[')
            ++cur_lvl;
    }
    print(fld);
}