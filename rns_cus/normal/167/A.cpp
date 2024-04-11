#include <bits/stdc++.h>
using namespace std;
#define M 100010
int n, a, d;
double t[M];
int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d %d %d", &n, &a, &d);
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%lf %d", t + i, &v);
    double T = 1. * v / a;
    if (T * v / 2 < d) {
      t[i] += (T + 1. * (d - (T * v / 2)) / v);
    }
    else t[i] += sqrt(2. * d / a);
  }
  for (int i = 1; i < n; i++) {
    t[i] = max(t[i], t[i - 1]);
  }
  for (int i = 0; i < n; i++) printf("%.12lf\n", t[i]);
}