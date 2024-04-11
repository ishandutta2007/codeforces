#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;

const int MAXN = 100100;
const int MAXK = 20;
set<int> s[MAXK];

int N, Q;
ll c2(ll x) {
  return x * (x + 1) / 2;
}

int getl(int i, int x) {
  set<int>::iterator n = s[i].lower_bound(x);
  --n;
  return *n;
}
int getr(int i, int x) {
  set<int>::iterator n = s[i].lower_bound(x);
  return *n;
}

int main() {
  scanf("%d %d", &N, &Q);
  for(int i = 0; i < N; ++i) {
    int tmp;
    scanf("%d", &tmp);
    for(int j = 0; j < MAXK; ++j) {
      if (!((tmp >> j) & 1)) {
        s[j].insert(i);
      }
    }
  }
  for(int i = 0; i < MAXK; ++i) {
    s[i].insert(-1);
    s[i].insert(N);
  }

  ll cval = 0;
  ll scal = 1;
  for(int i = 0; i < MAXK; ++i) {
    int run = 0;
    for(int j = 0; j < N; ++j) {
      if (s[i].find(j) == s[i].end()) {
        ++run;
      } else {
        run = 0;
      }
      cval += scal * run;
    }
    scal *= 2;
  }

//  printf("cval = %"PRId64"\n", cval);

  for(int i = 0; i < Q; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    scal = 1;
    for(int j = 0; j < MAXK; ++j) {
      if ((y >> j) & 1) {
        if (s[j].find(x) != s[j].end()) {
          s[j].erase(x);
          int lft = x - getl(j, x) - 1; // [x-lft, x] all 1s
          int rgt = getr(j, x + 1) - (x + 1); //[x+1,x+1+rgt] all 1s
          ll old = c2(lft) + c2(rgt);
          ll nw = c2(lft + rgt + 1);
          cval += scal * (nw - old);
        }
      } else {
        if (s[j].find(x) == s[j].end()) {
          int lft = x - getl(j, x) - 1;
          int rgt = getr(j, x + 1) - (x + 1);
          ll old = c2(lft) + c2(rgt);
          ll nw = c2(lft + rgt + 1);
          cval += scal * (old - nw);
          s[j].insert(x);
        }
      }
      scal *= 2;
    }

    printf("%I64d\n", cval);
  }


  return 0;
}