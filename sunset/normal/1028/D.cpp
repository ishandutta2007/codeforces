#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  set<int> buy, sell, others;
  int n, answer = 1;
  cin >> n;
  while (n--) {
    string type;
    int value;
    cin >> type >> value;
    if (type == "ADD") {
      if (!buy.empty() && value < *buy.rbegin()) {
        buy.insert(value);
      } else if (!sell.empty() && value > *sell.begin()) {
        sell.insert(value);
      } else {
        others.insert(value);
      }
    } else {
      if (!buy.empty() && value < *buy.rbegin()) {
        puts("0");
        return 0;
      }
      if (!sell.empty() && value > *sell.begin()) {
        puts("0");
        return 0;
      }
      if (buy.find(value) != buy.end()) {
        buy.erase(value);
        for (auto x : others) {
          sell.insert(x);
        }
        others.clear();
      } else if (sell.find(value) != sell.end()) {
        sell.erase(value);
        for (auto x : others) {
          buy.insert(x);
        }
        others.clear();
      } else {
        answer = (answer << 1) % mod;
        others.erase(value);
        for (auto x : others) {
          if (x < value) {
            buy.insert(x);
          } else {
            sell.insert(x);
          }
        }
        others.clear();
      }
    }
  }
  answer = (long long)answer * (others.size() + 1) % mod;
  printf("%d\n", answer);
  return 0;
}