#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
int n, Mn;
string A[N];
inline int Get(int i)
{
    int ret = 0;
    for (int j = 0; j < A[i].size(); j++)
    {
        if (A[i][j] != '?')
            ret = ret * 10 + (A[i][j] - '0');
        else
            ret = ret * 10 + 9;
    }
    return (ret);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    for (int i = 1; i <= n; i++)
    {
        if (Get(i) <= Mn)
            return puts("NO");
        for (int j = 0; j < A[i].size(); j++)
        {
            if (A[i][j] != '?')
                continue;
            for (int h = 0; h <= 9; h++)
                if (h || j)
                {
                    A[i][j] = h + '0';
                    if (Get(i) > Mn)
                        break;
                }
        }
        Mn = Get(i);
    }
    puts("YES");
    for (int i = 1; i <= n; i++)
        cout << A[i] << '\n';
}