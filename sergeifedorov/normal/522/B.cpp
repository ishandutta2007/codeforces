#undef NDEBUG

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>
#include <typeinfo>
#include <limits>

using namespace std;

struct Man {
  int w, h;
};

int main() {
#ifdef ssu1
  assert(freopen("input.txt", "rt", stdin));
#endif

  int n;
  scanf("%d", &n);
  vector<Man> a(n);
  long long sumw = 0;
  for (Man& m : a) {
    scanf("%d%d", &m.w, &m.h);
    sumw += m.w;
  }

  int maxid = -1, nextmaxid = -1;
  for (int i = 0; i < n; ++i) {
    if (maxid == -1 || a[maxid].h <= a[i].h) {
      nextmaxid = maxid;
      maxid = i;
    } else if (nextmaxid == -1 || a[nextmaxid].h <= a[i].h) {
      nextmaxid = i;
    }
  }

  for (int i = 0; i < n; ++i) {
    long long ans = (sumw - a[i].w) * (i == maxid ? a[nextmaxid].h : a[maxid].h);
    if (i > 0)
      printf(" ");
    printf("%lld", ans);
  }
  puts("");
  
#ifdef ssu1
  cerr << "\nTime = " << ((double)clock()) / CLOCKS_PER_SEC << endl;
#endif    
  return 0;
}