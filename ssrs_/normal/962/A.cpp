#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    if (i > 0){
      a[i] += a[i - 1];
    }
  }
  for (int i = 0; i < n; i++){
    if (a[i] >= (a[n - 1] + 1) / 2){
      cout << i + 1 << endl;
      break;
    }
  }
}