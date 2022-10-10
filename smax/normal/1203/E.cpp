#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, freq[150000] = {0};
  bool taken[150001] = {false};
  cin >> n;
  for (int i=0; i<n; i++) {
    int a;
    cin >> a;
    freq[a-1]++;
  }

  unordered_set<int> weights;
  for (int i=0; i<150000; i++) {
    if (freq[i] >= 3) {
      if (i > 0) {
        weights.insert(i-1);
        taken[i-1] = false;
      }
      weights.insert(i);
      weights.insert(i+1);
      taken[i] = taken[i+1] = true;
    } else if (freq[i] == 2) {
      int num = 0;
      if (i > 0 && !taken[i-1]) {
        weights.insert(i-1);
        taken[i-1] = true;
        num++;
      }
      if (!taken[i]) {
        weights.insert(i);
        taken[i] = true;
        num++;
      }
      if (num < 2 && !taken[i+1]) {
        weights.insert(i+1);
        taken[i+1] = true;
      }
    } else if (freq[i] == 1) {
      if (i > 0 && !taken[i-1]) {
        weights.insert(i-1);
        taken[i-1] = true;
      } else if (!taken[i]) {
        weights.insert(i);
        taken[i] = true;
      } else if (!taken[i+1]) {
        weights.insert(i+1);
        taken[i+1] = true;
      }
    }
  }

  cout << weights.size() << "\n";

  return 0;
}