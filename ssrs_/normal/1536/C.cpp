#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<pair<int, int>, int> mp;
    int D = 0, K = 0;
    for (int j = 0; j < n; j++){
      if (s[j] == 'D'){
        D++;
      }
      if (s[j] == 'K'){
        K++;
      }
      int g = __gcd(D, K);
      int D2 = D / g;
      int K2 = K / g;
      mp[make_pair(D2, K2)]++;
      cout << mp[make_pair(D2, K2)];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}