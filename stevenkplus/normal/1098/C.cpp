#include <cstdio>
#include <map>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;
const int MAXN = 100100;
int depths[MAXN];

int main() {
  ll n, s;
  cin >> n >> s;
  ll up = n * (n + 1) / 2;
  ll low = 1 + (n - 1) * 2;
  if (s < low || s > up) {
    cout << "No\n";
    return 0;
  }

  ll val = up;
  for(int i = 1; i <= n; ++i) {
    depths[i] = 1;
  }

  ll branch = 1;
  int mx = n;
  int mn = 2;
  while (val > s) {
    // printf("At (%d %d %d)\n", branch, mn, mx);
    while (mn >= mx || depths[mn] >= depths[mn - 1] * branch) {
      ++mn;
      if (mn >= mx) {
        mn = 2;
        ++branch;
      }
    }
    while (!depths[mx]) --mx;
    if (val - mx + mn >= s) {
      --depths[mx];
      ++depths[mn];
      val = val - mx + mn;
    } else {
      --depths[mx];
      ++depths[s - (val - mx)];
      val = s;
    }
  }

  // cout << "branch: " << branch << "\n";
  // for (int i = 1; i <= n; ++i) {
    // cout << i << ":" << depths[i] << "\n";
  // }

  cout << "Yes\n";
  vector<int> prev;
  prev.push_back(1);
  int id = 1;
  for(int i = 2; i <= n; ++i) {
    vector<int> next;
    for(int j = 0; j < depths[i]; ++j) {
      printf("%d ", prev[j % prev.size()]);
      ++id;
      next.push_back(id);
    }
    prev = next;
  }
  cout << "\n";
}