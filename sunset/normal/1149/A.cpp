#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int one = 0, two = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (a == 1) {
      one++;
    } else {
      two++;
    }
  }
  vector<int> ans;
  if (!one) {
    ans = vector<int>(n, 2);
  } else if (!two) {
    ans = vector<int>(n, 1);
  } else {
    ans.push_back(2);
    ans.push_back(1);
    for (int i = 1; i < two; ++i) {
      ans.push_back(2);
    }
    for (int i = 1; i < one; ++i) {
      ans.push_back(1);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << "\n";
  return 0;
}