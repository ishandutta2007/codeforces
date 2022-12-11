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

bool _less(char a, char c)
{
  return a > c;
}

void ret(string s)
{
  cout << s;
  exit(0);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string a, h;
    char b[100000];

    cin >> a;
    cin >> h;
    int n = a.length(), m = h.length();
    fr(i, m)
      b[i] = h[i];
    sort(b, b + m, _less);
    int pos = 0;
    fr(i, n)
      if(b[pos] > a[i])
      {
        a[i] = b[pos];
        pos++;
        if(pos == m)
          break;
      }
    cout << a;

    return 0;
}