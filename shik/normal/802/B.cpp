// by tmt514
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
typedef long long LL;

#include <set>
set<pair<int, int>> nextremove;
set<int> current;

const int N = 400005;
int a[N];
vector<int> b[N];
int cnt[N];

int main(void) {
  int n, k;
  scanf("%d%d", &n, &k);
  for(int i=0;i<n;i++) scanf("%d", &a[i]);
  for(int i=0;i<n;i++) {
    b[a[i]].push_back(i);
  }
  int cost=0;
  for(int i=0;i<n;i++) {
    int x = a[i];
    //fprintf(stderr, "x=%d\n", x);
    if(current.find(x) != current.end()) {
      nextremove.erase(nextremove.find({i, a[i]}));
      current.erase(current.find(x));

      if(++cnt[x] < SZ(b[x])) {
        //fprintf(stderr, "insert x = %d, cnt[x]=%d, b=%d\n", x, cnt[x], b[x][cnt[x]]);
        nextremove.insert({b[x][cnt[x]], x});
        current.insert(x);
      }
      
    } else {
      if (current.size() == k) {
        auto v = *nextremove.rbegin();
        int vx = v.second;
        int vi = v.first;

        nextremove.erase(nextremove.find({vi, vx}));
        current.erase(current.find(vx));
      }

      if(++cnt[x] < SZ(b[x])) {
        //fprintf(stderr, "insert x = %d, cnt[x]=%d, b=%d\n", x, cnt[x], b[x][cnt[x]]);
        nextremove.insert({b[x][cnt[x]], x});
        current.insert(x);
      }
      ++cost; 
    }
  }
  printf("%d\n", cost);
  return 0;
}