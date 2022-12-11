#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, l, c, d, p, nl, np;
    int a[1001] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &k);
      a[k] ++;
    }
    sort(a + 1, a + 1001);
    printf("%d ", a[1000]);
    for (int i = 1; i <= 1000; i++)
      if (a[i] != 0)
      {
        printf("%d", 1001 - i);
        return 0;
      }
    return 0;
}