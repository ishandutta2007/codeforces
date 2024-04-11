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
    string s;
    cin >> s;
    char a[1000];
    fr(i, s.length()) a[i] = s[i];
    sort(a, a + s.length());
    for(int i = s.length() - 1; i >= 0; i--)
    {
      if(a[i] != a[s.length() - 1]) return 0;
      cout << a[i];
    }
    return 0;
}