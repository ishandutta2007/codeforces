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
const int maxn = (int)2e5 + 10;
int n, T;
ld c;
int a[maxn];
ll sum[maxn];
ld app[maxn];
int main() {
  #ifdef DEBUG
  freopen(TASK".in", "r", stdin);
  freopen(TASK".out", "w", stdout);
  #endif
  scanf("%d %d %lf", &n, &T, &c);
  sum[0] = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum[i + 1] = sum[i] + a[i]; 
  }
  app[0] = 0;
  for (int i = 0; i < n; i++) {
    app[i + 1] = (app[i] + (ld)a[i] / T) / c;
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int q;
    scanf("%d", &q);
    ld real = (ld)(sum[q] - sum[q - T]) / T;
    ld appr = app[q];
    ld errr = abs(real - appr) / real;
    printf("%.6f %.6f %.6f\n", real, appr, errr);
  }
  return 0; 
}