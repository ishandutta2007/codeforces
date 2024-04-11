#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>

#define fab(i, a, b) for(int i = a; i <= b; i++)
#define fdown(i, n) for(int i = n - 1; i >= 0; i--)
#define fr(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef long double ld;
typedef double db;

using namespace std;

void ret(string s)
{
  cout << s;
  exit(0);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    char a[4][100];
    fr(i, 4)
      fr(j, 100)
        a[i][j] = 'a';
    cin >> n;
    a[0][0] = 'a';
    a[1][0] = 'a';
    int k = 1;
    int i = 1;
    while (i + 1 < n)
    {
      a[0][i] += k;
      a[0][i + 1] += k;
      a[1][i] += 3 - k;
      a[1][i + 1] += 3 - k;
      k = 3 - k;
      i += 2;
    }
    if(i == n - 1)
    {
      a[0][n - 1] = 'z';
      a[1][n - 1] = 'z';
    }
    else
    {
      a[2][n - 1] = 'z';
      a[3][n - 1] = 'z';
    }
    i = 0;
    k = 4;
    while (i + 1 < n)
    {
      a[2][i] += k;
      a[2][i + 1] += k;
      a[3][i] += 7 - k;
      a[3][i + 1] += 7 - k;
      k = 7 - k;
      i += 2;
    }
    fr(j, 4)
    {
      fr(h, n)
        cout << a[j][h];
      printf("\n");
    }
}