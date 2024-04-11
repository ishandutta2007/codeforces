#include <bits/stdc++.h>
using namespace std;
void f(vector<string> &a, int i, int j){
  if (a[i][j] == '9'){
    a[i][j] = '1';
  } else {
    a[i][j]++;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    vector<string> a(9);
    for (int j = 0; j < 9; j++){
      cin >> a[j];
    }
    f(a, 0, 0);
    f(a, 1, 4);
    f(a, 2, 8);
    f(a, 3, 1);
    f(a, 4, 5);
    f(a, 5, 6);
    f(a, 6, 2);
    f(a, 7, 3);
    f(a, 8, 7);
    for (int j = 0; j < 9; j++){
      cout << a[j];
      if (j < 8){
        cout << '\n';
      } else {
        cout << endl;
      }
    }
  }
}