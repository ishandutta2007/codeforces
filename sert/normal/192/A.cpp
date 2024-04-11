#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>

//#define for(i, n) for(int i = 0; i < n; i++)
#define fab(i, a, b) for(int i = a; i < b; i++)
#define fdown(i, n) for(int i = n - 1; i >= 0; i--)
typedef long long ll;
typedef long double ld;
typedef double db;

using namespace std;

void ret(string s)
{
  cout << s;
  exit(0);
}

int a[100000], m, kol = 0, sum, k, i;
long long n;
string s;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> k;
    n = 3;
    a[1] = 1;
    i = 1;
    while (n <= k)
    {
      i++;
      a[i] = n;
      n = (i + 1) * (i + 2) / 2;
    }
    for (int j = 1; j <= i; j++)
      for (int ii = 1; ii <= i; ii++)
        if (a[j] + a[ii] == k)
          ret("YES");
    cout << "NO";
    return 0;
}