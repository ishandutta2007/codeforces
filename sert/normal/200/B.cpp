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
    int n, k = 0, p;
    db ans = 0;
    cin >> n;
    fr(i, n)
    {
      cin >> p;
      k += p;
    }
    ans = k;
    ans /= n;
    printf("%.9lf", ans);
    //cout.precision() = 10;
    //cout << fixed << ans;
    return 0;
}