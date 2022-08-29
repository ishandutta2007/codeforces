#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int mx = 0;
  for (int i = 0; i < n; i++){
    mx = max(mx, a[i]);
  }
  long long tv = INF, fv = mx - 1;
  while (tv - fv > 1){
    long long mid = (tv + fv) / 2;
    long long sum = 0;
    for (int i = 0; i < n; i++){
      sum += mid - a[i];
    }
    if (sum >= mid){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  cout << tv << endl;
}