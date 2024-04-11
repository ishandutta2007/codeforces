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

int k, n, a[30];
string s;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> k >> s;
    n = s.length();
    fr(i, n)
      a[s[i] - 'a']++;
    fr(i, 26)
      if (a[i] % k != 0)
         ret("-1");
    fr(i, k)
      fr(j, 26)
        fr(ii, a[j] / k)
          cout << char('a' + j);
    return 0;
}