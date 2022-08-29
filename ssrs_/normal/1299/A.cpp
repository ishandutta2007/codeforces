#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> L(n + 1, 0);
  for (int i = 0; i < n; i++){
    L[i + 1] = L[i] | a[i];
  }
  vector<int> R(n + 1, 0);
  for (int i = n - 1; i >= 0; i--){
    R[i] = R[i + 1] | a[i];
  }
  int mx = -1;
  int max_id = 0;
  for (int i = 0; i < n; i++){
    int tmp = a[i] & ~(L[i] | R[i + 1]);
    if (mx < tmp){
      mx = tmp;
      max_id = i;
    }
  }
  cout << a[max_id];
  for (int i = 0; i < n; i++){
    if (i != max_id){
      cout << ' ' << a[i];
    }
  }
  cout << endl;
}