#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> A(n, 0);
  int o12, o23, o31, a12, a23, a31;
  cout << "or " << 1 << ' ' << 2 << endl;
  cin >> o12;
  cout << "or " << 2 << ' ' << 3 << endl;
  cin >> o23;
  cout << "or " << 3 << ' ' << 1 << endl;
  cin >> o31;
  cout << "and " << 1 << ' ' << 2 << endl;
  cin >> a12;
  cout << "and " << 2 << ' ' << 3 << endl;
  cin >> a23;
  cout << "and " << 3 << ' ' << 1 << endl;
  cin >> a31;
  for (int i = 0; i < 30; i++){
    if ((a12 >> i & 1) == 1){
      A[0] += 1 << i;
      A[1] += 1 << i;
      if ((a23 >> i & 1) == 1){
        A[2] += 1 << i;
      }
    } else if ((o12 >> i & 1) == 0){
      if ((o23 >> i & 1) == 1){
        A[2] += 1 << i;
      }
    } else {
      if ((a23 >> i & 1) == 1){
        A[1] += 1 << i;
        A[2] += 1 << i;
      }
      if ((a31 >> i & 1) == 1){
        A[0] += 1 << i;
        A[2] += 1 << i;
      }
      if ((o23 >> i & 1) == 0){
        A[0] += 1 << i;
      }
      if ((o31 >> i & 1) == 0){
        A[1] += 1 << i;
      }
    }
  }
  for (int i = 3; i < n; i++){
    int o, a;
    cout << "or " << 1 << ' ' << i + 1 << endl;
    cin >> o;
    cout << "and " << 1 << ' ' << i + 1 << endl;
    cin >> a;
    int x = o ^ a;
    A[i] = x ^ A[0];
  }
  sort(A.begin(), A.end());
  k--;
  cout << "finish " << A[k] << endl;
}