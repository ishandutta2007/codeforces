#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    cout << max({min(a1, a2) * min(a3, a4), min(a1, a3) * min(a2, a4), min(a1, a4) * min(a2, a3)}) << endl;
  }
}