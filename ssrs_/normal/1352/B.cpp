#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    if (n % 2 == 1){
      if (k % 2 == 0){
        cout << "NO" << endl;
      } else {
        vector<int> a;
        for (int j = 0; j < k - 1; j++){
          a.push_back(1);
          n -= 1;
        }
        a.push_back(n);
        if (n <= 0){
          cout << "NO" << endl;
        } else {
          cout << "YES" << endl;
          for (int j = 0; j < k; j++){
            cout << a[j];
            if (j < k - 1){
              cout << ' ';
            }
          }
          cout << endl;
        }
      }
    } else {
      //n is even
      if (k % 2 == 1){
        vector<int> a;
        for (int j = 0; j < k - 1; j++){
          a.push_back(2);
          n -= 2;
        }
        a.push_back(n);
        if (n <= 0){
          cout << "NO" << endl;
        } else {
          cout << "YES" << endl;
          for (int j = 0; j < k; j++){
            cout << a[j];
            if (j < k - 1){
              cout << ' ';
            }
          }
          cout << endl;
        }
      } else {
        vector<int> a;
        for (int j = 0; j < k - 1; j++){
          a.push_back(1);
          n -= 1;
        }
        a.push_back(n);
        if (n <= 0){
          cout << "NO" << endl;
        } else {
          cout << "YES" << endl;
          for (int j = 0; j < k; j++){
            cout << a[j];
            if (j < k - 1){
              cout << ' ';
            }
          }
          cout << endl;
        }
      }
    }
  }
}