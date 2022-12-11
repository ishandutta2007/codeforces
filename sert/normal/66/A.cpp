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

    string s;
    cin >> s;
    if (s[0] == '-' && more(s ,"-9223372036854775808"))
      ret("BigInteger");
    if (s[0] != '-' && more(s , "9223372036854775807"))
      ret("BigInteger");
    if (s[0] == '-' && more(s , "-2147483648"))
      ret("long");
    if (s[0] != '-' && more(s , "2147483647"))
      ret("long");
    if ((s[0] == '-' && more(s , "-32768")))
      ret("int");
    if (s[0] != '-' && more(s , "32767"))
      ret("int");
    if ((s[0] == '-' && more(s , "-128")))
      ret("short");
    if (s[0] != '-' && more(s , "127"))
      ret("short");
    ret("byte");
    return 0;
}