#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k, x;
  cin >> n >> k >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> c(1024, 0);
  for (int i = 0; i < n; i++){
    c[a[i]]++;
  }
  for (int i = 0; i < k; i++){
    vector<int> c2(1024, 0);
    int s = 0;
    for (int j = 0; j < 1024; j++){
      if (s % 2 == 0){
        c2[j ^ x] += (c[j] + 1) / 2;
        c2[j] += c[j] / 2;
      } else {
        c2[j ^ x] += c[j] / 2;
        c2[j] += (c[j] + 1) / 2;
      }
      s += c[j];
    }
    swap(c, c2);
  }
  vector<int> ans;
  for (int i = 0; i < 1024; i++){
    if (c[i] > 0){
      ans.push_back(i);
    }
  }
  cout << ans.back() << ' ' << ans.front() << endl;
}