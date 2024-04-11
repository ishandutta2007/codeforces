#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    long long x;
    cin >> n >> k >> x;
    x--;
    string s;
    cin >> s;
    vector<pair<char, int>> C;
    C.push_back(make_pair(s[0], 1));
    for (int j = 1; j < n; j++){
      if (s[j] == s[j - 1]){
        C.back().second++;
      } else {
        C.push_back(make_pair(s[j], 1));
      }
    }
    int m = C.size();
    string t;
    for (int j = m - 1; j >= 0; j--){
      if (C[j].first == 'a'){
        t += string(C[j].second, 'a');
      }
      if (C[j].first == '*'){
        int p = C[j].second * k + 1;
        t += string(x % p, 'b');
        x /= p;
      }
    }
    reverse(t.begin(), t.end());
    cout << t << endl;
  }
}