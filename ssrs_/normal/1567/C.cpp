#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string n;
    cin >> n;
    int L = n.size();
    int a = 0, b = 0;
    for (int j = 0; j < L; j++){
      if (j % 2 == 0){
        a = a * 10 + (n[j] - '0');
      }
      if (j % 2 == 1){
        b = b * 10 + (n[j] - '0');
      }
    }
    cout << (a + 1) * (b + 1) - 2 << endl;
  }
}