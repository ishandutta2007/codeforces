#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  long long k;
  cin >> n >> k;
  k -= (long long) n * (n + 1) / 2;
  if (k < 0){
    cout << -1 << endl;
    return 0;
  }
  long long sum = (long long) n * (n + 1) / 2;
  vector<int> ans;
  for (int i = n - 1; i >= 0; i--){
    int add = max(0, n - 1 - (n - 1 - i) * 2);
    if (k > add){
      ans.push_back(i);
      ans[n - 1 - i] = i;
      k -= add;
      sum += add;
    } else {
      for (int j = 0; j < i; j++){
        ans.push_back(j);
      }
      ans.insert(ans.begin() + (n - 1 - i) + (add - k), i);
      sum += k;
      break;
    }
  }
  cout << sum << endl;
  for (int i = 0; i < n; i++){
    cout << i + 1;
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
  for (int i = 0; i < n; i++){
    cout << ans[i] + 1;
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}