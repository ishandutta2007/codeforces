#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long loc[200001];
long long ans;

bool works (long long d)
{
     long long start = 0, end = 0;
     bool check = true;
     for (int a = 0; a < n - 1; a++)
     {
         if (!check)
            continue;
         if (loc[a] <= loc[0] + d && loc[a+1] > loc[0] + d)
         {
            start = loc[a+1];
            check = false;
         }
     }
     check = true;
     for (int a = n - 1; a >= 1; a--)
     {
         if (!check)
            continue;
         if (loc[a] >= loc[n-1] - d && loc[a-1] < loc[n-1] - d)
         {
            end = loc[a-1];
            check = false;
         }
     }
     if ((end - start) <= d)
     {
        ans = end + start;
        return true;
     }
     return false;
}

void print (long long a)
{
     if (a % 2 == 0)
       cout << a / 2 << ".000000";
     else
        cout << a / 2 << ".500000";
     return;
}

int main()
{
    cin >> n;
    for (int a = 0; a < n; a++)
        cin >> loc[a];
    sort (loc, loc + n);
    long long d;
    long long min = 0;
    long long max = (loc[n-1] - loc[0]) / 2;
    while (min != max)
    {
          d = (min + max) / 2;
          if (works (d))
             max = d;
          else
              min = d;
          if (min == max - 1)
             if (!works(min))
             {
                min++;
                max++;
             }
    }
    print (min);
    cout << endl;
    print (min + 2 * loc[0]);
    cout << " ";
    print (ans);
    cout << " ";
    print (2 * loc[n-1] - min);
    //system ("Pause");
}