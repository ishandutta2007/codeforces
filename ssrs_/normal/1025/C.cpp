#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  s += s;
  int N = s.size();
  int L = 1;
  int M = L;
  for (int i = 1; i < N; i++){
    if (s[i] != s[i - 1]){
      L++;
      M = max(M, L);
    } else {
      L = 1;
    }
  }
  cout << min(M, N / 2) << endl;
}