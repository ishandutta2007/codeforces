#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
    p[i]--;
  }
  vector<int> q(n);
  for (int i = 0; i < n; i++){
    q[p[i]] = i;
  }
  long long ans = 0;
  set<int> st;
  st.insert(-1);
  st.insert(n);
  for (int i = n - 1; i >= 0; i--){
    int L = *prev(st.lower_bound(q[i]));
    int R = *st.lower_bound(q[i]);
    int dl = q[i] - L - 1;
    int dr = R - q[i] - 1;
    if (dl < dr){
      for (int j = L + 1; j < q[i]; j++){
        int a = i - 1 - p[j];
        if (0 <= a && a < n){
          if (q[i] < q[a] && q[a] < R){
            ans++;
          }
        }
      }
    } else {
      for (int j = q[i] + 1; j < R; j++){
        int a = i - 1 - p[j];
        if (0 <= a && a < n){
          if (L < q[a] && q[a] < q[i]){
            ans++;
          }
        }
      }
    }
    st.insert(q[i]);
  }
  cout << ans << endl;
}