#include <iostream>
using namespace std;

int main() {
  int T,N;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> N;
    int even = 0;
    int odd = 0;
    for(int j = 0; j < N; ++j) {
      int x;
      cin >> x;
      if (x % 2 == 0) ++even;
      else ++odd;
    }
    if (odd == 0 || (even == 0 && N % 2 == 0)) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}