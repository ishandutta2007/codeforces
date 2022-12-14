#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <bitset>
#include <stdint.h>

using namespace std;

#define MAXN 100010

int X[MAXN];
int Y[MAXN];

vector<int> XS[MAXN];
vector<int> YS[MAXN];

//uint32_t bs[MAXN][MAXN / 32 + 1];


inline bool bget(int x, int y) {
  return binary_search(XS[x].begin(), XS[x].end(), y);
  //return bs[x][y >> 5] & 1U << (y & 0x1F);
}

inline void bset(int x, int y) {
  //bs[x][y >> 5] |= 1U << (y & 0x1F);
}

int main() {
  int N;
  scanf("%d", &N);

  for(int i = 0; i < N; i++) {
    scanf("%d %d", X + i, Y + i);
    XS[X[i]].push_back(Y[i]);
    YS[Y[i]].push_back(X[i]);
    bset(X[i], Y[i]);
  }
  for(int i = 0; i < MAXN; i++) {
    sort(XS[i].begin(), XS[i].end());
    sort(YS[i].begin(), YS[i].end());
  }

  int result = 0;
  for(int i = 0; i < N; i++) {
    int x = X[i];
    int y = Y[i];
    int xp = lower_bound(XS[x].begin(), XS[x].end(), y) - XS[x].begin();
    int yp = lower_bound(YS[y].begin(), YS[y].end(), x) - YS[y].begin();
    xp++;
    yp++;

    bool usex = XS[x].size() - xp < YS[y].size() - yp;
    int p = usex ? xp : yp;
    int offv = usex ? y : x;
    vector<int>& V = usex ? XS[x] : YS[y];

    for(int i = p; i < V.size(); i++) {
      int sz = V[i] - offv;
      if(x + sz >= MAXN || y + sz >= MAXN) break;

      if(bget(x, y + sz) &&
         bget(x + sz, y + sz) &&
         bget(x + sz, y)) {
        result++;
      }
    }
  }

  cout << result << endl;
  return 0;
}