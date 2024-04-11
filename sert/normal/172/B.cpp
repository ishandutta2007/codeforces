#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ost[100000] = {0};
    int a, b, r[100001], m;
    cin >> a >> b >> m >> r[0];
    ost[r[0]] = 1;
    int t = r[0];
    int pos = 1;
    while (1 < 2)
    {
      pos++;
      t = (t * a + b) % m;
      if (ost[t] != 0)
      {
        cout << pos - ost[t];
        return 0;
      }
      ost[t] = pos;
      //cout << t << " ";
    }

    return 0;
}