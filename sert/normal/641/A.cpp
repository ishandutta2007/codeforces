#include <bits/stdc++.h>

using namespace std;

int a[200000], use[200000];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1 ; i <= n; i++)
    {
        cin >> a[i];
        if (s[i - 1] == '<') a[i] *= -1;
    }
    int p = 1;
    while (1)
    {
        if (p < 1 || p > n)
        {
            cout << "FINITE";
            return 0;
        }
        use[p]++;
        if (use[p] > 1)
        {
            cout << "INFINITE";
            return 0;
        }
        p += a[p];
    }
    return 0;
}