#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <cctype>
#include <sstream>
#include <cassert>
#include <bitset>
#include <memory.h>
#include <complex>
#include <iomanip>

using namespace std;

#pragma comment(linker, "/STACK:200000000")

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define fore(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) (int(a.size()) - 1)
#define all(a) a.begin(), a.end()

const double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const double PI = 3.1415926535897932384626433832795;

bool is_prime(int a) {
  for (int i = 2; i * i <= a; i++)
    if (a % i == 0)
      return false;
  return true;
}

int64 gcd(int64 a, int64 b) {
  return a == 0 ? b : gcd(b % a, a);
}

int a[210], in[210], mx;
bool u[210];
int64 lcm;

void solve(int i) {
  memset(u, 0, sizeof(u));
  vector<int> p;
  for (int j = i; ; j = a[j]) {
    p.pb(j);
    if (u[j])
      break;
    u[j] = true;
  }

  int l = p.back();
  p.pop_back();

  int off = int(find(all(p), l) - p.begin());
  int len = int(p.end() - find(all(p), l));

  mx = max(mx, off);
  if (lcm == 0)
    lcm = len;
  else
    lcm = lcm / gcd(lcm, len) * len;
}

int main() {
#ifdef RADs_project
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

  int sum = 200;
  int64 res = 1;
  for (int i = 2; sum > 0 && i < 1000; i++)
    if (is_prime(i)) {
      sum -= i;
      res *= i;
    }
  cerr << res << endl;
  
  int n;
  cin >> n;
  forn(i, n) {
    cin >> a[i];
    a[i]--;
  }

  forn(i, n)
    in[a[i]]++;

  forn(i, n)
    if (!u[i])
      solve(i);

  if (max(lcm, (int64)mx) == 0) {
    puts("1");
    return 0;
  }

  if (lcm >= mx) {
    cout << lcm << endl;
    return 0;
  }

  for (int i = 1; ; i++)
    if (lcm * i >= mx) {
      cout << lcm * i << endl;
      return 0;
    }
  
  return 0;
}