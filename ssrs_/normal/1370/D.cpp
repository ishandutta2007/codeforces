#include <bits/stdc++.h>
using namespace std;
int INF = 1000000001;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int tv = INF;
  int fv = 0;
  while (tv - fv > 1){
    int mid = (tv + fv) / 2;
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < n; i++){
      if (cnt1 % 2 == 0 || a[i] <= mid){
        cnt1++;
      }
      if (cnt2 % 2 == 1 || a[i] <= mid){
        cnt2++;
      }
    }
    if (cnt1 >= k || cnt2 >= k){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  cout << tv << endl;
}