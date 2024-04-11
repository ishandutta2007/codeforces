#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> p(n + 1), ld(n + 1), lu(n + 1), rd(n + 1), ru(n + 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
  }
  for (int i = 1; i <= n; ++i) {
    lu[i] = i != 1 && p[i] < p[i - 1] ? lu[i - 1] + 1 : 1;
    ld[i] = i != 1 && p[i] > p[i - 1] ? ld[i - 1] + 1 : 1;
  }
  for (int i = n; i; --i) {
    ru[i] = i != n && p[i] < p[i + 1] ? ru[i + 1] + 1 : 1;
    rd[i] = i != n && p[i] > p[i + 1] ? rd[i + 1] + 1 : 1;
  }
  int lu_ = *max_element(lu.begin(), lu.end());
  int ld_ = *max_element(ld.begin(), ld.end());
  if (lu_ == ld_) {
    if (count(lu.begin(), lu.end(), lu_) != 1 || count(ld.begin(), ld.end(), ld_) != 1) {
      puts("0");
      return 0;
    }
    if (max_element(ld.begin(), ld.end()) - ld.begin() == max_element(rd.begin(), rd.end()) - rd.begin()) {
      if (ld_ != 1 && ld_ % 2 == 1) {
        puts("1");
      } else {
        puts("0");
      }
      return 0;
    }
    puts("0");
    return 0;
  }
  puts("0");
  return 0;
}