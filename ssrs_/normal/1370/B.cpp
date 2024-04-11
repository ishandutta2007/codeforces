#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n * 2);
    for (int j = 0; j < n * 2; j++){
      cin >> a[j];
    }
    vector<int> odd, even;
    for (int j = 0; j < n * 2; j++){
      if (a[j] % 2 == 0){
        even.push_back(j + 1);
      } else {
        odd.push_back(j + 1);
      }
    }
    for (int i = 0; i < n - 1; i++){
      if (odd.size() >= 2){
        cout << odd.back();
        cout << ' ';
        odd.pop_back();
        cout << odd.back();
        odd.pop_back();
      } else if (even.size() >= 2){
        cout << even.back();
        cout << ' ';
        even.pop_back();
        cout << even.back();
        even.pop_back();
      } else {
        cout << odd.back();
        cout << ' ';
        odd.pop_back();
        cout << even.back();
        even.pop_back();
      }
      cout << endl;
    }
  }
}