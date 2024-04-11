
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, k;
    char ch;
    string a[100];
    int kol = 0, n, m, max;
    bool fail, good;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
      fail = false;
      good = false;
      for (int j = 0; j < m; j++)
      {
        fail = false;
        for (int p = 0; p < n; p++)
        {
          if (a[p][j] > a[i][j])
            {fail = true;}
        }
        if (!fail)
          good = true;
      }
      if (good)
        kol++;
    }
    cout << kol;
    return 0;
}