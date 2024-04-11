#include <iostream>

using namespace std;

int main()
{
    long int l[101], r[101], t[101], c[101], n, m, i, time, cost, num, j, k, ii, epic_win_money=0;
    cin >> m >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i] >> t[i] >> c[i];
    }

    for (i = 1; i <= m; i++)
    {
      time = 100500;
      cost = 0;
      num = 0;
      for (j = 1; j <= n; j++)
        if ((i >= l[j])&&(i <= r[j]))
          if (t[j] < time)
          {
            cost = c[j];
            time = t[j];
          }
      epic_win_money = epic_win_money + cost;
    }
    cout << epic_win_money;
    return 0;
}