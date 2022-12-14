# include <iostream>
# include <string>
#include <cstdio>
#include <iomanip>
#include <queue>
# include <stack>
#include <ios>
using namespace std;
bool vis[1000000][2];
bool check(string s, int n, int k)
{
    for (int i = k; i < n; i++)
    {
        if (s[i] != s[i - k])
            return 0;
    }
    return 1;
}
void get(string s, int n,bool p)
{
    for (int i = 2; i <= n; i++)
    {
        if (n%i != 0)
            continue;
        if (check(s, n, n / i))
        {
            vis[n / i -1][p] = 1;
        }
    }
}
int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();
    vis[n - 1][0] = 1;
    vis[m - 1][1] = 1;
    get(a, n, 0);
    get(b, m, 1);
    int i = 0;
    int ans = 0;
    while (i < n && i < m && a[i]==b[i])
    {
        if (vis[i][0] == 1 && vis[i][1]==1)
            ans++;
        i++;
    }
    cout << ans << endl;
}