#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;
int nums[maxn];
int n, h;

bool check(int u) {
  vector<int> cv;
  for (int i = 1; i <= u; i++) {
    cv.push_back(nums[i]);
  }
  if (cv.size() % 2 == 1) cv.push_back(0);
  sort(cv.begin(), cv.end());

  int cur = h;
  for (int i = 1; i < cv.size(); i += 2) {
    cur -= cv[i];
    // cout << u << " : " << cv[i] << endl;
    if (cur < 0) return false;
  }
  return cur >= 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // int n, h;
  cin >> n >> h;


  int cur;
  for (int i = 1; i <= n; i++) {
    cin >> nums[i];
  }
  // sort(nums.begin(), nums.end());

  int lo = 0, hi = n;
  while (lo < hi) {
    int mid = (lo + hi+1)/2;
    if (check(mid)) {
      lo = mid;
    }
    else hi = mid-1;
  }
  cout << lo << endl;
}