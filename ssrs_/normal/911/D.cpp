#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int cnt = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < i; j++){
      if (a[i] < a[j]){
        cnt++;
      }
    }
  }
  bool odd = (cnt % 2 == 1);
  int m;
  cin >> m;
  for (int i = 0; i < m; i++){
    int l, r;
    cin >> l >> r;
    l--;
    if ((r - l) % 4 >= 2){
      odd = !odd;
    }
    if (odd){
      cout << "odd" << "\n";
    } else {
      cout << "even" << "\n";
    }
  }
}