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

long long gcd(long long a, long long b)
{
  if (a % b == 0) return b; else return gcd(b, a % b);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    long long n, k, p;
    cin >> n;
    fr(i, n)
    {
      cin >> k;
      p = gcd(k + 1, 4 * k);
      p = 4 * k / p;
      cout << p + 1;
      printf("\n");
    }
    return 0;
}