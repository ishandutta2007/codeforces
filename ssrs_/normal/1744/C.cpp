#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    vector<int> g;
    for (int j = 0; j < n * 2; j++){
      if (s[j % n] == 'g'){
        g.push_back(j);
      }
    }
    int ans = 0;
    for (int j = 0; j < n; j++){
      if (s[j] == c){
        ans = max(ans, *lower_bound(g.begin(), g.end(), j) - j);
      }
    }
    cout << ans << endl;
  }
}