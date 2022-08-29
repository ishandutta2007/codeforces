#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> p(n);
    for (int j = 0; j < n; j++){
      cin >> p[j];
    }
    vector<int> s;
    s.push_back(p[0]);
    s.push_back(p[1]);
    for (int j = 2; j < n; j++){
      if (s[s.size() - 2] < s[s.size() - 1] && s[s.size() - 1] < p[j]){
        s.pop_back();
      } else if (s[s.size() - 2] > s[s.size() - 1] && s[s.size() - 1] > p[j]){
        s.pop_back();
      }
      s.push_back(p[j]);
    }
    int k = s.size();
    cout << k << endl;
    for (int j = 0; j < k; j++){
      cout << s[j];
      if (j < k - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}