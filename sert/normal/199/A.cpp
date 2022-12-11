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
    cin >> n;
    if (n == 2) ret("0 1 1");
    if (n == 1) ret("0 0 1");
    if (n == 0) ret("0 0 0");
    if (n == 3) ret("1 1 1");
    int a[10000] = {0};
    int i = 1;
    a[0] = 1;
    a[1] = 1;
    while (a[i] != n)
    {
      i++;
      a[i] = a[i - 1] + a[i - 2];
    }
    cout << a[i - 1] << " " << a[i - 3] << " " << a[i - 4];
    return 0;
}