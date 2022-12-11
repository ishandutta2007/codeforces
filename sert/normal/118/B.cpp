#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j < n - i ; j++)
        printf("  ");
      printf("0");
      for (int j = 1; j <= i; j++)
        printf(" %d", j);
      for (int j = i - 1; j >= 0; j--)
        printf(" %d", j);

      printf("\n");
    }
    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = 0; j < n - i ; j++)
        printf("  ");
      printf("0");
      for (int j = 1; j <= i; j++)
        printf(" %d", j);
      for (int j = i - 1; j >= 0; j--)
        printf(" %d", j);
      printf("\n");
    }
    return 0;
}