#include <bits/stdc++.h>
using namespace std;
string rev(string s){
  reverse(s.begin(), s.end());
  return s;
}
vector<int> manacher(string &S){
  int N = S.size();
  vector<int> rad(N, 0);
  int i = 0, j = 0;
  while (i < N){
    while (i >= j && i + j < N && S[i - j] == S[i + j]){
      j++;
    }
    rad[i] = j;
    int k = 1;
    while (i >= k && i + k <= N && k + rad[i - k] < j){
      rad[i + k] = rad[i - k];
      k++;
    }
    i += k;
    j -= k;
  }
  return rad;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    string S1 = s;
    string S2 = rev(s);
    if (S1 == S2){
      cout << s << endl;
    } else {
      int p = 0;
      string T;
      while (S1[p] == S2[p]){
        T += S1[p];
        p++;
      }
      string r1 = "0";
      string r2 = "0";
      for (int j = p; j < s.size() - p; j++){
        r1 += S1[j];
        r2 += S2[j];
        r1 += '0';
        r2 += '0';
      }
      vector<int> v1 = manacher(r1);
      vector<int> v2 = manacher(r2);
      int M = 0;
      int L = v1.size();
      int u = 0;
      for (int i = 1; i < L; i++){
        if (v1[i] == i + 1){
          M = i;
          u = 1;
        }
        if (v2[i] == i + 1){
          M = i;
          u = 2;
        }
      }
      string R;
      if (u == 1){
        for (int j = p; j < p + M; j++){
          R += S1[j];
        }
      } else {
        for (int j = p; j < p + M; j++){
          R += S2[j];
        }
      }
      cout << T << R << rev(T) << endl;
    }
  }
}