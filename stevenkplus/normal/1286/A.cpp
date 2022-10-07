#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 111;
int ar[MAXN];
int prv[MAXN];
int nxt[MAXN];

typedef pair<int, int> pii;
vector<pii> odds;
vector<pii> evens;
int main() {
  int ans = 0;
  int n;
  cin >> n;
  int prv = -1;
  int run = 0;
  int o = (n + 1) / 2, e = n / 2;
  for (int i = 0; i < n; ++i) {
    cin >> ar[i];
    if (ar[i] == 0) {
      ++run;
    } else {
      if (ar[i] % 2 == 1) --o;
      else --e;
      if (prv == -1) {
        if (run > 0) {
          ans += 1;
          if (ar[i] % 2 == 1) {
            odds.push_back(pii(-1, run));
          } else {
            evens.push_back(pii(-1, run));
          }
        }
      } else if (prv % 2 == ar[i] % 2) {
        ans += 2;
        if (ar[i] % 2 == 1) {
          odds.push_back(pii(-2, run));
        } else {
          evens.push_back(pii(-2, run));
        }
      } else {
        ++ans;
      }
      run = 0;
      prv = ar[i];
    }
  }
  if (prv == -1) {
    if (n == 1) {
      cout << "0\n";
    } else {
      cout << "1\n";
    }
    return 0;
  }
  if (run > 0) {
    ans += 1;
    if (prv % 2 == 1) {
      odds.push_back(pii(-1, run));
    } else {
      evens.push_back(pii(-1, run));
    }
  }

  sort(odds.begin(), odds.end());
  sort(evens.begin(), evens.end());
  for (auto p: odds) {
    if (p.second <= o) {
      o -= p.second;
      ans += p.first;
    }
  }
  for (auto p: evens) {
    if (p.second <= e) {
      e -= p.second;
      ans += p.first;
    }
  }
  cout << ans << "\n";
}