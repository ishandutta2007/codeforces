#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>

#define fab(i, a, b) for(int i = a; i <= b; i++)
#define fdown(i, n) for(int i = n - 1; i >= 0; i--)
#define fr(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef long double ld;
typedef double db;

using namespace std;

void ret(string s)
{
  cout << s;
  exit(0);
}

string s;
int n, m, p, k, mx = 0, kol = 0, mn = 0, len = 0;
int a[300000], b[1000000], u[1000] = {false};

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    fr(i, m)
        cin >> a[i];
    sort(a, a + m);
    fr(i, m)
    {
        for (int j = a[i]; j > 0; j--)
        {
            if (kol == n) break;
            kol++;
            mn += j;
        }
        if (kol == n) break;
    }
    for (int i = 0; i < m; i++)
        for (int j = 1; j <= a[i]; j++)
            b[len++] = j;
    sort(b, b + len);
    for (int i = len - 1; i >= len - n; i--)
        mx += b[i];
    cout << mx << " " << mn;
}
/*cin >> n >> m;
    fr(i, m)
        cin >> a[i];
    sort(a, a + m);
    fr(i, m)
    {
        for (int j = a[i]; j > 0; j--)
        {
            if (kol == n) break;
            kol++;
            mn += j;
        }
        if (kol == m) break;
    }
    for (int i = 0; i < m; i++)
        for (int j = 1; j <= a[i]; j++)
            b[len++] = j;
    sort(b, b + len);
    for (int i = len - 1; i >= len - n; i--)
        mx += b[i];
    cout << mx << " " << mn;*/