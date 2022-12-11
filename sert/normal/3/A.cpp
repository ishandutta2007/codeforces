#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>

#define fab(i, a, b) for(int i = a; i < b; i++)
#define fdown(i, n) for(int i = n - 1; i >= 0; i--)
#define fr(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef long double ld;
typedef double db;

using namespace std;

struct dbl
{
  int a, b;
};

bool _less(dbl a, dbl b)
{
  if (a.a != b.a)
    return a.a < b.a;
  return a.b < b.b;
}

void ret(string s)
{
  cout << s;
  exit(0);
}

bool more(string s, string k)
{
  if (s.length() != k.length())
    return s.length() > k.length();
  return s > k;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s, k;
    int x, y;
    cin >> s >> k;
    x = k[0] - s[0];
    y = k[1] - s[1];
    printf("%d\n", max(abs(x), abs(y)));
    while(x != 0 || y != 0)
    {
      if (x == 0 && y > 0) {y--; printf("U\n");} else
      if (x == 0 && y < 0) {y++; printf("D\n");} else
      if (x > 0 && y == 0) {x--; printf("R\n");} else
      if (x < 0 && y == 0) {x++; printf("L\n");} else
      if (x > 0 && y > 0) {y--; x--; printf("RU\n");} else
      if (x < 0 && y > 0) {y--; x++; printf("LU\n");} else
      if (x > 0 && y < 0) {y++; x--; printf("RD\n");} else
      if (x < 0 && y < 0) {y++; x++; printf("LD\n");}
    }
    return 0;
}