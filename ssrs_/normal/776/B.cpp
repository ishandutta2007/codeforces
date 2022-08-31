#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  if (n == 1){
    cout << 1 << endl;
    cout << 1 << endl;
  } else if (n == 2){
    cout << 1 << endl;
    cout << 1 << ' ' << 1 << endl;
  } else {
    vector<bool> prime(n + 2, true);
    for (int i = 2; i < n + 2; i++){
      if (prime[i]){
        for (int j = i * 2; j < n + 2; j += i){
          prime[j] = false;
        }
      }
    }
    cout << 2 << endl;
    for (int i = 2; i < n + 2; i++){
      if (prime[i]){
        cout << 1;
      } else {
        cout << 2;
      }
      if (i < n + 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}