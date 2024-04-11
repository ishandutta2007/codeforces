#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  cout << "? 1" << endl;
  vector<int> d1(n);
  for (int i = 0; i < n; i++){
    cin >> d1[i];
  }
  vector<int> cnt(2, 0);
  for (int i = 0; i < n; i++){
    cnt[d1[i] % 2]++;
  }
  int P;
  if (cnt[0] <= cnt[1]){
    P = 0;
  } else {
    P = 1;
  }
  vector<int> u, v;
  if (P == 0){
    for (int i = 0; i < n; i++){
      if (d1[i] == 1){
        u.push_back(0);
        v.push_back(i);
      }
    }
  }
  for (int i = 1; i < n; i++){
    if (d1[i] % 2 == P){
      cout << "? " << i + 1 << endl;
      vector<int> d(n);
      for (int j = 0; j < n; j++){
        int d;
        cin >> d;
        if (d == 1){
          u.push_back(i);
          v.push_back(j);
        }
      }
    }
  }
  cout << "!" << endl;
  for (int i = 0; i < n - 1; i++){
    cout << u[i] + 1 << ' ' << v[i] + 1 << endl;
  }
}