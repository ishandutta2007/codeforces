#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> x(n);
    for (int j = 0; j < n; j++){
      cin >> x[j];
    }
    set<int> st;
    for (int j = 0; j < n; j++){
      for (int k = j + 1; k < n; k++){
        st.insert(x[k] - x[j]);
      }
    }
    cout << st.size() << endl;
  }
}