#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char board[105][105];
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++)
            board[i][j] = s[j];
    }
    vector<pair<int, int>> dir = {{0, 0}, {1, 0}, {1, -1}, {1, 1}, {2, 0}};
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == '#')
            {
                for(auto d : dir)
                {
                    int ni = i + d.first, nj = j + d.second;
                    if(ni < 0 || ni >= n || nj < 0 || nj >= n || board[ni][nj] == '.')
                    {
                        cout << "NO\n";
                        return 0;
                    }
                    board[ni][nj] = '.';
                }
            }
        }
    }
    cout << "YES\n";
    return 0;
}