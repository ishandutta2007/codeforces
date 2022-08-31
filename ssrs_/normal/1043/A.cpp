#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int s = 0;
  int m = 0;
  for (int i = 0; i < n; i++){
    s += a[i];
    m = max(m, a[i]);
  }
  int k = m;
  while (k * n - s <= s){
    k++;
  }
  cout << k << endl;
}