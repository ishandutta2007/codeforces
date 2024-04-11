#include <iostream>
#include <algorithm>

using namespace std;

long long A, B;
int main() {
  cin >> A >> B;
  long long steps = 0;
  while (A != 1 && B != 1) {
    if (A < B) swap(A, B);
    steps += A / B;
    A %= B;
  }

  if (A < B) swap(A, B);
  steps += A;

  cout << steps << endl;
  return 0;
}