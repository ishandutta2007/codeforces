#include <bits/stdc++.h>
using namespace std;
long long dfs(vector<int> &a, int &A, int &B, int l, int r){
  auto itr1 = lower_bound(a.begin(), a.end(), l);
  auto itr2 = lower_bound(a.begin(), a.end(), r);
  if (itr1 == itr2){
    return A;
  } else if (r - l == 1){
    return B * (itr2 - itr1);
  } else {
    int m = (l + r) / 2;
    long long ans1 = dfs(a, A, B, l, m) + dfs(a, A, B, m, r);
    long long ans2 = (long long) B * (itr2 - itr1) * (r - l);
    return min(ans1, ans2);
  }
}
int main(){
  int n, k, A, B;
  cin >> n >> k >> A >> B;
  vector<int> a(k);
  for (int i = 0; i < k; i++){
    cin >> a[i];
    a[i]--;
  }
  sort(a.begin(), a.end());
  cout << dfs(a, A, B, 0, 1 << n) << endl;
}