                            
#include <cmath>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
int mp[30][30], t[30][30], cnt;
int main()
{
    int m, n;
    cin >> m >> n;
    int i, j, k, l;
    for(i = 1 ;i <= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            cin >> mp[i][j];
        }
    }
    int res = 0;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            int ok = 1;
            for(k = 1; k <= m; k++)
            {
                for(l = 1; l <= n; l++)
                {
                    if(l == i)
                    {
                        t[k][l] = mp[k][j];
                    } else if (l == j) {
                        t[k][l] = mp[k][i];
                    } else {
                        t[k][l] = mp[k][l];
                    }
                }
            }
            for(k = 1; k <= m; k++)
            {
                cnt = 0;
                for(l = 1; l <= n; l++)
                {
                    if(t[k][l] != l) cnt++;
                    if(cnt > 2) ok = 0;
                }
            }
            if(ok) res = 1;
        }
    }
    if(res) cout << "YES";
    else cout << "NO";
}