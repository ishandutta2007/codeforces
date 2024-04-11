#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int N = s.size();
    vector<vector<int>> a(3);
    for (int j = 0; j < 3; j++){
      a[j].push_back(-1);
    }
    for (int j = 0; j < N; j++){
      if (s[j] != '?'){
        a[2].push_back(j);
        int d = s[j] - '0';
        int p = (d + j) % 2;
        a[p].push_back(j);
      }
    }
    for (int j = 0; j < 3; j++){
      a[j].push_back(N);
    }
    vector<long long> S(3, 0);
    for (int j = 0; j < 3; j++){
      int cnt = a[j].size();
      for (int k = 0; k < cnt - 1; k++){
        long long d = a[j][k + 1] - a[j][k];
        S[j] += d * (d - 1) / 2;
      }
    }
    cout << S[0] + S[1] - S[2] << endl;
  }
}