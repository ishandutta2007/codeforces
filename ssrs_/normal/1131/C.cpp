#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<int> b1, b2;
  b1.push_back(a[0]);
  b2.push_back(a[0]);
  for (int i = 1; i < n - 1; i++){
    if (b1.back() < b2.back()){
      b1.push_back(a[i]);
    } else {
      b2.push_back(a[i]);
    }
  }
  b1.push_back(a[n - 1]);
  while (b2.size() > 1){
    b1.push_back(b2.back());
    b2.pop_back();
  }
  for (int i = 0; i < n; i++){
    cout << b1[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}