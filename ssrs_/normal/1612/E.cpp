#include <bits/stdc++.h>
using namespace std;
const int MAX = 200000;
int main(){
  int n;
  cin >> n;
  vector<int> m(n), k(n);
  for (int i = 0; i < n; i++){
    cin >> m[i] >> k[i];
    m[i]--;
  }
  pair<long long, long long> mx = make_pair(0, 1);
  vector<int> c;
  for (int i = 1; i <= 20; i++){
    vector<long long> C(MAX, 0);
    for (int j = 0; j < n; j++){
      if (k[j] >= i){
        C[m[j]] += i;
      } else {
        C[m[j]] += k[j];
      }
    }
    vector<pair<long long, int>> P(MAX);
    for (int j = 0; j < MAX; j++){
      P[j] = make_pair(C[j], j);
    }
    sort(P.begin(), P.end(), greater<pair<long long, int>>());
    long long S = 0;
    for (int j = 0; j < i; j++){
      S += P[j].first;
    }
    if (mx.first * i < S * mx.second){
      mx = make_pair(S, i);
      c.clear();
      for (int j = 0; j < i; j++){
        c.push_back(P[j].second);
      }
    }
  }
  int t = c.size();
  cout << t << endl;
  for (int i = 0; i < t; i++){
    cout << c[i] + 1;
    if (i < t - 1){
      cout << ' ';
    }
  }
  cout << endl;
}