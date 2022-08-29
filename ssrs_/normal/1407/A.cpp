#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
      cin >> a[i];
    }
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++){
      if (a[i] == 0){
        zero++;
      } else {
        one++;
      }
    }
    if (zero >= one){
      cout << zero << endl;
      for (int i = 0; i < zero; i++){
        cout << 0;
        if (i < zero - 1){
          cout << ' ';
        }
      }
      cout << endl;
    } else {
      cout << one / 2 * 2 << endl;
      for (int i = 0; i < one / 2 * 2; i++){
        cout << 1;
        if (i < one - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}