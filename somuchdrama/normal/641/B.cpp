#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, m, i, j, q;
    cin >> n >> m >> q;
    pair < pair <int, int> , int> arr[n][m];
    int cnt = 1;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            arr[i][j].first.first = i;
            arr[i][j].first.second = j;
            arr[i][j].second = cnt;
            cnt++;
        }
    }

    //go go go
    for(i = 0; i < q; i++)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int row;
            pair < pair <int, int> , int> last, tmp;
            cin >> row;
            row--;
            last = arr[row][m - 1];
            arr[row][m - 1] = arr[row][0];
            for(j = m - 2; j >= 0; j--)
            {
                tmp = arr[row][j];
                arr[row][j] = last;
                last = tmp;
            }
        }
        else if(type == 2)
        {
            int col;
            pair < pair <int, int> , int> last, tmp;
            cin >> col;
            col--;
            last = arr[n - 1][col];
            arr[n - 1][col] = arr[0][col];
            for(j = n - 2; j >= 0; j--)
            {
                tmp = arr[j][col];
                arr[j][col] = last;
                last = tmp;
            }
        }
        else if(type == 3)
        {
            int x, y, nova;
            cin >> x >> y >> nova;
            //cout << "azaza " << x - 1 << " " << y - 1 << ", " << arr[x - 1][y - 1].second << " " << nova << endl;
            arr[x - 1][y - 1].second = nova;
        }
    }

    //cout << "herre";
    /*for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            cout << arr[i][j].second << " ";
        cout << endl;
    }*/

    //output;
    int new_arr[n][m];
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            //cout << "boom";
            new_arr[arr[i][j].first.first][arr[i][j].first.second] = arr[i][j].second;
        }
    }


    //out
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            cout << new_arr[i][j] << " ";
        cout << endl;
    }
    return 0;
}