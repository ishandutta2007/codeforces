#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<bool> prime(20001, true);
  prime[1] = false;
  for (int i = 2; i <= 20000; i++){
    if (prime[i]){
      for (int j = i * 2; j <= 20000; j += i){
        prime[j] = false;
      }
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int S = 0;
    for (int j = 0; j < n; j++){
      S += a[j];
    }
    vector<int> p;
    if (prime[S]){
      for (int j = 0; j < n; j++){
        if (!prime[S - a[j]]){
          p.push_back(j);
          break;
        }
      }
    }
    int cnt = p.size();
    vector<bool> used(n, true);
    for (int j = 0; j < cnt; j++){
      used[p[j]] = false;
    }
    vector<int> ans;
    for (int j = 0; j < n; j++){
      if (used[j]){
        ans.push_back(j);
      }
    }
    int x = ans.size();
    cout << x << endl;
    for (int j = 0; j < x; j++){
      cout << ans[j] + 1;
      if (j < x - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}