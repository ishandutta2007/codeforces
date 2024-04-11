#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    cout << n;
    for (int j = 1; j < n; j++){
      cout << ' ' << j;
    }
    cout << endl;
  }
}