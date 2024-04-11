#include <bits/stdc++.h>
using namespace std;

struct Stopwatch {
  clock_t t = clock();
  void restart() { t = clock(); }
  int elapsed() const { return (clock() - t) * 1000 / CLOCKS_PER_SEC; }
  friend string to_string(Stopwatch sw) {
    return "Time: " + to_string(sw.elapsed()) + " ms";
  }
} sw;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  vector<double> a(n);
  for (auto&& e : a) {
    int $;
    cin >> $;
    e = $;
  }
  while (sw.elapsed() < 1000) {
    vector<int> v{0};
    for (int i = 1; i < n; ++i) {
      if (a[i - 1] < a[i]) {
        v.push_back(i);
      }
    }
    v.push_back(n);
    for (int t = 0; t < (int)v.size() - 1; ++t) {
      double avg = accumulate(begin(a) + v[t], begin(a) + v[t + 1], 0.0) / (v[t + 1] - v[t]);
      fill(begin(a) + v[t], begin(a) + v[t + 1], avg);
    }
  }
  for (auto e : a) {
    cout << e << '\n';
  }
}