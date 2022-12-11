#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, l, c, d, p, nl, np;
    long long a[100001] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &k);
      a[k + 10]++;
    }
    long long kol = 0;
    for (int i = 0; i <= 20; i++)
      kol += a[i] * a[20 - i];
    kol -= a[10];
    cout << kol / 2;
    return 0;
}