#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, NX = 1e9 + 7;
int n, r, t, p, c, m, k;
string A[N];
int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
    {
        c = 0;
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == '*')
            {
                c = 0;
                continue;
            }
            c ++;
            if (c >= k)
                r ++;
        }
    }
    if (k == 1)
        return !printf("%d", r);
    c = 0;
    for (int i = 0; i < m; i++)
    {
        c = 0;
        for (int j = 0; j < n; j++)
        {
            if (A[j][i] == '*')
            {
                c = 0;
                continue;
            }
            c ++;
            if (c >= k)
                r ++;
        }
    }
    printf("%d", r);
    return (0);
}