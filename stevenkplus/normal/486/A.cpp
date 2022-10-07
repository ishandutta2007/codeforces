#include <cstdio>
#include <iostream>

using namespace std;

long long N;

int main() {
  cin >> N;
  if (N % 2 == 0) {
    cout << N / 2 << "\n";
  } else {
    cout << N / 2 - N << "\n";
  }
}