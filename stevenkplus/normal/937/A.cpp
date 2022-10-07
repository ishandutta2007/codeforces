#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int main() {
  int N;
  cin >> N;
  set<int> s;
  for(int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    if (x > 0) {
      s.insert(x);
    }
  }
  int ans = s.size();
  cout << ans << "\n";
}