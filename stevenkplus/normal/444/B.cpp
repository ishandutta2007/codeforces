#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)

const int MAXN = 100100;
const int THRES = 3000;

int a[MAXN];
int b[MAXN];

int n, d;
int N;
int X;
ll x;

int getNextX() {
   x = (x * 37 + 10007) % 1000000007;
  return x;
}


void gen() {

  for(int i = 0; i < n; ++i) {
    a[i] = i + 1;
  }
  for(int i = 0; i < n; ++i) {
    swap(a[i], a[getNextX() % (i + 1)]);
  }
  for(int i = 0; i < n; ++i) {
    if (i < d) b[i] = 1;
    else b[i] = 0;
  }
  for(int i = 0; i < n; ++i) {
    swap(b[i], b[getNextX() % (i + 1)]);
  }
}

vector<int> ones;
set<pii> guys;

int main() {
  scanf("%d %d %d", &n, &d, &X);
  N = n;
  x = X;
  gen();

  if (d < THRES) {
    for(int i = 0; i < N; ++i) {
      if (b[i]) ones.push_back(i);
    }

    for(int i = 0; i < N; ++i) {
      int ans = 0;
      repi(j, ones) {
        if (*j <= i) {
          if (a[i - *j] > ans) {
            ans = a[i - *j];
          }
        }
      }
      printf("%d\n", ans);
    }
  } else {
    set<pii> myset;
    for(int i = 0; i < N; ++i) {
      myset.insert(pii(-a[i], i));
      int ans = 0;
      repi(j, myset) {
        int pos = j->second;
        if (b[i - pos]) {
          ans = -j->first;
          break;
        }
      }
      printf("%d\n", ans);
    }
  }

  return 0;
}