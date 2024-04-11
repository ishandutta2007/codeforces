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
const ll N = 1e6 + 4;
const ll M = 1e6 + 4;

using namespace std;

void ret(string s)
{
  cout << s;
  exit(0);
}

string s;
ll n, m, k, t, kol = 0, ans = 0, l1, rr, j;
ll a[N], b[N];
bool p[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    p[2] = false;
    fab(i, 2, 1000){
      if (!p[i]){
        j = i * i;
        while (j <= 1000000){
          p[j] = true;
          j += i;
        }
      }
    }
    a[0] = 0;
    a[1] = 0;
    fab(i, 2, 1000000){
      a[i] = a[i - 1];
      if (!p[i]) a[i]++;
    }
    cin >> l1 >> rr >> k;
    int l = 0;
    int r = rr - l1 + 1;
    if (a[rr] - a[l1 - 1] < k) ret("-1");
    int m;
    bool fail;
    while (r - l > 1){
      //cerr << l << " " << r << "\n";
      m = (l + r) / 2;
      fail = false;
      fab(i, l1, rr - m + 1){
        if (a[i + m - 1] - a[i - 1] < k)
          fail = true;
      }
      if (fail) l = m; else r = m;

    }
    cout << r;
    return 0;
}