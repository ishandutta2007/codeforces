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
   // freopen("output.txt", "w", stdout);
    string s, k;
    int a = 0, b = 0;
    cin >> s >> k;
    fr(i, s.length())
    {
      if(s[i] != k[i] && s[i] == '4') a++;
      if(s[i] != k[i] && s[i] == '7') b++;
    }
    cout << max(a, b);
    return 0;
}