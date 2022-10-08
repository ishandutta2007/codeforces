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
typedef long double ld;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define next next_fdsgd
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),(a).end()
#define TASK "a"
int n, m;
char a[1000][1000];
int main() {
  #ifdef DEBUG
  freopen(TASK".in", "r", stdin);
  freopen(TASK".out", "w", stdout);
  #endif
  scanf("%d %d", &m, &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", a[i]);
  }
  for (int i = 0; i < 2 * m; i++) {
    for (int j = 0; j < 2 * n; j++) {
      int i1 = i / 2;
      int j1 = j / 2;
      printf("%c", a[j1][i1]);
    }
    printf("\n");
  }
  return 0; 
}