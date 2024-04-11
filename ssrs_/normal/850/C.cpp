#include <bits/stdc++.h>
using namespace std;
map<int, int> grundy;
int f(int x){
  if (!grundy.count(x)){
    set<int> st;
    for (int k = 1; k <= 30; k++){
      if (x >= (1 << k)){
        st.insert(f((x & ((1 << k) - 1)) | (x >> k)));
      }
    }
    grundy[x] = 0;
    while (st.count(grundy[x])){
      grundy[x]++;
    }
  }
  return grundy[x];
}
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> b = a;
  map<int, int> mp;
  for (int i = 0; i < n; i++){
    for (int j = 2; j * j <= a[i]; j++){
      int X = 0;
      while (a[i] % j == 0){
        X++;
        a[i] /= j;
      }
      if (X > 0){
        mp[j] |= 1 << X;
      }
    }
    if (a[i] > 1){
      mp[a[i]] |= 2;
    }
  }
  int X = 0;
  for (auto P : mp){
    X ^= f(P.second);
  }
  if (X == 0){
    cout << "Arpa" << endl;
  } else {
    cout << "Mojtaba" << endl;
  }
}