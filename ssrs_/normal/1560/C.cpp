#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int k;
    cin >> k;
    int s = 1;
    while (k > s * s){
      s++;
    }
    int a = (s - 1) * (s - 1);
    if (k <= a + s){
      cout << k - a << ' ' << s << endl;
    } else {
      cout << s << ' ' << s - (k - a - s) << endl;
    }
  }
}