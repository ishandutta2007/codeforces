#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  vector<int> primes;
  vector<int> cnt(MAX);
  for (int i = 2; i < MAX; ++i) {
    if (!cnt[i]) {
      cnt[i] = 1;
      primes.push_back(i);
    }
    for (auto p : primes) {
      if (i * p >= MAX) {
        break;
      }
      cnt[i * p] = cnt[i] + 1;
      if (i % p == 0) {
        break;
      }
    }
  }
  int n, m;
  scanf("%d %d", &n, &m);
  bitset<MAX> trans;
  for (int i = 2; i < MAX; ++i) {
    if (i != m && cnt[i] <= 2) {
      trans[i] = true;
    }
  }
  trans[0] = true;
  vector<bitset<MAX>> ban(1);
  vector<int> sg(MAX);
  ban[0] |= trans;
  for (int i = 1; i < MAX; ++i) {
    bool found = false;
    for (int j = 0; j < ban.size(); ++j) {
      if (!ban[j][i]) {
        sg[i] = j;
        ban[j] |= trans << i;
        found = true;
        break;
      }
    }
    if (!found) {
      sg[i] = ban.size();
      ban.push_back(trans << i);
    }
  }
  int sg_all = 0;
  for (int i = 0; i < n; ++i) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    sg_all ^= sg[y - x - 1] ^ sg[z - y - 1];
  }
  if (sg_all) {
    puts("Alice\nBob");
  } else {
    puts("Bob\nAlice");
  }
  return 0;
}