#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cout.tie(0);
  int n;
  long long s;
  cin >> n >> s;
  if (s > (long long) n * (n + 1) / 2 || s < n * 2 - 1) {
    cout << "No" << "\n";
    return 0;
  }
  cout << "Yes" << "\n";
  auto check = [&](int limit) {
    int remain = n - 1, depth = 2, last = 1;
    long long sum = 1;
    while (remain) {
      long long cur = min((long long) last * limit, (long long) remain);
      sum += cur * depth;
      remain -= cur;
      last = cur;
      ++depth;
    }
    return sum <= s;
  };
  int l = 1, r = n;
  while (l < r) {
    int mid = l + r >> 1;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  vector<int> cnt(n + 1);
  int depth = 2, remain = n - 1;
  long long cur = s - 1;
  cnt[1] = 1;
  while (remain) {
    cnt[depth] = min((long long) cnt[depth - 1] * r, (long long) remain);
    cur -= (long long) cnt[depth] * depth;
    remain -= cnt[depth++];
  }
  int ptr = --depth;
  while (cur) {
    while (cnt[ptr] == 1) {
      --ptr;
    }
    --cnt[ptr];
    if (cur >= depth + 1 - ptr) {
      ++cnt[++depth];
      cur -= depth - ptr;
    } else {
      ++cnt[cur + ptr];
      cur = 0;
    }
  }
  for (int i = 2, j = 1; i <= n; ++i) {
    for (int k = 0; k < cnt[i]; ++k) {
      if (i != 2 || k) {
        cout << " ";
      }
      cout << k / r + j;
    }
    j += cnt[i - 1];
  }
  cout << "\n";
  return 0;
}