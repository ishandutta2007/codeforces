#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory.h>
#include <cstring>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int h, m, n;
map<int, int> where;
char s[100];
int id, t, ans;
vector< vector<int> > cycles, sums;
int listpos[200010], listid[200010];
bool used[200010];

void modify(vector<int>& s, int i, int d) {
  for (i++; i < (int)s.size(); i+=-i&i)
    s[i] += d;
}

int sum(vector<int>& s, int x) {
  int res = 0;
  for (; x>0; x&=x-1)
    res += s[x];
  return res;
}

int getsum(vector<int>& s, int a, int b) {
  return sum(s, b + 1) - sum(s, a);
}

int isEmpty(vector<int>& s, int a, int b) {
  // printf("isEmpty %d %d: %d < %d\n", a, b, getsum(s, a, b-1), b - a);
  return getsum(s, a, b - 1) < b - a;
}

int getFree(int id, int i) {
  int l, r, m;
  int len = cycles[id].size();
  if (isEmpty(sums[id], i, len)) {
    l = i;
    r = len;
  } else {
    l = 0;
    r = i;
  }

  while (r - l > 1) {
    m = (l + r) >> 1;
    if (isEmpty(sums[id], l, m)) r = m;
    else l = m;
  }
  int w = l - i;
  if (w < 0) w += len;
  // printf( ">>> +%d\n", w);
  // printf( "place to %d\n", l);
  ans += w;

  return cycles[id][l]; 
}

int main()
{
  scanf("%d %d %d", &h, &m, &n);
  forn(i, h)
    if (!used[i]) {
      vector<int> cur;
      cur.pb(i);
      used[i] = true;
      listid[i] = cycles.size();
      listpos[i] = 0;

      i += m;
      if (i >= h) i -= h;
      while (i != cur[0]) {
        used[i] = true;
        listid[i] = cycles.size();
        listpos[i] = cur.size();
        cur.pb(i);
        i += m;
        if (i >= h) i -= h;
      }

      cycles.pb(cur);
      sums.pb(vector<int>(cur.size() + 1, 0));
    }

  ans = 0;
  forn(i, n) {
    scanf("%s %d", s, &id);
    if (s[0] == '+') {
      scanf("%d", &t);
      int lid = listid[t];
      int x = getFree(lid, listpos[t]);
      modify(sums[lid], listpos[x], +1);
      where[id] = x;
    } else {
      int x = where[id];
      modify(sums[listid[x]], listpos[x], -1);
    }
  }
  printf("%d\n", ans);
  return 0;
}