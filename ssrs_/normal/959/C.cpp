#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  //Incorrect
  if (n < 6){
    cout << -1 << endl;
  } else {
    for (int i = 2; i <= n - 2; i++){
      cout << 1 << ' ' << i << endl;
    }
    cout << n - 2 << ' ' << n - 1 << endl;
    cout << n - 2 << ' ' << n << endl;
  }
  //Correct
  for (int i = 2; i <= n; i++){
    cout << 1 << ' ' << i << endl;
  }
}