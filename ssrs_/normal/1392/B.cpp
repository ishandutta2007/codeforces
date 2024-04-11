#include <bits/stdc++.h>
using namespace std;
vector<long long> op(vector<long long> a){
  int n = a.size();
  long long d = *max_element(a.begin(), a.end());
  for (int i = 0; i < n; i++){
    a[i] = d - a[i];
  }
  return a;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    if (k >= 3){
      k = k % 2 + 2;
    }
    for (int j = 0; j < k; j++){
      a = op(a);
    }
    for (int j = 0; j < n; j++){
      cout << a[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}