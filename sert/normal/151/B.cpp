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

int number(string s)
{
  int h[10];
  h[0] = s[0];
  h[1] = s[1];
  h[2] = s[3];
  h[3] = s[4];
  h[4] = s[6];
  h[5] = s[7];
  bool ok = true;
  fr(i, 5)
    if (h[i] != h[i + 1])
      ok = false;
  if (ok) return 0;
  ok = true;
  fr(i, 5)
    if (h[i] <= h[i + 1])
      ok = false;
  if (ok) return 1;
  return 2;
}

void ret(string s)
{
  cout << s;
  exit(0);
}

int main()
{
    int n, k, mx;
    string s, out[3], name[100000];
    out[0] = "If you want to call a taxi, you should call:";
    out[1] = "If you want to order a pizza, you should call:";
    out[2] = "If you want to go to a cafe with a wonderful girl, you should call:";
    int a[3][100000];
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    fr(i, 3)
      fr(j, n)
        a[i][j] = 0;
    fr(i, n)
    {
      cin >> k;
      cin >> name[i];
      fr(j, k)
      {
        cin >> s;
        a[number(s)][i]++;
      }
    }
    mx = 0;
    bool first = true;
    fr(i, 3)
    {
      mx = 0;
      fr(j, n)
      {
        if(a[i][j] > mx)
          mx = a[i][j];
      }
      first = true;
      cout << out[i];
      fr(j, n)
        if(a[i][j] == mx)
        {
          if (!first) cout << ",";
          cout << " ";
          cout << name[j];
          first = false;
        }
      printf(".\n");
    }
    return 0;
}