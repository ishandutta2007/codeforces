#include <bits/stdc++.h>

using namespace std;

const int MAGIC = 3000;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int a;
  cin >> a;
  vector<vector<tuple<int, int, int>>> from(a, vector<tuple<int, int, int>>(MAGIC * 2, make_tuple(-1, -1, -1)));
  queue<pair<int, int>> q;
  q.emplace(0, MAGIC);
  while (!q.empty()) {
    int carry = q.front().first;
    int balance = q.front().second;
    q.pop();
    for (int d = !carry && balance == MAGIC; d < 10; ++d) {
      int new_carry = (carry + a * d) / 10;
      int new_balance = balance + (carry + a * d) % 10 * a - d;
      if (new_balance >= 0 && new_balance < MAGIC * 2 && get<0>(from[new_carry][new_balance]) == -1) {
        from[new_carry][new_balance] = make_tuple(carry, balance, d);
        q.emplace(new_carry, new_balance);
      }
    }
  }
  if (get<0>(from[0][MAGIC]) == -1) {
    cout << -1 << "\n";
    return 0;
  }
  bool first = true;
  int carry = 0;
  int balance = MAGIC;
  do {
    int new_carry = get<0>(from[carry][balance]);
    int new_balance = get<1>(from[carry][balance]);
    int d = get<2>(from[carry][balance]);
    if (!first || d) {
      cout << d;
      first = false;
    }
    carry = new_carry;
    balance = new_balance;
  } while (carry || balance != MAGIC);
  cout << "\n";
  return 0;
}