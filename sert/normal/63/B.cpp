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
    int a[1000], n, k;
    cin >> n >> k;
    fr(i, n) cin >> a[i];
    if (a[0] >= k)
      ret("0");
    fr(i, 100000)
    {
      fab(j, 0, n - 2)
        if(a[j] != a[j + 1])
          a[j]++;
      a[n - 1]++;
      if(a[0] >= k)
      {
        cout << i + 1;
        return 0;
      }
    }
    cout << 0;
    return 0;
}