#include <bits/stdc++.h>
using namespace std;
int main(){
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int n;
    cin >> n;
    vector<int> t(n);
    for (int j = 0; j < n; j++){
      cin >> t[j];
    }
    bool one_color = true;
    for (int j = 1; j < n; j++){
      if (t[j] != t[0]){
        one_color = false;
      }
    }
    if (one_color){
      cout << 1 << endl;
      for (int j = 0; j < n; j++){
        cout << 1;
        if (j < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    } else {
      bool three_colors = true;
      if (n % 2 == 0){
        three_colors = false;
      }
      for (int j = 0; j < n - 1; j++){
        if (t[j] == t[j + 1]){
          three_colors = false;
        }
      }
      if (t[n - 1] == t[0]){
        three_colors = false;
      }
      if (three_colors){
        cout << 3 << endl;
        for (int j = 0; j < n - 1; j++){
          if (j % 2 == 0){
            cout << "1 ";
          } else {
            cout << "2 ";
          }
        }
        cout << "3" << endl;
      } else {
        //two colors
        cout << 2 << endl;
        if (n % 2 == 0){
          for (int j = 0; j < n; j++){
            if (j % 2 == 0){
              cout << 1;
            } else {
              cout << 2;
            }
            if (j < n - 1){
              cout << ' ';
            }
          }
          cout << endl;
        } else {
          int change = n;
          for (int j = 0; j < n - 1; j++){
            if (t[j] == t[j + 1]){
              change = j;
              break;
            }
          }
          for (int j = 0; j < n; j++){
            if (j % 2 == 0 && j < change){
              cout << 1;
            } else if (j % 2 == 0 && j > change){
              cout << 2;
            } else if (j % 2 == 1 && j <= change){
              cout << 2;
            } else {
              cout << 1;
            }
            if (j < n - 1){
              cout << ' ';
            }
          }
          cout << endl;
        }
      }
    }
  }
}