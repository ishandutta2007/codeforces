#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string t;
    for (int j = 0; j < k - 1; j++){
      t += "()";
    }
    t += '(';
    for (int j = 0; j < n / 2 - k; j++){
      t += "()";
    }
    t += ")";
    vector<pair<int, int>> op;
    for (int j = 0; j < n; j++){
      if (s[j] != t[j]){
        int p = j;
        while (s[p] != t[j]){
          p++;
        }
        //s[p]
        op.push_back(make_pair(j, p));
        reverse(s.begin() + j, s.begin() + p + 1);
      }
    }
    int m = op.size();
    cout << m << endl;
    for (int j = 0; j < m; j++){
      cout << op[j].first + 1 << ' ' << op[j].second + 1 << endl;
    }
  }
}