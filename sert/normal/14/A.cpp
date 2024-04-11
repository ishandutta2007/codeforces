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
    int n, m;
    cin >> n >> m;
    bool ok;
    string s[100];
    int xn = 200, xm = 0, yn = 200, ym = 0;
    fr(i, n)
    {
      cin >> s[i];
      fr(j, s[i].length())
        if(s[i][j] == '*')
        {
          xn = min(xn, j);
          xm = max(xm, j);
          yn = min(yn, i);
          ym = max(yn, i);
        }
    }

    fab(i, yn, ym)
    {
      fab(j, xn, xm)
        cout << s[i][j];
      printf("\n");
    }

    return 0;
}