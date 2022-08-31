#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  map<int, int> mp;
  for (int i = 0; i < n; i++){
    mp[a[i]] = i + 1;
  }
  if (mp.size() < k){
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    auto itr = mp.begin();
    for (int i = 0; i < k; i++){
      cout << (*itr).second;
      if (i < k - 1){
        cout << ' ';
        itr++;
      }
    }
    cout << endl;
  }
}