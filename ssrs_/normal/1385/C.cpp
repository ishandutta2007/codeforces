#include <bits/stdc++.h>
using namespace std;
bool good(deque<int> b){
  vector<int> c;
  while (!b.empty()){
    if (b.front() < b.back()){
      c.push_back(b.front());
      b.pop_front();
    } else {
      c.push_back(b.back());
      b.pop_back();
    }
  }
  int n = c.size();
  for (int i = 0; i < n - 1; i++){
    if (c[i] > c[i + 1]){
      return false;
    }
  }
  return true;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int tv = n - 1;
    int fv = -1;
    while (tv - fv > 1){
      int mid = (tv + fv) / 2;
      int m = n - mid;
      deque<int> b(m);
      for (int j = 0; j < m; j++){
        b[j] = a[j + mid];
      }
      if (good(b)){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    cout << tv << endl;
  }
}