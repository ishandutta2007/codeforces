#include <bits/stdc++.h>
using namespace std;
bool is_substring(string S, string T){
  int N = S.size();
  int M = T.size();
  for (int i = 0; i <= N - M; i++){
    if (S.substr(i, M) == T){
      return true;
    }
  }
  return false;
}
int main(){
  int n;
  cin >> n;
  vector<string> S(n);
  for (int i = 0; i < n; i++){
    cin >> S[i];
  }
  vector<pair<int, string>> P(n);
  for (int i = 0; i < n; i++){
    P[i] = make_pair(S[i].size(), S[i]);
  }
  sort(P.begin(), P.end());
  bool ok = true;
  for (int i = 0; i < n - 1; i++){
    if (!is_substring(P[i + 1].second, P[i].second)){
      ok = false;
    }
  }
  if (!ok){
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++){
      cout << P[i].second << endl;
    }
  }
}