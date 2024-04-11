#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> p;
    for (int j = 0; j < n; j++){
      if ((s[j] - '0') % 2 == 1){
        p.push_back(j);
      }
    };
    if (p.size() < 2){
      cout << -1 << endl;
    } else {
      cout << s.substr(p[0], p[1] - p[0] + 1) << endl;
    }
  }
}