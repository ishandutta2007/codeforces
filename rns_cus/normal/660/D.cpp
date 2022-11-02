#include <bits/stdc++.h>
using namespace std;
#define M 100010

typedef pair <int, int> PII;

int x[M], y[M], n;


int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x[i], &y[i]);
  }
  map <PII, int> mp;
  __int64 ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      int xx = x[i] + x[j], yy = y[i] + y[j];
      if (mp.count(PII(xx, yy))) ans += mp[PII(xx, yy)];
      mp[PII(xx, yy)]++;
    }
  }
  cout << ans << endl;
}