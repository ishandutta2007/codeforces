#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int s;
    cin >> s;
    int x = 1;
    while (true){
      if (x * x >= s){
        cout << x << endl;
        break;
      }
      x++;
    }
  }
}