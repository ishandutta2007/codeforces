#include <bits/stdc++.h>
using int64 = long long;
const int N = 200005;

  int n, a[N], b[N];

void work() {
  int64 sum = 0;
  scanf("%d" , &n);
  for (int i =  0 ; i < n ; ++ i) {
    scanf("%d" , &a[i]);
  }
  for (int i =  0 ; i < n ; ++ i) {
    scanf("%d" , &b[i]);
    sum += b[i];
  }
  std::vector<int> A, B;
  for (int i = 0 ; i < n ; ++ i) {
    if (a[i]) {
      B.emplace_back(b[i]);
    } else {
      A.emplace_back(b[i]);
    }
  }
  if (A.size() > B.size()) {
    std::swap(A, B);
  }

  std::sort(A.begin(), A.end());
  std::sort(B.begin(), B.end());
  std::reverse(B.begin(), B.end());

  if (A.size() == 0) {
    printf("%lld\n", sum);
  } else {
    // A first
    int64 sa = 0;
    for (int i = 1 ; i < A.size() ; ++ i) {
      sa += A[i];
    }
    for (int i = 0 ; i < A.size() ; ++ i) {
      sa += B[i];
    }
    // B first
    int64 sb = 0;
    for (int i = 0 ; i < A.size() ; ++ i) {
      sb += A[i];
    }
    int p = std::min<int>(B.size() - 1 , A.size());
    for (int i = 0 ; i < p ; ++ i) {
      sb += B[i];
    }
    // std::cout << sa << ' ' << sb << std::endl;
    printf("%lld\n", sum + std::max(sb, sa));
  }
}

int main() {
  int T = 1;
  scanf("%d", &T);
  while (T --) {
    work();
  }
  return 0;
}