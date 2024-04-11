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

void rent(int a)
{
  cout << a;
  exit(0);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int a[100000], n;
    cin >> n;
    fab(i, 1, n)
      {cin >> a[i]; a[i] = a[i] % 2;}
    a[0] = a[n];
    a[n + 1] = a[1];
    fab(i, 1, n)
      if (a[i - 1] == a[i + 1] && a[i - 1] != a[i])
        rent(i);
    return 0;
}