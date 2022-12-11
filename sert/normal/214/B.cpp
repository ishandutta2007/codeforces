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

bool _less(int a, int b)
{
  return a > b;
}

void print(string s)
{
  if (s[0] == '0')
  cout << "0";
  else
  cout << s;
}


int a[200000], num = -1;
int u[200000] = {-1};
int b[200000], c[200000];
int n, p = -1, h, k, mx = 0, kol = 0, m1, m2, len = 0;
bool found, nn;
bool use[200000];
string s = "";

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    fr(i, n) cin >> a[i];
    fr(i, 10){b[i] = -1; c[i] = -1;}
    sort(a, a + n, _less);



    fr(i, n) kol += a[i];
    if (a[n - 1] != 0) ret("-1");
    if (a[0] == 0) ret("0");
    if (kol % 3 == 0){fr(i, n) cout << a[i]; return 0;}
    b[0] = n;
    fr(i, n - 1)
    if(b[a[i]] == -1) b[a[i]] = i; else if (c[a[i]] == -1) c[a[i]] = i;
    fr(i, 10) {if ((kol - i) % 3 == 0 && b[i] != -1)
    {
      fr(j, n) if (j != b[i]) s += (char)'0' + a[j];
      cerr << s;
      print(s); return 0;}
    if (!found) fr(j, i)
    if (b[i] != -1)
    {
      if (b[j] != -1 && (i + j - kol) % 3 == 0)
      {use[b[i]] = true; use[b[j]] = true; found = true; break;}
      if (c[i] != -1 && (kol - i * 2) % 3 == 0)
      {
        use[c[i]] = true;
        use[b[i]] = true; found = true; break;
      }
    }}
    fr(i, n) if (!use[i]) s += (char)'0' + a[i];
    print(s);
    return 0;
}