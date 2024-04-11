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
    ll a[3], b[3], k, kol = 3;
    fr(i, 3) b[i] = -1;
    fr(i, 3) cin >> a[i];
    fr(i, 3) a[i]--;
    cin >> k;
    fr(i, 3)
      fr(j, 3)
        if(kol != 0)
          if(a[j] < (k + kol - 1) / kol && b[j] == -1)
          {
            b[j] = a[j];
            k -= a[j];
            kol--;
          }
    if(kol == 3)
    {
      fr(i, 3) b[i] = k / 3;
      fr(i, k % 3) b[i]++;
      ll ans = 1;
      fr(i, 3) ans *= (b[i] + 1);
      cout << ans;
      return 0;
    }
    if(kol == 0)
    {
      ll ans = 1;
      fr(i, 3) ans *= (b[i] + 1);
      cout << ans;
      return 0;
    }
    if(kol == 1)
    {
      fr(i, 3)
        if(b[i] == -1) b[i] = k;
      ll ans = 1;
      fr(i, 3) ans *= (b[i] + 1);
      cout << ans;
      return 0;
    }
    if(kol == 2)
    {
      fr(i, 3)
        if(b[i] == -1)
        {
          b[i] = k / 2;
          k -= k / 2;
          break;
        }
      fr(i, 3)
        if(b[i] == -1) b[i] = k;
      ll ans = 1;
      fr(i, 3) ans *= (b[i] + 1);
      cout << ans;
      return 0;
    }
    return 0;
}