#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> cnt(x + 1, 0);
  for (int i = 0; i < n; i++){
    cnt[a[i]]++;
  }
  bool ok = true;
  for (int i = 1; i < x; i++){
    if (cnt[i] % (i + 1) != 0){
      ok = false;
    } else {
      cnt[i + 1] += cnt[i] / (i + 1);
    }
  }
  if (ok){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}