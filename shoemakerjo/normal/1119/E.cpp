#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int maxn = 300010;
int n;

ll nums[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll res = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  ll nc = 0;
  for (int i = 0; i < n; i++) {
    ll cm = min(nums[i]/2, nc);
    res += cm;
    nc -= cm;
    nums[i] -= cm*2;

    res += nums[i]/3;
    nums[i] -= (nums[i]/3) * 3;
    nc += nums[i];
  }
  cout << res << endl;
}