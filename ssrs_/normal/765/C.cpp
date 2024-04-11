#include <bits/stdc++.h>
using namespace std;
int main(){
  int k, a, b;
  cin >> k >> a >> b;
  if (a < k && b < k){
    cout << -1 << endl;
  } else if (a < k && b % k != 0){
    cout << -1 << endl;
  } else if (b < k && a % k != 0){
    cout << -1 << endl;
  } else {
    cout << a / k + b / k << endl;
  }
}