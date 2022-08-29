#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> X(n, 0);
  for (int i = 1; i < n; i++){
    cout << "XOR " << 1 << " " << i + 1 << endl;
    cin >> X[i];
  }
  int A01, A02, A12;
  cout << "AND " << 1 << " " << 2 << endl;
  cin >> A01;
  cout << "AND " << 1 << " " << 3 << endl;
  cin >> A02;
  cout << "AND " << 2 << " " << 3 << endl;
  cin >> A12;
  int f = 0;
  for (int i = 0; (1 << i) < n; i++){
    if (!(X[1] >> i & 1)){
      if (A01 >> i & 1){
        f |= 1 << i;
      }
    } else if (!(X[2] >> i & 1)){
      if (A02 >> i & 1){
        f |= 1 << i;
      }
    } else {
      if (!(A12 >> i & 1)){
        f |= 1 << i;
      }
    }
  }
  vector<int> ans(n);
  ans[0] = f;
  for (int i = 1; i < n; i++){
    ans[i] = f ^ X[i];
  }
  cout << "!";
  for (int i = 0; i < n; i++){
    cout << ' ' << ans[i];
  }
  cout << endl;
}