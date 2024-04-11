#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>

#define fab(i, a, b) for(int i = a; i < b; i++)
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

string a[1000], h2[1000], a2[1000];
int n, k, p, sc[1000] = {0}, kol = 0, h[1000], u[1000] = {0}, mx, sc2[1000];
string s;

void moov(int i)
{
  while(i > 0 && sc[i] > sc[i - 1])
  {
    swap(sc[i], sc[i - 1]);
    swap(a[i], a[i - 1]);
    i--;
  }
  while(i < kol - 1 && sc[i] < sc[i + 1])
  {
    swap(sc[i], sc[i + 1]);
    swap(a[i], a[i + 1]);
    i++;
  }
}

bool name_check(string st)
{
  bool ok = false;
  fr(i, kol)
    if(a2[i] == st && sc2[i] == mx)
      return true;
  return false;
}

int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    fr(i, n)
    {
      cin >> h2[i];
      s = h2[i];
      cin >> h[i];
      k = h[i];
      p = -1;
      fr(i, kol)
        if (s == a[i])
          p = i;
      if (p == -1)
      {
        a[kol] = s;
        p = kol;
        kol++;
      }
      sc[p] += k;
      moov(p);
    }
    fr(i, kol)
    {
      a2[i] = a[i];
      sc2[i] = sc[i];
    }
    mx = sc[0];
    fr(i, kol)
      sc[i] = 0;
    fr(i, n)
    {
      s = h2[i];
      k = h[i];
      p = -1;
      fr(i, kol)
        if (s == a[i])
          p = i;
      if (p == -1)
      {
        a[kol] = s;
        p = kol;
        kol++;
      }
      sc[p] += k;
      if(sc[p] >= mx && name_check(s))
        ret(a[p]);
      moov(p);
    }
    return 0;
}