#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    for (int j = 0; j < k; j++){
      if (a[j] < b[j]){
        swap(a[j], b[j]);
      }
    }
    long long sum = 0;
    for (int j = 0; j < n; j++){
      sum += a[j];
    }
    cout << sum << endl;
  }
}