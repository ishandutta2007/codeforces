#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    if (n % 2 == 1){
      if (n == 1){
        cout << "a" << endl;
      } else {
        string s = string(n / 2, 'a') + "bc" + string(n / 2 - 1, 'a');
        cout << s << endl;
      }
    } else {
      string s = string(n / 2, 'a') + "b" + string(n / 2 - 1, 'a');
      cout << s << endl;
    }
  }
}