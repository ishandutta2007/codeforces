#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> t(n);
  for (int i = 0; i < n; i++){
    cin >> t[i];
  }
  vector<bool> nice(n - 1);
  for (int i = 0; i < n; i++){
    if (i % 2 == 0){
      if (t[i] < t[i + 1]){
        nice[i] = true;
      } else {
        nice[i] = false;
      }
    }
    if (i % 2 == 1){
      if (t[i] > t[i + 1]){
        nice[i] = true;
      } else {
        nice[i] = false;
      }
    }
  }
  vector<int> S(n);
  S[0] = 0;
  for (int i = 0; i < n - 1; i++){
    if (nice[i]){
      S[i + 1] = S[i] + 1;
    } else {
      S[i + 1] = S[i];
    }
  }
  if (S[n - 1] < n - 5){
    cout << 0 << endl;
  } else {
    set<int> st;
    for (int i = 0; i < n - 1; i++){
      if (!nice[i]){
        st.insert(i);
        if (i < n - 1){
          st.insert(i + 1);
        }
      }
    }
    set<pair<int, int>> st2;
    for (int i : st){
      for (int j = 0; j < n; j++){
        if (i != j){
          swap(t[i], t[j]);
          set<int> st3;
          if (i > 0){
            st3.insert(i - 1);
          }
          if (i < n - 1){
            st3.insert(i);
          }
          if (j > 0){
            st3.insert(j - 1);
          }
          if (j < n - 1){
            st3.insert(j);
          }
          int cnt = S[n - 1];
          for (int p : st3){
            if (nice[p]){
              cnt--;
            }
            if (p % 2 == 0){
              if (t[p] < t[p + 1]){
                cnt++;
              }
            }
            if (p % 2 == 1){
              if (t[p] > t[p + 1]){
                cnt++;
              }
            }
          }
          if (cnt == n - 1){
            st2.insert(make_pair(min(i, j), max(i, j)));
          }
          swap(t[i], t[j]);
        }
      }
    }
    cout << st2.size() << endl;
  }
}