#include<iostream>
#include<algorithm>
#include<cstring>
#include<string.h>
using namespace std;
typedef __int64 ll;
ll map[502][502];
ll row[502],col[502];
int r_, c_;
int main()
{
    int n, i, j; ll res = 0;
    cin >> n;
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            cin >> map[i][j];
            row[i] += map[i][j];
            col[j] += map[i][j];
            if(map[i][j] == 0)
            {
                r_ = i;
                c_ = j;
            }
        }
    }
    if(n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    sort(row + 1 ,row + 1 + n);
    sort(col + 1, col + 1 + n);
    if(row[2] != row[n]) res = -1;
    if(col[2] != col[n]) res = -1;
    if(col[n] - col[1] != row[n] - row[1]) res = -1;
    if(res == -1){
        cout << -1 << endl;
        return 0;
    }
    res = row[2] - row[1];
    map[r_][c_] = res;
    ll k1 = 0, k2 = 0;
    for(i = 1; i <= n; i++)
    {
        k1 += map[i][i];
        k2 += map[i][n - i + 1];
    }
    if(!(k1 == row[n] && k2 == row[n]))
    {
        cout << -1 << endl;
        return 0;
    }
    if(res <= 0)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << res << endl;
}