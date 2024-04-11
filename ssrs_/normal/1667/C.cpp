#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  if (n % 3 != 0){
    cout << n / 3 * 2 + 1 << endl;
    cout << 1 << ' ' << 1 << endl;
    for (int i = 0; i < n / 3; i++){
      cout << i + 2 << ' ' << i * 2 + 3 << endl;
    }
    for (int i = 0; i < n / 3; i++){
      cout << n / 3 + 2 + i << ' ' << i * 2 + 2 << endl;
    }
  } else {
    cout << n / 3 * 2 << endl;
    cout << 1 << ' ' << 1 << endl;
    for (int i = 0; i < n / 3 - 1; i++){
      cout << i + 2 << ' ' << i * 2 + 3 << endl;
    }
    for (int i = 0; i < n / 3 - 1; i++){
      cout << n / 3 + 1 + i << ' ' << i * 2 + 2 << endl;
    }
    cout << n / 3 * 2 << ' ' << n / 3 * 2 << endl;
  }
}