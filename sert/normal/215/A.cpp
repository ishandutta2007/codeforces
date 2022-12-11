#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>

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

int a[200000], c[200000];
int b[1000][1000];
int n, m, p, h, k, mx = 0, kol = 0;
string s;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    fr(i, n) cin >> a[i];
    cin >> m;
    fr(i, m) cin >> c[i];
    fr(i, n) fr(j, m)
    {
      if (c[j] % a[i] != 0) continue;
      if (c[j] / a[i] == mx) kol++;
      if (c[j] / a[i] > mx)
      {
        mx = c[j] / a[i];
        kol = 1;
      }
    }
    cout << kol;
    return 0;
}