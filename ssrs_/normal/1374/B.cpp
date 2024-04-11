#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    int two = 0;
    while (n % 2 == 0){
      n /= 2;
      two++;
    }
    int three = 0;
    while (n % 3 == 0){
      n /= 3;
      three++;
    }
    if (n != 1){
      cout << -1 << endl;
    } else if (two > three){
      cout << -1 << endl;
    } else {
      cout << three + (three - two) << endl;
    }
  }
}