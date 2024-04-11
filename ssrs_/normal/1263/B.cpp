#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<string> p(n);
    for (int j = 0; j < n; j++){
      cin >> p[j];
    }
    map<string, vector<int>> mp;
    for (int j = 0; j < n; j++){
      mp[p[j]].push_back(j);
    }
    set<string> st;
    for (int j = 0; j < n; j++){
      st.insert(p[j]);
    }
    int k = 0;
    for (auto P : mp){
      int sz = P.second.size();
      k += sz - 1;
      for (int j = 0; j < sz - 1; j++){
        int id = P.second[j];
        for (int d = 0; d <= 9; d++){
          string s = p[id];
          s[0] = '0' + d;
          if (!st.count(s)){
            st.insert(s);
            p[id] = s;
            break;
          }
        }
      }
    }
    cout << k << endl;
    for (int j = 0; j < n; j++){
      cout << p[j] << endl;
    }
  }
}