#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    sort(a.begin(), a.end());
    int cnt = unique(a.begin(), a.end()) - a.begin();
    if (cnt % 2 != n % 2){
      cnt--;
    }
    cout << cnt << endl;
  }
}