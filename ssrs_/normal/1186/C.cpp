#include <bits/stdc++.h>
using namespace std;
int main(){
  string a;
  cin >> a;
  string b;
  cin >> b;
  int N = a.size();
  int M = b.size();
  int B = 0;
  for (int i = 0; i < M; i++){
    if (b[i] == '1'){
      B++;
    }
  }
  vector<int> S(N + 1);
  S[0] = 0;
  for (int i = 0; i < N; i++){
    S[i + 1] = S[i];
    if (a[i] == '1'){
      S[i + 1]++;
    }
  }
  int ans = 0;
  for (int i = 0; i <= N - M; i++){
    if ((S[i + M] - S[i]) % 2 == B % 2){
      ans++;
    }
  }
  cout << ans << endl;
}