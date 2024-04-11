#include<bits/stdc++.h>
using namespace std;
int n, m, r, t, k, PS[105][105], PR[105][105], opt[105][105], dp[2][10005];
//map < pair < int , int > , int > M;
vector < int > A[105];
/*int Solve(int p, int s)
{
    if (p == 0)
    {
        return (0);
    }
    if (M.count(make_pair(p, s)) != 0)
    {
        return (M[make_pair(p, s)]);
    }
    int Mx = 0;
    for (int i = 0; i <= min((int)A[p].size(), s); i++)
    {
        Mx = max(Mx, Solve(p - 1, s - i) + opt[p][i]);
    }
    M[make_pair(p, s)] = Mx;
    return (Mx);
}*/
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &r);
        for (int j = 1; j <= r; j++)
        {
            scanf("%d", &t);
            A[i].push_back(t);
            PS[i][j] = PS[i][j - 1] + t;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= A[i].size(); j++)
        {
            PR[i][j] = PR[i][j - 1] + A[i][A[i].size() - j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= min((int)A[i].size(), m); j++)
        {
            for (int h = 0; h <= j; h++)
            {
                opt[i][j] = max(opt[i][j], PS[i][h] + PR[i][j - h]);
            }
            //cout << i << " " << j << " " << opt[i][j] << "\n";
        }
    }
    //cout << ":::::::::::\n";
    /*for (int i = 0; i <= min((int)A[1].size(), m); i++)
    {
        dp[1][i] = opt[1][i];
    }*/
    for (int i = 1; i <= n; i++)
    {
        k += A[i].size();
        for (int j = 0; j <= min(k, m); j++)
        {
            for (int h = 0; h <= min((int)A[i].size(), j); h++)
            {
                dp[i % 2][j] = max(dp[i % 2][j], dp[(i + 1) % 2][j - h] + opt[i][h]);
            }
            //cout << i << " " << j << " " << dp[i % 2][j] << "\n";
        }
    }
    printf("%d", dp[n % 2][m]);
    //printf("%d", Solve(n, m));
    return (0);
}