#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long long> B, R, P;
  for (int i = 0; i < n; i++){
    int x;
    char c;
    cin >> x >> c;
    if (c == 'B'){
      B.push_back(x);
    }
    if (c == 'R'){
      R.push_back(x);
    }
    if (c == 'P'){
      P.push_back(x);
    }
  }
  if (P.empty()){
    long long ans = 0;
    if (!B.empty()){
      ans += B.back() - B.front();
    }
    if (!R.empty()){
      ans += R.back() - R.front();
    }
    cout << ans << endl;
  } else {
    vector<vector<int>> R2(P.size() + 1);
    int a = 0;
    for (int i : R){
      if (a < P.size()){
        while (P[a] < i){
          a++;
          if (a == P.size()){
            break;
          }
        }
      }
      R2[a].push_back(i);
    }
    vector<vector<int>> B2(P.size() + 1);
    int b = 0;
    for (int i : B){
      if (b < P.size()){
        while (P[b] < i){
          b++;
          if (b == P.size()){
            break;
          }
        }
      }
      B2[b].push_back(i);
    }
    long long ans = 0;
    for (int i = 0; i <= P.size(); i++){
      if (i == 0){
        if (!empty(R2.front())){
          ans += P.front() - R2.front().front();
        }
        if (!empty(B2.front())){
          ans += P.front() - B2.front().front();
        }
      } else if (i == P.size()){
        if (!empty(R2.back())){
          ans += R2.back().back() - P.back();
        }
        if (!empty(B2.back())){
          ans += B2.back().back() - P.back();
        }
      } else {
        long long L1;
        if (R2[i].empty() && B2[i].empty()){
          L1 = P[i] - P[i - 1];
        } else {
          L1 = (P[i] - P[i - 1]) * 2;
        }
        long long L2 = (P[i] - P[i - 1]) * 3;
        vector<int> r = R2[i];
        r.push_back(P[i - 1]);
        r.push_back(P[i]);
        sort(r.begin(), r.end());
        int rmd = 0;
        for (int j = 0; j < r.size() - 1; j++){
          rmd = max(rmd, r[j + 1] - r[j]);
        }
        L2 -= rmd;
        vector<int> b = B2[i];
        b.push_back(P[i - 1]);
        b.push_back(P[i]);
        sort(b.begin(), b.end());
        int bmd = 0;
        for (int j = 0; j < b.size() - 1; j++){
          bmd = max(bmd, b[j + 1] - b[j]);
        }
        L2 -= bmd;
        ans += min(L1, L2);
      }
    }
    cout << ans << endl;
  }
}