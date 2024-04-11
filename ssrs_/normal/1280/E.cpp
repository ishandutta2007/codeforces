#include <bits/stdc++.h>
using namespace std;
const int INF = 100000000;
int parse(vector<vector<int>> &c, string &t, int& p){
  int p2 = p;
  if (t[p] == '*'){
    p++;
    return 1;
  } else {
    p++;
    vector<int> A;
    vector<int> pos;
    char T;
    while (true){
      pos.push_back(p);
      A.push_back(parse(c, t, p));
      if (t[p] == ')'){
        break;
      }
      T = t[p];
      p++;
    }
    p++;
    int cnt = A.size();
    if (T == 'P'){
      int ans = 0;
      for (int j = 0; j < cnt; j++){
        ans += A[j];
        c[p2].push_back(pos[j]);
      }
      return ans;
    } else {
      int ans = INF;
      for (int j = 0; j < cnt; j++){
        ans = min(ans, A[j]);
      }
      for (int j = 0; j < cnt; j++){
        if (A[j] == ans){
          c[p2].push_back(pos[j]);
          break;
        }
      }
      return ans;
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int r;
    cin >> r;
    cin.ignore();
    string s;
    getline(cin, s);
    int N = s.size();
    string t;
    for (int j = 0; j < N; j++){
      if (s[j] != ' '){
        t += s[j];
      }
    }
    int N2 = t.size();
    vector<vector<int>> c(N2);
    int p = 0;
    int cnt = parse(c, t, p);
    vector<bool> used(N2, false);
    used[0] = true;
    for (int j = 0; j < N2; j++){
      if (used[j]){
        for (int k : c[j]){
          used[k] = true;
        }
      }
    }
    long long R = (long long) r * cnt;
    cout << "REVOLTING";
    for (int j = 0; j < N2; j++){
      if (t[j] == '*'){
        if (!used[j]){
          cout << ' ' << 0;
        } else {
          cout << ' ' << R;
        }
      }
    }
    cout << "\n";
  }
}