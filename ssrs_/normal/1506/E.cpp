#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> q(n);
    for (int j = 0; j < n; j++){
      cin >> q[j];
    }
    vector<bool> a(n, false);
    a[0] = true;
    for (int j = 1; j < n; j++){
      if (q[j] > q[j - 1]){
        a[j] = true;
      }
    }
    set<int> st1, st2;
    for (int j = 1; j <= n; j++){
      st1.insert(j);
      st2.insert(j);
    }
    vector<int> ans1(n, -1), ans2(n);
    for (int j = 0; j < n; j++){
      if (a[j]){
        ans1[j] = q[j];
        ans2[j] = q[j];
        st1.erase(q[j]);
        st2.erase(q[j]);
      }
    }
    for (int j = 0; j < n; j++){
      if (!a[j]){
        ans1[j] = *st1.begin();
        st1.erase(ans1[j]);
        ans2[j] = *prev(st2.upper_bound(q[j]));
        st2.erase(ans2[j]);
      }
    }
    for (int j = 0; j < n; j++){
      cout << ans1[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
    for (int j = 0; j < n; j++){
      cout << ans2[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}