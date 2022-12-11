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
    int x, ans = 0, kol;
    cin >> x;
    if (x == 3) {cout << 5; return 0;}
    fab(i, 1, 300)
    {
      if (i % 2 == 0) continue;
      if (x <= (i * i + 1) / 2) {cout << i; return 0;}
    }
    return 0;
}