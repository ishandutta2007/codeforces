#include<bits/stdc++.h>
using namespace std;
int k, Construct[510][510], dp1[510][510], dp2[510][510];
string s;
int MakePalindrom(int l, int r)
{
    int c = 0;
    for (int i = l, j = r; i < j; i++, j--)
    {
        if (s[i] != s[j])
        {
            c ++;
        }
    }
    dp2[l][r] = c;
    return (0);
}
int Solve(int n, int r)
{
    if (n == -1)
    {
        dp1[n][r] = 0;
        return (0);
    }
    if (r == 0)
    {
        dp1[n][r] = 1e3;
        return (0);
    }
    int Mn = 1e3, t = 0;
    for (int i = 0; i <= n; i++)
    {
        if (dp2[n - i][n] == -1)
        {
            MakePalindrom(n - i, n);
        }
        t += dp2[n - i][n];
        if (dp1[n - i - 1][r - 1] == -1)
        {
            Solve(n - i - 1, r - 1);
        }
        t += dp1[n - i - 1][r - 1];
        if (t < Mn)
        {
            Mn = t;
            Construct[n][r] = n - i - 1;
        }
        t = 0;
    }
    dp1[n][r] = Mn;
    return (0);
}
int Print(int n, int r)
{
    int i, j;
    string t = "", p;
    for (i = Construct[n][r] + 1, j = n; i < j; i++, j--)
    {
        t += s[i];
    }
    p = t;
    if (j == i)
    {
        t += s[i];
    }
    reverse(p.begin(), p.end());
    t += p;
    if (Construct[n][r] != -1)
    {
        Print(Construct[n][r], r - 1);
        cout << "+" << t;
        return (0);
    }
    cout << t;
    return (0);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> k;
    for (int i = 0; i <= 500; i++)
    {
        for (int j = 0; j <= 500; j++)
        {
            dp1[i][j] = dp2[i][j] = -1;
        }
    }
    Solve((int)s.size() - 1, k);
    cout << dp1[(int)s.size() - 1][k] << "\n";
    Print((int)s.size() - 1, k);
    return (0);
}