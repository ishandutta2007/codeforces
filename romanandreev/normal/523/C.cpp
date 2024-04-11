#include <iostream>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
typedef double ld;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define next next_fdsgd
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),(a).end()
#define TASK "a"
const int maxn = (int)1e6 + 10;
char s[maxn];
char t[maxn];

int main() {
  #ifdef DEBUG
  freopen(TASK".in", "r", stdin);
  freopen(TASK".out", "w", stdout);
  #endif
  scanf("%s %s", s, t);
  int n = strlen(s);
  int m = strlen(t);
  int cur = 0;
  int L = -1, R = -1;
  for (int i = 0; i < m; i++) {
    if (s[cur] == t[i]) {
      cur++;
    }
    if (cur == n) {
      L = i;
      break;
    }
  }
  cur = n - 1;
  for (int i = m - 1; i >= 0; i--) {
    if (s[cur] == t[i]) {
      cur--;
    }
    if (cur == -1) {
      R = i;
      break;
    }
  }           
  printf("%d\n", max(0, R - L));
  return 0; 
}