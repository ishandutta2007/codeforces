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

int get_sum(int a, int s)
{
  int ans = 0;
  while (a > 0)
  {
    ans += a % s;
    a /= s;
  }
  return ans;
}

int gcd(int a, int b)
{
  if (a % b == 0) return b; else return gcd(b, a % b);
}

void ret(string s)
{
  cout << s;
  exit(0);
}

string s;
int n, k, a[3] = {0};
int last = -1, step = -1;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    fr(i, n)
    {
      cin >> k;
      a[k - 1]++;
    }
    sort(a, a + 3);
    cout << a[0] + a[1];
    return 0;
}