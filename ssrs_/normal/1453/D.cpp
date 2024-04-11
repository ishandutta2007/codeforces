#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long k;
    cin >> k;
    if (k % 2 == 1){
      cout << -1 << endl;
    } else {
      vector<long long> s(59);
      for (int j = 0; j < 59; j++){
        s[j] = ((long long) 1 << (j + 2)) - 2;
      }
      vector<int> ans;
      ans.push_back(1);
      k -= 2;
      while (k > 0){
        auto itr = upper_bound(s.begin(), s.end(), k) - 1;
        k -= *itr;
        for (int j = 0; j < itr - s.begin(); j++){
          ans.push_back(0);
        }
        ans.push_back(1);
      }
      int n = ans.size();
      cout << n << endl;
      for (int j = 0; j < n; j++){
        cout << ans[j];
        if (j < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}