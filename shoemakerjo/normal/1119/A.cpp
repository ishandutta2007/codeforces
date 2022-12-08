#include <bits/stdc++.h>

using namespace std;

int n;
const int maxn = 300010;
int nums[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> nums[i];
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (nums[i] != nums[1]) res = max(res, i - 1);
    if (nums[i] != nums[n]) res = max(res, n-i);
  }
  cout << res << endl;
}