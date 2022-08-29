#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
  }
  vector<int> p(50, n);
  for (int i = 0; i < n; i++){
    if (p[a[i]] == n){
      p[a[i]] = i;
    }
  }
  for (int i = 0; i < q; i++){
    int t;
    cin >> t;
    t--;
    cout << p[t] + 1;
    if (i < q - 1){
      cout << ' ';
    }
    for (int j = 0; j < 50; j++){
      if (p[j] < p[t]){
        p[j]++;
      }
    }
    p[t] = 0;
  }
  cout << endl;
}