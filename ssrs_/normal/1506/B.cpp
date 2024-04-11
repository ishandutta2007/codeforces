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
    vector<int> p;
    for (int j = 0; j < n; j++){
      if (s[j] == '*'){
        p.push_back(j);
      }
    }
    int m = p.size();
    vector<bool> used(m, false);
    used[0] = true;
    int ans = 0;
    for (int j = 0; j < m; j++){
      if (used[j]){
        int next = upper_bound(p.begin(), p.end(), p[j] + k) - p.begin() - 1;
        used[next] = true;
        ans++;
      }
    }
    cout << ans << endl;
  }
}