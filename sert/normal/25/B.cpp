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
    int n;
    string s;
    cin >> n;
    cin >> s;
    cout << s[0] << s[1];
    if (n == 2) return 0;
    fab(i, 2, s.length() - 2)
    {
      if(i % 2 == 0) cout << "-";
      cout << s[i];
    }
    cout << s[s.length() - 1];

    return 0;

}