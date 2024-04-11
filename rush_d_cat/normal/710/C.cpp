#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
int map[52][52], used[52][52];
int main()
{
    int n, i, j; cin >> n;
    int row = 1, col = (n + 1) / 2, row_, col_;
    used[row][col] = 1;
    map[row][col] = 1;
    int cnt = 1;
    while(1)
    {
        row_ = row + 1;
        col_ = col;
        row --; col ++;
        if(row == 0) row += n;
        if(col == n + 1) col -= n;
        if(!used[row][col]) {map[row][col] = ++cnt;used[row][col] = 1;}
        else{ map[row_][col_] = ++cnt;used[row_][col_] = 1;row = row_;col=col_;}
        if(cnt >= n * n) break;
    }

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            cout << map[i][j];
            if(j == n) cout << endl;
            else cout << " ";
        }
    }

}