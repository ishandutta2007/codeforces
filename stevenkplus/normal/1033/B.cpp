#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int T;
  cin >> T;
  for (int j = 0; j < T; ++j) {
    ll N, M;
    cin >> N >> M;
    if (N == M + 1) {
      N += M;
      int p = 1;
      for(int i = 2; i < 1E6 && i < N; ++i) {
        if (N % i == 0) {
          p = 0;
          break;
        }
      }
      if (p) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else {
      cout << "NO\n";
    }
  }
}