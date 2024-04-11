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
    vector<int> cnt(2, 0);
    for (int j = 0; j < n; j++){
      cnt[a[j] % 2]++;
    }
    cout<< min(cnt[0], cnt[1]) << endl;
  }
}