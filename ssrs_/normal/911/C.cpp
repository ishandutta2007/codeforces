#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> k(3);
  for (int i = 0; i < 3; i++){
    cin >> k[i];
  }
  sort(k.begin(), k.end());
  if (k[0] == 1){
    cout << "YES" << endl;
  } else if (k[0] == 2){
    if (k[1] == 2){
      cout << "YES" << endl;
    } else if (k[1] == 4){
      if (k[2] == 4){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  } else if (k[0] == 3){
    if (k[1] == 3 && k[2] == 3){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    cout << "NO" << endl;
  }
}