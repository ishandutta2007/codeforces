#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int maxn = 100010;
int nums[maxn];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n;
  ll res = 0LL;
  set<int> vals;
  for (int i = 1; i <= n; i++) {
    cin >> nums[i];
    vals.insert(nums[i]);
  }
  ll x = vals.size();
  vals.insert(0);
  vals.insert(n+1);
  vector<int> garb;
  for (int v : vals) {
    garb.push_back(v);
  }
  res += n * (n-1LL)/2LL;
  res += n; //WE NEED TO FIX THIS PART

  for (int i = 0; i < garb.size()-1; i++) {
    int st = garb[i]+1;
    int en = garb[i+1]-1;
    ll cv = en - st + 1LL;
    res -= cv * (cv-1LL)/2LL;
    res -= cv;
  }

  //actually this res is NOT correct

  set<int> cseen;
  for (int i = 2; i <= n; i++) {

    // cout << i << " : " << res << endl;

    cseen.insert(nums[i-1]);
    if (nums[i-1] == nums[i]) continue;

    auto it = cseen.lower_bound(nums[i]);

    if (it != cseen.end() && *it == nums[i]) {

      // cout << " this this " << endl;

      if (nums[i-1] > nums[i]) {
        res += (nums[i-1] - nums[i] + 0LL) *
          (nums[i]);
      }
      else {
        res += (nums[i] - nums[i-1] + 0LL) *
          (n - nums[i]+1LL);
      }
    }
    else {
      int ab = -1, bel = -1;

      // cout << "    " << ab << " " << bel << endl;

      //first above and first below
      if (it != cseen.end()) {
        ab = *it;
      }
      if (it != cseen.begin()) {
        --it;
        bel = *it;
      }

      if (ab == -1 && bel == -1) continue;

      if (ab != -1) {
        //go and grab the ab value
        if (nums[i-1] > nums[i]) {
          res += (nums[i-1] - ab + 0LL) * (nums[i]);
        }
        else {
          res += (n - ab + 1LL) * (nums[i] - nums[i-1]);
        }
      }
      if (bel != -1) {
        if (nums[i-1] > nums[i]) {
          res += (bel) * (nums[i-1]-nums[i]+0LL);
        }
        else {
          res += (bel - nums[i-1] + 0LL) * (n - nums[i]+1LL);
        }
      }
      if (ab != -1 && bel != -1) {
        //subtract out when we get both
        if (nums[i-1] > nums[i]) {
          res -= (nums[i-1]-ab + 0LL) * bel;
        }
        else {
          res -= (n - ab + 1LL) * (bel - nums[i-1]);
        }
      }

    }

  }
  cout << res << endl;
}