#include <bits/stdc++.h>
using namespace std;

int main()
{
    char rect[1005][1005];
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++)
            rect[i][j] = s[j];
    }
    pair<int, int> dir[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    vector<pair<int, int>> v;
    for(int i = 1; i < n - 1; i++)
    {
        for(int j = 1; j < m - 1; j++)
        {
            //cout << rect[i][j];
            bool b = true;
            for(pair<int, int> d : dir)
            {
                if(rect[i + d.first][j + d.second] == '.')
                {
                    //cout << i << " " << j << " " << d.first << " " << d.second << endl;
                    b = false;
                    break;
                }
            }
            if(!b)
                continue;
            v.push_back({i , j});
        }
        //cout << endl;
    }
    for(pair<int, int> p : v)
    {
        //cout << p.first << " " << p.second << endl;
        for(pair<int, int> d : dir)
        {
            rect[p.first + d.first][p.second + d.second] = '.';
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(rect[i][j] == '#')
            {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}