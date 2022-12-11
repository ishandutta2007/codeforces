#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

void ret(string s)
{
  cout << s;
  exit(0);
}

int a[2001], n, ans = 0, mx, nm;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        mx = 1;
        nm = i;
        while (a[nm] != -1)
        {
          mx++;
          nm = a[nm];
        }
        ans = max(ans, mx);
    }
    cout << ans;
    return 0;
}