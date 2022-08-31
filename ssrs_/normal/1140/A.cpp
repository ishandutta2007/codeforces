#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
  }
  int M = 0;
  int count = 0;
  for (int i = 0; i < n; i++){
    bool flg = true;
    for (int j = 0; j <= i; j++){
      if (a[j] > i){
        flg = false;
      }
    }
    if (flg){
      count++;
    }
  }
  cout << count << endl;
}