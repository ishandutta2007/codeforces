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

const int NMAX = 2100000;

char s[NMAX];
int p[NMAX], cnt[NMAX], c[NMAX], pn[NMAX], cn[NMAX], n, b[NMAX];
bool good[NMAX];

int md[NMAX * 4], add[NMAX * 4];

void md_build(int idx, int l, int r) {
  if (l == r) {
    md[idx] = b[l];
    return;
  }

  int mid = (l + r) >> 1;
  md_build(idx << 1, l, mid);
  md_build(idx << 1 | 1, mid + 1, r);

  md[idx] = min(md[idx << 1], md[idx << 1 | 1]);
}

void md_relax(int idx, int l, int r) {
  if (add[idx]) {
    md[idx] += add[idx];
    if (l != r) {
      add[idx << 1] += add[idx];
      add[idx << 1 | 1] += add[idx];
    }
    add[idx] = 0;
  }
}

void md_add(int idx, int l, int r, int a, int b, int d) {
  md_relax(idx, l, r);
  if (b < l || r < a)
    return;

  if (a <= l && r <= b) {
    add[idx] += d;
    return md_relax(idx, l, r);
  }

  int mid = (l + r) >> 1;
  md_add(idx << 1, l, mid, a, b, d);
  md_add(idx << 1 | 1, mid + 1, r, a, b, d);

  md[idx] = min(md[idx << 1], md[idx << 1 | 1]);
}

int md_min(int idx, int l, int r, int a, int b) {
  md_relax(idx, l, r);
  if (b < l || r < a)
    return INF;

  if (a <= l && r <= b)
    return md[idx];

  int mid = (l + r) >> 1;
  return min(md_min(idx << 1, l, mid, a, b), md_min(idx << 1 | 1, mid + 1, r, a, b));
}

int main() {
#ifdef RADs_project
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

  gets(s);

  n = (int)strlen(s);

  memset (cnt, 0, sizeof(cnt));
  forn(i,n)
	  ++cnt[s[i] - '('];
  cnt[1] += cnt[0];
  forn(i,n)
	  p[--cnt[s[i] - '(']] = i;
  c[p[0]] = 0;
  int classes = 1;
  fore(i,1,n) {
	  if (s[p[i]] != s[p[i-1]])  ++classes;
	  c[p[i]] = classes-1;
  }

  for (int h=0; (1<<h)<n; ++h) {
	  forn(i,n)
		  pn[i] = (p[i] - (1<<h) + n) % n;
	  memset (cnt, 0, classes * sizeof(int));
	  forn(i,n)
		  ++cnt[c[pn[i]]];
	  fore(i,1,classes)
		  cnt[i] += cnt[i-1];
	  ford(i,n)
		  p[--cnt[c[pn[i]]]] = pn[i];
	  cn[p[0]] = 0;
	  classes = 1;
	  fore(i,1,n) {
		  int mid1 = (p[i] + (1<<h)) % n,
				  mid2 = (p[i-1] + (1<<h)) % n;
		  if (c[p[i]] != c[p[i-1]]
					  || c[mid1] != c[mid2])
			  ++classes;
		  cn[p[i]] = classes-1;
	  }
	  memcpy (c, cn, n * sizeof(int));
  }

  int sum = 0;
  forn(i, n) {
    sum += s[i] == '(' ? +1 : -1;
    b[i] = sum;
  }
  forn(i, n)
    b[i + n] = sum;

  md_build(1, 0, 2 * n);
  forn(i, n) {
    if (i) {
      if (s[i - 1] == '(')
        md_add(1, 0, 2 * n, i, i + n - 1, -1);
      else
        md_add(1, 0, 2 * n, i, i + n - 1, +1);
    }

    good[i] = md_min(1, 0, 2 * n, i, i + n - 1) >= min(0, sum);
  }

  int sh = -1;
  forn(i, n)
    if (good[p[i]]) {
      sh = p[i];
      break;
    }

  rotate(s, s + sh, s + n);

  if (sum <= 0)
    printf("%s", string(-sum, '(').c_str());
  printf("%s", s);
  if (sum > 0)
    printf("%s", string(sum, ')').c_str());
  puts("");

  return 0;
}