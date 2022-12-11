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

struct pt{
  int x, y;
  ll operator * (const pt &a){
    return x * a.x + y * a.y;
  }
  pt operator - (const pt &a){
    pt b;
    b.x = x - a.x;
    b.y = y - a.y;
    return b;
  }
    pt operator + (const pt &a){
    pt b;
    b.x = x + a.x;
    b.y = y + a.y;
    return b;
  }
};

bool is_pr(pt a, pt b, pt c){
  bool ans = false;
  if (a.x == b.x && a.y == b.y) return false;
  if (c.x == b.x && c.y == b.y) return false;
  if (a.x == c.x && a.y == c.y) return false;
  if ((a - b) * (a - c) == 0) ans = true;
  if ((a - b) * (b - c) == 0) ans = true;
  if ((a - c) * (b - c) == 0) ans = true;
  return ans;
}

void ret(string s)
{
  cout << s;
  exit(0);
}

pt a[3];
pt v[4];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fr(i, 3) cin >> a[i].x >> a[i].y;

    v[0].x = 1;
    v[1].x = -1;
    v[2].y = 1;
    v[3].y = -1;
    if (is_pr(a[0], a[1], a[2])) ret("RIGHT");
    bool almost = false;
    fr(i, 3)
      fr(j, 4){
        a[i] = a[i] + v[j];
        if (is_pr(a[0], a[1], a[2]))
          ret("ALMOST");
        a[i] = a[i] - v[j];
      }
    cout << ("NEITHER");
    return 0;
}