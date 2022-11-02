#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
int P[5005][5005], n, C[5005];
vector < pair < int , int > > V;
string s;
int DFS(int r, int t, int c)
{
    C[c] ++;
    if (2 * t - r > 5000)
        return (0);
    if (P[r][2 * t - r] == 1)
        DFS(r, 2 * t - r, c + 1);
    if (P[r][2 * t - r + 1] == 1)
        DFS(r, 2 * t - r + 1, c + 1);
    return (0);
}
int main()
{
    cin >> s;
    n = (int)s.size();
    for (int i = 0; i < n; i++)
    {
        P[i][i] = P[i][i + 1] = 1;
        V.push_back(make_pair(i, i + 1));
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            if (s[j] == s[j + i - 1] && P[j + 1][j + i - 1] == 1)
            {
                P[j][j + i] = 1;
                if (P[j][j + i / 2] == 0)
                    V.push_back(make_pair(j, j + i));
            }
        }
    }
    for (int i = 0; i < (int)V.size(); i++)
        DFS(V[i].x, V[i].y, 1);
    for (int i = n; i > 0; i--)
        C[i] += C[i + 1];
    for (int i = 1; i <= n; i++)
        printf("%d ", C[i]);
    return (0);
}