#include <bits/stdc++.h>

template <class T>
inline void read(T &res) {
  res = 0; bool bo = 0; char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-');
  if (c == '-') bo = 1; else res = c - 48;
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + (c - 48);
  if (bo) res = ~res + 1;
}

typedef long long ll;

struct num {
  int x; ll cnt;
};

std::vector<num> transform(std::vector<int> a, int k) {
  std::vector<num> tmp, ans;
  for (int i = 0; i < a.size(); i++) {
  	ll c = 1; int x = a[i];
  	while (x % k == 0) x /= k, c *= k;
  	tmp.push_back((num) {x, c});
  }
  for (int i = 0; i < tmp.size(); i++)
    if (ans.empty() || ans[ans.size() - 1].x != tmp[i].x)
      ans.push_back(tmp[i]);
    else ans[ans.size() - 1].cnt += tmp[i].cnt;
  return ans;
}

void yhjssa() {
  int n, m, k, x;
  read(n); read(m);
  std::vector<int> a, b;
  for (int i = 0; i < n; i++) read(x), a.push_back(x);
  read(k);
  for (int i = 0; i < k; i++) read(x), b.push_back(x);
  std::vector<num> A = transform(a, m), B = transform(b, m);
  if (A.size() != B.size()) return (void) puts("no");
  for (int i = 0; i < A.size(); i++) if (A[i].x != B[i].x || A[i].cnt != B[i].cnt)
    return (void) puts("no");
  puts("yes");
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}