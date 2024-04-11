#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    if (n == 3){
      cout << -1 << endl;
    } else {
      vector<int> p;
      int x = 0;
      if (n % 2 == 1){
        p = vector<int>{4, 3, 0, 1, 2};
        x += 5;
      }
      for (int j = x; j < n; j += 2){
        p.push_back(j + 1);
        p.push_back(j);
      }
      for (int j = 0; j < n; j++){
        cout << p[j] + 1;
        if (j < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}