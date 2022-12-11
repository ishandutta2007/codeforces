#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    int x[3] = {0}, y[3] = {0};
    int kol = 0;

    cin >> n >> m;
    string s;
    for (int i = 1; i <= n; i++)
    {
      cin >> s;
      //cout << s << endl;
      for (int j = 0; j < s.length(); j++)
        if (s[j] == '*')
          {
            kol++;
            x[kol - 1] = j + 1;
            y[kol - 1] = i;
          }
    }
    sort(x, x + 3);
    sort(y, y + 3);
    if (y[1] == y[0]) cout << y[2]; else cout << y[0];
    if (x[1] == x[0]) cout << " " << x[2]; else cout << " " << x[0];
    return 0;
}