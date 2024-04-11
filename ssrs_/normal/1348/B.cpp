#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    set<int> count;
    for (int j = 0; j < n; j++){
      count.insert(a[j]);
    }
    if (count.size() > k){
      cout << -1 << endl;
    } else {
      vector<int> num;
      for (int j : count){
        num.push_back(j);
      }
      while (num.size() < k){
        num.push_back(num.back());
      }
      cout << n * k << endl;
      for (int j = 0; j < n * k; j++){
        cout << num[j % k];
        if (j < n * k - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}