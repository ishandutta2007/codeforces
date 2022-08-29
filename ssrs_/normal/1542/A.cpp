#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    int cnt = 0;
    for (int j = 0; j < n * 2; j++){
      int a;
      cin >> a;
      if (a % 2 == 1){
        cnt++;
      }
    }
    if (cnt == n){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}