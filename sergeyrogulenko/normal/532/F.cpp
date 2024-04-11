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

#define hash hash_huy

const double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const double PI = 3.1415926535897932384626433832795;

const int NMAX = 210000;
const int CNT = 4;
const int64 D = 17;

int mod[CNT];

struct hash {
  int64 v[CNT];

  void operator *= (int64 x) {
    forn(i, CNT) {
      v[i] *= x;
      if (i)
        v[i] %= mod[i];
    }
  }

  void operator *= (const hash& x) {
    forn(i, CNT) {
      v[i] *= x.v[i];
      if (i)
        v[i] %= mod[i];
    }
  }

  void operator -= (const hash& x) {
    forn(i, CNT) {
      v[i] -= x.v[i];
      if (i && v[i] < 0)
        v[i] += mod[i];
    }
  }

  void operator += (int64 x) {
    forn(i, CNT) {
      v[i] += x;
      if (i)
        v[i] %= mod[i];
    }
  }

  bool operator == (const hash& x) {
    forn(i, CNT)
      if (v[i] != x.v[i])
        return false;
    return true;
  }
};

bool is_prime(int a) {
  for (int i = 2; i * i <= a; i++)
    if (a % i == 0)
      return false;
  return true;
}

char s[NMAX], t[NMAX];
hash h[NMAX][26], ht[26], pw[NMAX];
bool u[26];
int pos[26], lt[26], ns, nt;

bool check(int sh, int cs, int ct) {
  hash cur = h[sh + nt - 1][cs];
  if (sh) {
    hash g = h[sh - 1][cs];
    g *= pw[nt];
    cur -= g;
  }

  return cur == ht[ct];
}

int main() {
#ifdef RADs_project
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

  srand(time(0));
  forn(i, CNT) {
    mod[i] = INF - rand() % 10000;
    while (!is_prime(mod[i]))
      mod[i]--;
  }

  memset(pw[0].v, 0, sizeof(pw[0].v));
  pw[0] += 1;
  for (int i = 1; i < NMAX; i++) {
    pw[i] = pw[i - 1];
    pw[i] *= D;
  }

  scanf("%d%d", &ns, &nt);
  scanf("%s%s", s, t);

  forn(i, ns)
    forn(c, 26) {
      if (i)
        h[i][c] = h[i - 1][c];
      else
        memset(h[i][c].v, 0, sizeof(h[i][c].v));
      h[i][c] *= D;
      if (s[i] - 'a' == c)
        h[i][c] += 1;
    }

  forn(i, 26)
    memset(ht[i].v, 0, sizeof(ht[i].v));

  forn(i, nt)
    forn(c, 26) {
      ht[c] *= D;
      if (t[i] - 'a' == c)
        ht[c] += 1;
    }

  memset(pos, -1, sizeof(pos));
  forn(i, nt)
    pos[t[i] - 'a'] = i;

  vector<int> ans;
  forn(sh, ns - nt + 1) {
    memset(u, 0, sizeof(u));
    memset(lt, -1, sizeof(lt));

    forn(c, 26) {
      if (pos[c] == -1)
        continue;

      lt[c] = s[sh + pos[c]] - 'a';
      if (u[lt[c]])
        goto bad;
      u[lt[c]] = true;
    }

    forn(c, 26) {
      if (lt[c] == -1)
        continue;
      if (lt[lt[c]] == -1)
        continue;
      if (lt[lt[c]] != c)
        goto bad;
    }

    forn(c, 26) {
      if (lt[c] == -1)
        continue;

      if (!check(sh, lt[c], c))
        goto bad;
    }

    ans.pb(sh);
bad:;
  }

  printf("%d\n", (int)ans.size());
  forn(i, ans.size())
    printf(i ? " %d" : "%d", ans[i] + 1);
  puts("");

  return 0;
}