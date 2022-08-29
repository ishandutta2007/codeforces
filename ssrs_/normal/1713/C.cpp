#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> p(n);
    int s = (int) sqrt(n) + 1;
    int c = n - 1;
    for (int j = s; j >= 0; j--){
      if (j * j >= c && c >= 0){
        int x = j * j - c;
        if (x <= c){
          for (int k = x; k <= c; k++){
            p[k] = j * j - k;
          }
          c = x - 1;
        }
      }
    }
    for (int j = 0; j < n; j++){
      cout << p[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}