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
    int m, n, a[1000] = {0}, r, k, ans = 0, h;
    cin >> n >> m >> k;
    fr(i, m) a[i] = 2000000000;
    fr(i, n)
    {
      cin >> r >> h;
      r--;
      a[r] = min(a[r], h);
    }
    fr(i, m)
      ans += a[i];
    cout << min(k, ans);
    return 0;
}