#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    if (m < n){
      cout << "No" << "\n";
    } else if (n % 2 == 1){
      cout << "Yes" << "\n";
      for (int j = 0; j < n - 1; j++){
        cout << 1 << ' ';
      }
      cout << m - (n - 1) << "\n";
    } else if (m % 2 == 1){
      cout << "No" << "\n";
    } else {
      cout << "Yes" << "\n";
      for (int j = 0; j < n - 2; j++){
        cout << 1 << ' ';
      }
      cout << (m - n + 2) / 2 << ' ' << (m - n + 2) / 2 << "\n";
    }
  }
}