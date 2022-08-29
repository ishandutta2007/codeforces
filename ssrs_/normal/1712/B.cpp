#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    if (n == 1){
      cout << 1 << endl;
    } else {
      vector<int> a;
      if (n % 2 == 1){
        a.push_back(0);
        a.push_back(2);
        a.push_back(1);
      }
      while (a.size() < n){
        int m = a.size();
        a.push_back(m + 1);
        a.push_back(m);
      }
      for (int j = 0; j < n; j++){
        cout << a[j] + 1;
        if (j < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}