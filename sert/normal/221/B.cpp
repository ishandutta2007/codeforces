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

int px[N], py[N];
int a, b, da, ddb, t, n, x, kol = 0;
bool u[N], is;

string s;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> x;
    if (x == 1) ret("1");
    t = x;
    while (t != 0){
      u[t % 10] = true;
      t /= 10;
    }
    fab(i, 1, sqrt(x)){
      if (x % i != 0) continue;
      n = i;
      is = false;
      while (n > 0){
        if (u[n % 10])
          is = true;
        n /= 10;
      }
      if (is) kol++;
      n = x / i;
      if (n == i) continue;
      is = false;
      while (n > 0){
        if (u[n % 10])
          is = true;
        n /= 10;
      }
      if (is) kol++;
    }
    cout << kol;
    return 0;
}