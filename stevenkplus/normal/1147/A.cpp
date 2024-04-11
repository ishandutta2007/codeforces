#include <bits/stdc++.h>
using namespace std;

map<int, int> first, last;

int main() {
  int N, K;
  cin >> N >> K;
  for(int i = 0; i < K; ++i) {
    int x;
    cin >> x;
    if (first.find(x) == first.end()) {
      first[x] = i;
    }
    last[x] = i;
  }

  int cnt = 0;
  for(int i = 1; i <= N; ++i) {
    for(int j = i - 1; j <= i + 1; ++j) {
      if (j < 1 || j > N) continue;
      if (i == j) {
        if (first.find(i) == first.end()) {
          ++cnt;
        }
      } else {
        if (first.find(i) == first.end() || first.find(j) == first.end() || first[i] > last[j]) {
          ++cnt;
        }
      }
    }
  }

  cout << cnt << "\n";
}