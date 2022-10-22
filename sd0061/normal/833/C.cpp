#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int nl , nr , dl[20] , dr[20];
int cnt[10], res , num[10];

bool check(int k , bool lower , bool upper) {
  if (lower && upper) {
    return 1;
  }
  if (k == -1) {
    return 1;
  }
  for (int i = 0 ; i < 10 ; ++ i) {
    if (num[i]) {
      if (!lower && i < dl[k]) continue;
      if (!upper && i > dr[k]) continue;
      -- num[i];
      if (check(k - 1 , lower || (i > dl[k]) , upper || (i < dr[k]))) {
        return true;
      }
      ++ num[i];
    }
  }
  return 0;
}

void dfs(int k , int cur) {
  if (k == nr) {
    memcpy(num , cnt , sizeof(num));
    res += check(nr - 1 , 0 , 0);
  } else {
    for (int i = cur ; i < 10 ; ++ i) {
      ++ cnt[i];
      dfs(k + 1 , i);
      -- cnt[i];
    }
  }
}


int main() {
  LL L , R;
  scanf("%lld%lld" , &L , &R);
  while (L) {
    dl[nl ++] = L % 10;
    L /= 10;
  }
  while (R) {
    dr[nr ++] = R % 10;
    R /= 10;
  }
  dfs(0 , 0);
  cout << res << endl;
}