#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <deque>

#define fab(i, a, b) for(int i = a; i <= b; i++)
#define fdown(i, n) for(int i = n - 1; i >= 0; i--)
#define fr(i, n) for(int i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define pint pair <int, int>
#define vint vector <int>
#define vpint vector < pair <int, int> >
#define ff first
#define ss second
#define cpr(n) cout.precision(n);

typedef long long ll;
typedef long double ld;
typedef double db;

const ll inf = 1e9;
const ld eps = 1e-6;
const ll N = 1e6;
const ll M = 1e3;

using namespace std;

void ret(string s)
{
  cout << s;
  exit(0);
}

int a[N], py[N];
ll n, x, va = 0, pt = 0;
bool u[N], is;
ld k, s;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    fr(i, n){
      cin >> a[i];
      s += a[i];
    }
    ld l = 0, r = 1000, m, mn, pl;
    fr(i, 1000){
      pl = 0;
      mn = 0;
      m = (l + r) / 2;
      fr(j, n)
        if (a[j] > m)
          pl += a[j] - m;
        else
          mn += m - a[j];
      if (pl * (100 - k) / 100 > mn)
        l = m;
      else
        r = m;

    }
    cpr(10);
    cout << fixed << l;
    return 0;
}