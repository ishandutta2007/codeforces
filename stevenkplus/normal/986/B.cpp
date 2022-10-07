#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1001000;

int BIT[MAXN];
void inc(int x) {
  while (x < MAXN) {
    BIT[x] += 1;
    x += x & -x;
  }
}

int ask(int x) {
  int res = 0;
  while (x) {
    res += BIT[x];
    x -= x & -x;
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  int sum = 0;
  for(int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    sum += i - 1 - ask(x);
    sum %= 2;
    inc(x);
  }

  if (sum == n % 2) {
    cout << "Petr\n";
  } else {
    cout << "Um_nik\n";
  }
}