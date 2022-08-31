#include <iostream>

using namespace std;

int main()
{
   int n, m;
   char blah[110][110];
   cin >> n >> m;
   for (int i = 0; i < n; i++)
       for (int j = 0; j <m; j++)
       cin >> blah[i][j];
       bool good[110][110];
       for (int i = 0; i < 110; i++)
       for (int j = 0; j < 110; j++)
       good[i][j] = true;
       for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++)
       {
       for (int k = 0; k < n; k++)
       if (blah[k][j] == blah[i][j] && i != k)
       good[i][j] = false;
       for (int k = 0; k < m; k++)
       if (blah[i][k] == blah[i][j] && k != j)
       good[i][j] = false;
       if (good[i][j])
       cout << blah[i][j];
       }
       cout << "\n";
       return 0;
       }