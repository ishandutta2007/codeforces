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
  int picked, upset;
};

const int kInf = 1e9;

void SolveCase() {
  int m, k;
  scanf("%d%d", &m, &k);
  vector<int> a(k);
  for (int& ai : a)
    scanf("%d", &ai);
  vector<Man> b(m - 1); 
  for (Man& man : b) {
    scanf("%d%d", &man.picked, &man.upset);
    man.picked--;
  }
  int firstupset = -1;
  for (int i = 0; i < b.size(); ++i) {
    if (b[i].upset) {
      firstupset = i; 
      break;
    }
  }
  vector<int> ans(k, false);
  if (firstupset != -1) {
    vector<int> canend(k, true);
    for (int i = firstupset; i < b.size(); ++i) {
      if (b[i].picked != -1)
        canend[b[i].picked] = false;
    }

    int unused = 0;
    vector<int> cnt = a;
    for (int i = 0; i < firstupset; ++i) {
      if (b[i].picked != -1)
        cnt[b[i].picked]--;
      else
        unused++;
    }

    int minval = kInf, minidx = -1;
    for (int i = 0; i < k; ++i) {
      if (canend[i]) {
        if (minval > cnt[i]) {
          minval = cnt[i];
          minidx = i;
        }
        if (cnt[i] <= unused)
          ans[i] = true;
      }
    }
    assert(minidx != -1);
    assert(minval <= unused);

    cnt[minidx] = 0;
    unused -= minval;

    for (int i = firstupset; i < b.size(); ++i) {
      if (b[i].picked != -1)
        cnt[b[i].picked]--;
      else
        unused++;
    }

    for (int i = 0; i < k; ++i) {
      ans[i] |= (cnt[i] <= unused);
    }
    puts("");
  } else {
    vector<int> cnt = a;
    int unused = 0;
    for (int i = 0; i < b.size(); ++i) {
      if (b[i].picked != -1)
        cnt[b[i].picked]--;
      else
        unused++;
    }

    for (int i = 0; i < k; ++i) {
      ans[i] = (cnt[i] <= unused);
    }
    puts("");
  }
  for (int i = 0; i < k; ++i) {
    if (ans[i])
      printf("Y");
    else
      printf("N");
  }
  puts("");
}

int main() {
#ifdef ssu1
  assert(freopen("input.txt", "rt", stdin));
#endif
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    SolveCase();
  }
#ifdef ssu1
  cerr << "\nTime = " << ((double)clock()) / CLOCKS_PER_SEC << endl;
#endif    
  return 0;
}